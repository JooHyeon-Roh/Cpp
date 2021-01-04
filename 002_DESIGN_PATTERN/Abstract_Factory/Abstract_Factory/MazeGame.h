#pragma once

/*
CreateMaze() 연산은 방향을 정의하기 위해 방에 정의된 SetSide() 연산을 이용하였습니다. BombedMazeFactory로 방을 생성한다면 미로는 RoomWithABomb객체와
BombedWall 객체로 만들어집니다. RoomWithABob 클래스는 BombedWall 멤버를 접근해야 하므로 Wall*에 대한 매개 변소를 BombedWall*에 대한 매개변수로 반환해야 합니다.
이와 같은 타입 변환은 모든 벽들이 BombedMazeFactory내에서만 쓰고 있으며, BombedWall은 Wall의 서브클래스이므로 가능합니다.
*/

#include "MapSite.h"
#include "MazeFactory.h"
#include "BombedMazeFactory.h"

class CMazeGame
{
public:
	CMazeGame();
	~CMazeGame();

public:
	CMaze* CreateMaze(CMazeFactory& factory);

};