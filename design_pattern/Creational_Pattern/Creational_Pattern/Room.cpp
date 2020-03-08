#include "Room.h"

CRoom::CRoom(int roomNo)
	: _roomNumber(roomNo)
{
	memset(_sides, 0x00, sizeof(_sides));
}

CRoom::~CRoom()
{
}

CMapSite* CRoom::GetSite(E_DIRECTION e_direction) const
{
	return nullptr;
}

void CRoom::SetSide(E_DIRECTION e_direction, CMapSite* p_cMapSite)
{
	return;
}

void CRoom::Enter()
{
	return;
}

