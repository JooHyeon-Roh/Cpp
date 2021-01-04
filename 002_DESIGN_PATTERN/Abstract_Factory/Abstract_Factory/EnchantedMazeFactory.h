#pragma once

/*
EnchantedMazeFactory�� MazeFactory ���� ���� Ŭ���� ����, ��� �Լ��� ������ �Ͽ� Room, Wall�� ����ϴ� �ٸ� ���� Ŭ������ �ν��Ͻ���
��ȯ�ϰ� ����ϴ�.
*/

#include "MazeFactory.h"
#include "EnchantedRoom.h"
#include "DoorNeedingSpell.h"

class CEnchantedMazeFactory : public CMazeFactory
{
	/*
	MazeFactory �� ��� �޾� �θ� Ŭ������ ���ǵ� ������ ������ ����
	��ü���� ��Ҹ� �����Ͽ� ��ȯ�ϵ��� �����ϴ� ����Ŭ����
	*/
public:
	CEnchantedMazeFactory();
	~CEnchantedMazeFactory();

public:
	virtual CRoom* MakeRoom(int n) const; // �̶��� Room �� ��ӹ��� EnchantedRoom�� �ν��Ͻ��� �����Ͽ� ��ȯ��
	virtual CDoor* MakeDoor(CRoom* r1, CRoom* r2) const; // �̶��� Door �� ��ӹ��� DoorNeedingSpell�� �ν��Ͻ��� �����Ͽ� ��ȯ��

protected:
	CSpell* CastSpell() const;
};
