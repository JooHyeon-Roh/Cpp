#pragma once

#include "MapSite.h"
#include "Maze.h"
#include "Door.h"
#include "Room.h"
#include "Wall.h"

class CMazeGame
{
public:
	CMazeGame();
	~CMazeGame();

public:
	CMaze* CreateMaze();

};