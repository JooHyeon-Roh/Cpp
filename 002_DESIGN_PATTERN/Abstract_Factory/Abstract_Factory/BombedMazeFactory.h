#pragma once

/*
���� ��ź�� ������ ���� ����� �ʹٸ�, �濡 ��ź�� �ִ��� �����ϰ� �����ϴ� Ŭ������ Room Ŭ������ ���� Ŭ������ ����� �˴ϴ�.
���� ���� ��ź�� ������ ���� �ջ��� ������ ���� ����� �ٲ�� �Ϸ���, Wall�� ���ο� Ŭ������ ����� �˴ϴ�.
�̸� RoomWithABomb Ŭ������ BombWallŬ������ ���� �մϴ�.
*/

#include "MazeFactory.h"
#include "RoomWithABomb.h"
#include "BombedWall.h"

class CBombedMazeFactory : public CMazeFactory
{
public:
	CBombedMazeFactory();
	~CBombedMazeFactory();

public:
	virtual CWall* MakeWall() const;
	virtual CRoom* MakeDoor(int n) const;

};

