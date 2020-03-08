#pragma once

#include "Door.h"

class CDoorNeedingSpell : public CDoor
{
public:
	CDoorNeedingSpell();
	CDoorNeedingSpell(CRoom* r1, CRoom* r2);
	~CDoorNeedingSpell();
};

