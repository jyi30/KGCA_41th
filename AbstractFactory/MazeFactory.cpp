#include "MazeFactory.h"
//AbstractFactory�� ��ü�� �����Ҷ����� ������ ��ǰ���� ���ϴ� ��ü�� �����ϱ� ����
// ������ ������ �˻��� �ʿ䰡 ����.
// ���� ���ο� ��ǰ���� �����Ϸ��� �� ��� ���� �ҽ��ڵ�ʹ� ���������� ���ο�
// ��ǰ���� �߰��ϴ� ���� �����ϴ�.

class MazeFactory
{
public:
	MazeFactory()
	{

	}
	virtual Maze* MakaMaze() const
	{
		return new Maze;
	}
	virtual Wall* MakeWall() const
	{
		return new Wall;
	}
	virtual Room* MakeRoom(int n) const
	{
		return new Room(n);
	}
	virtual Door* MakeDoor(Room* r1, Room* r2) const
	{
		return new Door(r1, r2);
	}
};

class Spell
{
public:
	Spell()
	{

	}
};

class EnchantedRoom : public Room
{
public:
	EnchantedRoom(int n, Spell*) : Room(n)
	{
	}
};

class DoorNeedingSpell : public Door
{
public:
	DoorNeedingSpell(Room* r1, Room* r2) : Door(r1, r2)
	{

	}
};

class EnchantedMazeFactory : public MazeFactory
{
protected:
	Spell* CastSpell() const
	{
		return new Spell;
	}
public:
	EnchantedMazeFactory()
	{

	}
	virtual Room* MakeRoom(int n) const
	{
		return new EnchantedRoom(n, CastSpell());
	}
	virtual Door* MakeDoor(Room* r1, Room* r2) const
	{
		return new DoorNeedingSpell(r1, r2);
	}
};

class MazeGame
{
public:
	Maze* CreateMaze()
	{
		Maze* aMaze = new Maze;
		Room* r1 = new Room(1);
		Room* r2 = new Room(2);
		Door* theDoor = new Door(r1, r2);
		aMaze->AddRoom(r1);
		aMaze->AddRoom(r2);
		
		r1->SetSide(North, new Wall);
		r1->SetSide(East, theDoor);
		r1->SetSide(South, new Wall);
		r1->SetSide(West, new Wall);

		r2->SetSide(North, new Wall);
		r2->SetSide(East, new Wall);
		r2->SetSide(South, new Wall);
		r2->SetSide(West, theDoor);
		return aMaze;
	}

	//AbstractFactory ���
	Maze* CreateMaze(MazeFactory* factory)
	{
		Maze* aMaze = factory->MakaMaze();
		Room* r1 = factory->MakeRoom(1);
		Room* r2 = factory->MakeRoom(2);
		Door* theDoor = factory->MakeDoor(r1, r2);
		aMaze->AddRoom(r1);
		aMaze->AddRoom(r2);

		r1->SetSide(North, factory->MakeWall());
		r1->SetSide(East, theDoor);
		r1->SetSide(South, factory->MakeWall());
		r1->SetSide(West, factory->MakeWall());

		r2->SetSide(North, factory->MakeWall());
		r2->SetSide(East, factory->MakeWall());
		r2->SetSide(South, factory->MakeWall());
		r2->SetSide(West, theDoor);
		return aMaze;
	}
};

int main()
{
	MazeGame mg; 
	Maze* pMaze = mg.CreateMaze();
	//AbstractFactory
	MazeGame mg1;
	MazeFactory* factory1 = new MazeFactory;
	Maze* pMaze1 = mg1.CreateMaze(factory1);

	MazeGame mg2;
	MazeFactory* factory2 = new EnchantedMazeFactory;
	Maze* pMaze2 = mg2.CreateMaze(factory2);
}