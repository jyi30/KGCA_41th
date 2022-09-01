#include "Launcher.h"

bool Launcher::run()
{
    float delay = 0.0f;
    float playtime = 0.0f;

    std::cout << "======================================\n";
    std::cout << "    Octree ������ Object �浹 �׽�Ʈ           \n";
    std::cout << "======================================\n";
    std::cout << "���ΰ�ħ �� �Է�(���� : ms(1/1000��)) : ";
    std::cin >> delay;
    std::cout << "�۵��ð� �Է�(���� : ��) : ";
    std::cin >> playtime;


    

    system("cls");

    init();
    clock_t start = clock();

    float time = 0.0f;

    while (time < (playtime * 1000))
    {
        std::cout << "���� �ð� : " << (time / 1000) << "��" << std::endl;
        frame(delay / 1000.0f); //õ���� n��(ms)
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
        std::string name = std::to_string(i) + "�� ����";

        Object* obj = new Object(name);

        allObjectList.insert(std::make_pair(i, obj));
        tree->addStaticObject(obj);
    }
    for (int i = 0; i < 10; i++)
    {
        std::string name = std::to_string(i) + "�� ����";

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