#pragma once

/*
만약 폭탄이 장착된 방을 만들고 싶다면, 방에 폭탄이 있는지 추적하고 관리하는 클래스를 Room 클래스의 서브 클래스로 만들면 됩니다.
또한 방의 폭탄이 터진후 벽에 손상이 갔을때 벽의 모습이 바뀌도록 하려면, Wall의 새로운 클래스를 만들면 됩니다.
이를 RoomWithABomb 클래스와 BombWall클래스로 정의 합니다.
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

