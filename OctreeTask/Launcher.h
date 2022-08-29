#pragma once
#include "Octree.h"
#include "PlayableObj.h"
#include "DeployObj.h"
class Launcher
{
public:
    PlayableObj player;
    Octree* tree = new Octree();
    std::map<int, Object*> m_npcList;
    std::map<int, Object*> m_AllObjectList;
    std::vector<Object*>   m_DrawList;
public:
    bool    Init();     // �ʱ�ȭ	
    bool    Frame(float fDeltaTime, float fGameTime);    // �ǽð� ���
    bool    Render();   // ȭ�鿡 ��ο�
    bool    Release();  // �Ҹ�����
    bool	Run();      // ��������
};

