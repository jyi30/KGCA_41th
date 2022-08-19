#include <iostream>
#include <vector>

class TGamePlayer
{
public:
	virtual void Render() = 0;
};

class TApiGamePlayer : public TGamePlayer
{
public:
	virtual void Render()
	{
		std::cout << "TApiGamePlayer" << std::endl;
	}
};

class TDxGamePlayer : public TGamePlayer
{
public:
	virtual void Render()
	{
		std::cout << "TDxGamePlayer" << std::endl;
	}
};

class TGameMap
{
public:
	virtual void Render() = 0;
};

class TApiGameMap : public TGameMap
{
public:
	virtual void Render()
	{
		std::cout << "TApiGameMap" << std::endl;
	}
};

class TDxGameMap : public TGameMap
{
public:
	virtual void Render()
	{
		std::cout << "TDxGameMap" << std::endl;
	}
};

class TGraphics
{
public:
	virtual TGamePlayer* CreateGamePlayer() = 0;
	virtual TGameMap* CreateGameMap() = 0;
};

class TApiGraphics : public TGraphics
{
	TApiGamePlayer a;
	TApiGameMap b;
public:
	TGamePlayer* CreateGamePlayer()
	{
		return new TApiGamePlayer;
	}
	TGameMap* CreateGameMap()
	{
		return new TApiGameMap;
	}
};

class TDxGraphics : public TGraphics
{
	TDxGamePlayer a;
	TDxGameMap b;
public:
	TGamePlayer* CreateGamePlayer()
	{
		return new TDxGamePlayer;
	}
	TGameMap* CreateGameMap()
	{
		return new TDxGameMap;
	}
};

int main()
{
	TGraphics* graphic = new TDxGraphics;
	TGamePlayer* gp = graphic->CreateGamePlayer();
}