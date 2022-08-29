#include "Launcher.h"

bool Launcher::Run()
{
    Init();
    float gameTimer = 0.0f;
    float delay = 10;
    while (gameTimer < 10.0f)
    {
        Frame(delay / 1000.0f, gameTimer); //천분의 n초(ms)
        Render();
        Sleep(delay);
        system("cls");
        gameTimer = gameTimer + (delay / 1000.0f);
    }
    Release();
    return true;
}

bool Launcher::Init()
{
    for (int iObj = 0; iObj < 10; iObj++)
    {
        std::string name = std::to_string(iObj) + "번 staticObj";

        Object* pObj = new Object(name);

        m_AllObjectList.insert(std::make_pair(iObj, pObj));
        tree->addStaticObject(pObj);
    }
    for (int iObj = 0; iObj < 10; iObj++)
    {
        std::string name = std::to_string(iObj) + "번 dynamicObj";

        Object* pObj = new DeployObj();

        pObj->name = name;
        m_npcList.insert(std::make_pair(iObj, pObj));
        m_AllObjectList.insert(std::make_pair(10 + iObj, pObj));
        tree->addDynamicObject(pObj);
    }
    return true;
}

bool Launcher::Frame(float fDeltaTime, float fGameTime)
{
    tree->DynamicObjectReset();
    for (auto obj : m_npcList)
    {
        Object* pObject = obj.second;
        pObject->frame(fDeltaTime, fGameTime);
        tree->addDynamicObject(pObject);
    }
    player.frame(fDeltaTime, fGameTime);
    m_DrawList = tree->Collisionlist(&player);

    return false;
}

bool Launcher::Render()
{
    std::cout << "Player:"
        << player.box.min.x << "," << player.box.min.y << ","
        << player.box.min.z << std::endl;
    if (!m_DrawList.empty())
    {
        for (int iObj = 0; iObj < m_DrawList.size(); iObj++)
        {
            std::cout << m_DrawList[iObj]->name << " : "
                << m_DrawList[iObj]->box.min.x << ","
                << m_DrawList[iObj]->box.min.y << ","
                << m_DrawList[iObj]->box.min.z << std::endl;
        }
    }
    return false;
}

bool Launcher::Release()
{
    for (auto object : m_AllObjectList)
    {
        delete object.second;
    }
    m_AllObjectList.clear();
    m_npcList.clear();
    return true;
}