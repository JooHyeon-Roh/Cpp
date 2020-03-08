#pragma once

#include "MapSite.h"
#include "Door.h"
#include "Room.h"
#include "Wall.h"

class CMaze
{
public:
	CMaze();
	~CMaze();

public:
	void AddRoom(CRoom* p_cRoom);
	CRoom* RoomNo(int number) const;

};

