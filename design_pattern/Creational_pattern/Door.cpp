#include "Door.h"

CDoor::CDoor(CRoom* p_cRoom1 = 0, CRoom* p_cRoom2 = 0)
	: _room1(nullptr), _room2(nullptr), _isOpen(0x00)
{
}

CDoor::~CDoor()
{
}

void CDoor::Enter()
{
}

CRoom* CDoor::OtherSideFrom(CRoom* p_cRoom)
{
	return nullptr;
}

