#include "EnchanteMazeFactory.h"

CEnchanteMazeFactory::CEnchanteMazeFactory()
{
}

CEnchanteMazeFactory::~CEnchanteMazeFactory()
{
}

CRoom* CEnchanteMazeFactory::MakeRoom(int n) const
{
	return new CEnchantedRoom(n, CastSpell());
}

CDoor* CEnchanteMazeFactory::MakeDoor(CRoom* r1, CRoom* r2) const
{
	return new CDoorNeeingSpell(r1, r2);
}

CSpell* CEnchanteMazeFactory::CastSpell() const
{
	return nullptr;
}
