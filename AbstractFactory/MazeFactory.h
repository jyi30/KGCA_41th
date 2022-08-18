#pragma once
#include <iostream>
#include <vector>

enum Direction {North, East, South, West};
class MapSite
{
public:
	virtual void Enter() = 0;
};

class Room : public MapSite
{
private:
	MapSite* _sides[4];
	int _roomNumber;
public:
	Room() 
	{
	
	};
	Room(int RoomNo)
	{
		_roomNumber = RoomNo;
	};

	MapSite* GetSide(Direction) const
	{

	}
	void SetSide(Direction dir, MapSite* pMapSize)
	{
		_sides[dir] = pMapSize;
	};
	virtual void Enter()
	{

	}
};

class Wall : public MapSite
{
public:
	Wall()
	{

	}
	virtual void Enter()
	{

	}
};
class Door : public MapSite
{
private:
	Room* _room1;
	Room* _room2;
	bool _isOpen;
public:
	Door()
	{

	}
	Door(Room* a, Room* b)
	{
		_room1 = a; _room2 = b;
	}
	virtual void Enter()
	{

	}
	Room* OtherSideFrom(Room*)
	{

	}
};

class Maze
{
public:
	std::vector<Room*> m_RoomList;
public:

	Maze()
	{

	}
	void AddRoom(Room* room)
	{
		m_RoomList.push_back(room);
	}
	Room* RoomNo(int no)const
	{
		return m_RoomList[no];
	}
};

