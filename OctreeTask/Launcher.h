#pragma once
#include "Octree.h"
#include "PlayableObj.h"
#include "DeployObj.h"
#include <iomanip>
class Launcher
{
public:
    PlayableObj player;
    Octree* tree = new Octree();
    std::map<int, Object*> nonPlayableList;
    std::map<int, Object*> allObjectList;
    std::vector<Object*>   printList;
public:
    bool init();     // 초기화	
    bool frame(float deltaTime, float gameTime);    // 계산
    bool render();   // 출력
    bool release();  // 소멸
    bool run();      // 실행
};

