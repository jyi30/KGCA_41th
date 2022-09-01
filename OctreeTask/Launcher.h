#pragma once
#include "Octree.h"
#include "PlayableObj.h"
#include "DeployObj.h"
#include <iomanip>
#include <time.h>
class Launcher
{
public:
    PlayableObj player;
    Octree* tree = new Octree();
    std::map<int, Object*> nonPlayableList;
    std::map<int, Object*> allObjectList;
    std::vector<Object*>   printList;
public:
    bool init(); // 초기화	
    bool frame(float deltaTime); // 동작
    bool render(); // 출력
    bool release(); // 해제
    bool run(); // 시작
};

