#pragma once

/*
EnchantedMazeFactory를 MazeFactory 에서 서브 클래싱 한후, 멤버 함수를 재정의 하여 Room, Wall을 상속하는 다른 서브 클래스의 인스턴스를
반환하게 만듭니다.
*/

#include "MazeFactory.h"
#include "EnchantedRoom.h"
#include "DoorNeedingSpell.h"

class CEnchantedMazeFactory : public CMazeFactory
{
	/*
	MazeFactory 를 상속 받아 부모 클래스에 정의된 연산을 재정의 한후
	구체적인 요소를 생성하여 반환하도록 구현하는 서브클래스
	*/
public:
	CEnchantedMazeFactory();
	~CEnchantedMazeFactory();

public:
	virtual CRoom* MakeRoom(int n) const; // 이때는 Room 을 상속받은 EnchantedRoom의 인스턴스를 생성하여 반환함
	virtual CDoor* MakeDoor(CRoom* r1, CRoom* r2) const; // 이때는 Door 을 상속받은 DoorNeedingSpell의 인스턴스를 생성하여 반환함

protected:
	CSpell* CastSpell() const;
};
