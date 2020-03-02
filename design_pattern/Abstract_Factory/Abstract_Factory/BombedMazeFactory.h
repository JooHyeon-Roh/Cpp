#pragma once

#include "MazeFactory.h"
#include "RoomWithABomb.h"
#include "BombedWall.h"

class CBombedMazeFactory : public CMazeFactory
{
public:
	CBombedMazeFactory();
	~CBombedMazeFactory();

public:
	CWall* MakeWall() const;
	CRoom* MakeDoor(int n) const;

};

