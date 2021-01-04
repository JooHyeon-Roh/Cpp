#pragma once

#include "Room.h"
#include "Spell.h"

class CEnchantedRoom : public CRoom
{
public:
	CEnchantedRoom();
	CEnchantedRoom(int n, CSpell* p_cSpell);
	~CEnchantedRoom();
};

