#include "EnchantedMazeFactory.h"

CEnchantedMazeFactory::CEnchantedMazeFactory()
{
}

CEnchantedMazeFactory::~CEnchantedMazeFactory()
{
}

CRoom* CEnchantedMazeFactory::MakeRoom(int n) const
{
	return new CEnchantedRoom(n, CastSpell());
}

CDoor* CEnchantedMazeFactory::MakeDoor(CRoom* r1, CRoom* r2) const
{
	return new CDoorNeedingSpell(r1, r2);
}

CSpell* CEnchantedMazeFactory::CastSpell() const
{
	return nullptr;
}
