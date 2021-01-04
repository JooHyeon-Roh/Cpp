#include "MazeGame.h"

CMazeGame::CMazeGame()
{
}

CMazeGame::~CMazeGame()
{
}

CMaze* CMazeGame::CreateMaze()
{
	CMaze* aMaze = new CMaze;

	CRoom* r1 = new CRoom(1);
	CRoom* r2 = new CRoom(2);

	CDoor* theDoor = new CDoor(r1, r2);

	aMaze->AddRoom(r1);
	aMaze->AddRoom(r2);

	r1->SetSide(E_DIRECTION::NORTH, new CWall);
	r1->SetSide(E_DIRECTION::EAST, theDoor);
	r1->SetSide(E_DIRECTION::SOUTH, new CWall);
	r1->SetSide(E_DIRECTION::WEST, new CWall);

	r2->SetSide(E_DIRECTION::NORTH, new CWall);
	r2->SetSide(E_DIRECTION::EAST, new CWall);
	r2->SetSide(E_DIRECTION::SOUTH, new CWall);
	r2->SetSide(E_DIRECTION::WEST, theDoor);

	return aMaze;
}
