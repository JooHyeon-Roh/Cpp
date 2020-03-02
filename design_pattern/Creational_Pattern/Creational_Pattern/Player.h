#pragma once

#include "Room.h"

class CPlayer
{
public:
	CPlayer(CRoom* p_cPlayerRoom);
	~CPlayer();

public:
	void MovePlayer(const E_DIRECTION direction);

protected:
	int _life;
	CRoom* mp_cPlayerRoom;
};

