#pragma once

#include "MapSite.h"
#include "Room.h"

class CDoor : public CMapSite
{
public:
	CDoor();
	CDoor(CRoom* p_cRoom1, CRoom* p_cRoom2);
	~CDoor();

public:
	virtual void Enter();
	CRoom* OtherSideFrom(CRoom* p_cRoom);

private:
	CRoom* _room1;
	CRoom* _room2;
	bool _isOpen;
};