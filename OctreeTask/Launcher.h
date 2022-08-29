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
    bool init();     // �ʱ�ȭ	
    bool frame(float deltaTime, float gameTime);    // ���
    bool render();   // ���
    bool release();  // �Ҹ�
    bool run();      // ����
};

