#include "BombedMazeFactory.h"

CBombedMazeFactory::CBombedMazeFactory()
{
}

CBombedMazeFactory::~CBombedMazeFactory()
{
}

CWall* CBombedMazeFactory::MakeWall() const
{
	return new CBombedWall;
}

CRoom* CBombedMazeFactory::MakeDoor(int n) const
{
	return new CRoomWithABomb(n);
}
