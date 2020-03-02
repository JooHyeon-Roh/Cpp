#pragma once

#include "cstdio"
#include "cstdlib"
#include "Maze.h"

class CMazeGame
{
public:
	CMazeGame();
	~CMazeGame();

public:
	CMaze* CreateMaze();
};