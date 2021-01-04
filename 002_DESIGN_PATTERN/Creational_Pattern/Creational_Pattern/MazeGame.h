#pragma once

#include "Maze.h"

class CMazeGame
{
public:
	CMazeGame();
	~CMazeGame();

public:
	CMaze* CreateMaze();
};