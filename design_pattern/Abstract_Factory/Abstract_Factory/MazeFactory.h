#pragma once

#include "Maze.h"
#include "Room.h"
#include "Wall.h"
#include "Door.h"
#include "Spell.h"

class CMazeFactory
{
public:
	CMazeFactory();
	~CMazeFactory();

public:
	virtual CMaze* MakeMaze() const;
	virtual CWall* MakeWall() const;
	virtual CRoom* MakeRoom(int n) const;
	virtual CDoor* MakeDoor(CRoom* r1, CRoom* r2) const;
};

