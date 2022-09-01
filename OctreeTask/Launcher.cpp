#include "Launcher.h"

bool Launcher::run()
{
    float delay = 0.0f;
    float playtime = 0.0f;

    std::cout << "======================================\n";
    std::cout << "    Octree 구현과 Object 충돌 테스트           \n";
    std::cout << "======================================\n";
    std::cout << "새로고침 빈도 입력(단위 : ms(1/1000초)) : ";
    std::cin >> delay;
    std::cout << "작동시간 입력(단위 : 초) : ";
    std::cin >> playtime;


    

    system("cls");

    init();
    clock_t start = clock();

    float time = 0.0f;

    while (time < (playtime * 1000))
    {
        std::cout << "가동 시간 : " << (time / 1000) << "초" << std::endl;
        frame(delay / 1000.0f); //천분의 n초(ms)
        render();
        Sleep(delay);
        system("cls");
        clock_t end = clock();
        time = float(end - start);
    }
    release();

    return true;
}

bool Launcher::init()
{
    for (int i = 0; i < 10; i++)
    {
        std::string name = std::to_string(i) + "번 정적";

        Object* obj = new Object(name);

        allObjectList.insert(std::make_pair(i, obj));
        tree->addStaticObject(obj);
    }
    for (int i = 0; i < 10; i++)
    {
        std::string name = std::to_string(i) + "번 동적";

        Object* obj = new DeployObj();
        obj->name = name;

        nonPlayableList.insert(std::make_pair(i, obj));
        allObjectList.insert(std::make_pair(10 + i, obj));
        tree->addDynamicObject(obj);
    }

    return true;
}

bool Launcher::frame(float deltaTime)
{
    tree->dynamicObjectReset();
    for (auto obj : nonPlayableList)
    {
        Object* object = obj.second;
        object->frame(deltaTime);
        tree->addDynamicObject(object);
    }
    player.frame(deltaTime);
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
                << std::setw(20) << printList[iObj]->box.min.x << std::setw(20) << printList[iObj]->box.min.y << std::setw(20) << printList[iObj]->box.min.z << std::endl << std::endl;
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