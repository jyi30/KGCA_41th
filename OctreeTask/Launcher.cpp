#include "Launcher.h"

bool Launcher::run()
{
    float delay = 0.0f;

    std::cout << "======================================\n";
    std::cout << "    Octree ������ Object �浹 �׽�Ʈ           \n";
    std::cout << "======================================\n";
    std::cout << "���ΰ�ħ �� �Է�(���� : ms(1/1000��)) : ";
    std::cin >> delay;

    system("cls");

    init();
    float gameTimer = 0.0f;
    while (gameTimer < 5.0f)
    {
        frame(delay / 1000.0f, gameTimer); //õ���� n��(ms)
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
        std::string name = std::to_string(iObj) + "�� ����";

        Object* pObj = new Object(name);

        allObjectList.insert(std::make_pair(iObj, pObj));
        tree->addStaticObject(pObj);
    }
    for (int iObj = 0; iObj < 10; iObj++)
    {
        std::string name = std::to_string(iObj) + "�� ����";

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
    std::cout << std::setw(20) << "������Ʈ��" << std::setw(20) << "���� x��" << std::setw(20) << "���� y��" << std::setw(20) << "���� z��" << std::endl;
    std::cout << "=========================================================================" << std::endl;


    std::cout << std::setw(20) << "�÷��̾�"
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