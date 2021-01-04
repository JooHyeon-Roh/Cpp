#pragma once

#include "MapSite.h"
#include "Room.h"

class CMaze
{
public:
	CMaze();
	~CMaze();

public:
	void AddRoom(CRoom* p_cRoom);
	CRoom* RoomNo(int number) const;

};