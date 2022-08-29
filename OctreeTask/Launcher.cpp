#include "Launcher.h"

bool Launcher::run()
{
    float delay = 0.0f;

    std::cout << "======================================\n";
    std::cout << "    Octree 구현과 Object 충돌 테스트           \n";
    std::cout << "======================================\n";
    std::cout << "새로고침 빈도 입력(단위 : ms(1/1000초)) : ";
    std::cin >> delay;

    system("cls");

    init();
    float gameTimer = 0.0f;
    while (gameTimer < 5.0f)
    {
        frame(delay / 1000.0f, gameTimer); //천분의 n초(ms)
        render();
        Sleep(delay);
        system("cls");
        gameTimer = gameTimer + (delay / 1000.0f);
    }
    release();
    return true;
}

bool Launcher::init()
{
    for (int iObj = 0; iObj < 10; iObj++)
    {
        std::string name = std::to_string(iObj) + "번 정적";

        Object* pObj = new Object(name);

        allObjectList.insert(std::make_pair(iObj, pObj));
        tree->addStaticObject(pObj);
    }
    for (int iObj = 0; iObj < 10; iObj++)
    {
        std::string name = std::to_string(iObj) + "번 동적";

        Object* pObj = new DeployObj();

        pObj->name = name;
        nonPlayableList.insert(std::make_pair(iObj, pObj));
        allObjectList.insert(std::make_pair(10 + iObj, pObj));
        tree->addDynamicObject(pObj);
    }
    return true;
}

bool Launcher::frame(float fDeltaTime, float fGameTime)
{
    tree->dynamicObjectReset();
    for (auto obj : nonPlayableList)
    {
        Object* pObject = obj.second;
        pObject->frame(fDeltaTime, fGameTime);
        tree->addDynamicObject(pObject);
    }
    player.frame(fDeltaTime, fGameTime);
    printList = tree->collisionList(&player);

    return false;
}

bool Launcher::render()
{
    std::cout.setf(std::ios::left);
    std::cout << std::setw(20) << "오브젝트명" << std::setw(20) << "현재 x축" << std::setw(20) << "현재 y축" << std::setw(20) << "현재 z축" << std::endl;
    std::cout << "=========================================================================" << std::endl;


    std::cout << std::setw(20) << "플레이어"
        << std::setw(20) << player.box.min.x << std::setw(20) << player.box.min.y << std::setw(20) << player.box.min.z << std::endl;
    std::cout << "=========================================================================" << std::endl;
    
    if (!printList.empty())
    {
        for (int iObj = 0; iObj < printList.size(); iObj++)
        {
            std::cout << std::setw(20) << printList[iObj]->name 
                << std::setw(20) << printList[iObj]->box.min.x << std::setw(20) << printList[iObj]->box.min.y << std::setw(20) << printList[iObj]->box.min.z << std::endl;
        }
    }
    return false;
}

bool Launcher::release()
{
    for (auto object : allObjectList)
    {
        delete object.second;
    }
    allObjectList.clear();
    nonPlayableList.clear();
    return true;
}