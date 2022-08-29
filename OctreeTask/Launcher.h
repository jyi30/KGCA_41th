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
    bool    Init();     // 초기화	
    bool    Frame(float fDeltaTime, float fGameTime);    // 실시간 계산
    bool    Render();   // 화면에 드로우
    bool    Release();  // 소멸하자
    bool	Run();      // 실행하자
};

