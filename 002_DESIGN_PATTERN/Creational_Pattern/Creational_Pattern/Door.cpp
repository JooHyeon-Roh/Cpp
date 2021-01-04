#include "Door.h"

CDoor::CDoor(CRoom* p_cRoom1 = nullptr, CRoom* p_cRoom2 = nullptr)
	: _room1(p_cRoom1), _room2(p_cRoom2), _isOpen(true)
{
}

CDoor::~CDoor()
{
}

void CDoor::Enter()
{
	return;
}

CRoom* CDoor::OtherSideFrom(CRoom* p_cRoom)
{
	return nullptr;
}