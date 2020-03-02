#pragma once

#include "Door.h"

class CDoorNeeingSpell : public CDoor
{
public:
	CDoorNeeingSpell();
	CDoorNeeingSpell(CRoom* r1, CRoom* r2);
	~CDoorNeeingSpell();
};

