#pragma once

#include "MapSite.h"
#include "MazeFactory.h"

class CMazeGame
{
public:
	CMazeGame();
	~CMazeGame();

public:
	CMaze* CreateMaze(CMazeFactory& factory);

};