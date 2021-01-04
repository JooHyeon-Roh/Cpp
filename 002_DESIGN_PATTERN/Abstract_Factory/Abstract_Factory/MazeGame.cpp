#include "MazeGame.h"

CMazeGame::CMazeGame()
{
}

CMazeGame::~CMazeGame()
{
}

CMaze* CMazeGame::CreateMaze(CMazeFactory& factory)
{
	CMaze* aMaze = factory.MakeMaze();
	CRoom* r1 = factory.MakeRoom(1);
	CRoom* r2 = factory.MakeRoom(2);
	CDoor* aDoor = factory.MakeDoor(r1, r2);

	aMaze->AddRoom(r1);
	aMaze->AddRoom(r2);

	r1->SetSide(E_DIRECTION::North, factory.MakeWall());
	r1->SetSide(E_DIRECTION::East, aDoor);
	r1->SetSide(E_DIRECTION::South, factory.MakeWall());
	r1->SetSide(E_DIRECTION::West, factory.MakeWall());

	r2->SetSide(E_DIRECTION::North, factory.MakeWall());
	r2->SetSide(E_DIRECTION::East, factory.MakeWall());
	r2->SetSide(E_DIRECTION::South, factory.MakeWall());
	r2->SetSide(E_DIRECTION::West, aDoor);

	return aMaze;
}
