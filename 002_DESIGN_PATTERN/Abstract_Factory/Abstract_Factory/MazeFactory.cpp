#include "MazeFactory.h"

CMazeFactory::CMazeFactory()
{
}

CMazeFactory::~CMazeFactory()
{
}

CMaze* CMazeFactory::MakeMaze() const
{
	return new CMaze;
}

CWall* CMazeFactory::MakeWall() const
{
	return new CWall;
}

CRoom* CMazeFactory::MakeRoom(int n) const
{
	return new CRoom(n);
}

CDoor* CMazeFactory::MakeDoor(CRoom* r1, CRoom* r2) const
{
	return new CDoor(r1, r2);
}