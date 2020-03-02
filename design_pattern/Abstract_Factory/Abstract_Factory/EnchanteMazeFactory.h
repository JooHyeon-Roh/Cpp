#pragma once

#include "MazeFactory.h"
#include "EnchantedRoom.h"
#include "DoorNeeingSpell.h"

class CEnchanteMazeFactory : public CMazeFactory
{
public:
	CEnchanteMazeFactory();
	~CEnchanteMazeFactory();

public:
	virtual CRoom* MakeRoom(int n) const;
	virtual CDoor* MakeDoor(CRoom* r1, CRoom* r2) const;

protected:
	CSpell* CastSpell() const;
};

