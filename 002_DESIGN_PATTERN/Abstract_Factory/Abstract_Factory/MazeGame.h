#pragma once

/*
CreateMaze() ������ ������ �����ϱ� ���� �濡 ���ǵ� SetSide() ������ �̿��Ͽ����ϴ�. BombedMazeFactory�� ���� �����Ѵٸ� �̷δ� RoomWithABomb��ü��
BombedWall ��ü�� ��������ϴ�. RoomWithABob Ŭ������ BombedWall ����� �����ؾ� �ϹǷ� Wall*�� ���� �Ű� ���Ҹ� BombedWall*�� ���� �Ű������� ��ȯ�ؾ� �մϴ�.
�̿� ���� Ÿ�� ��ȯ�� ��� ������ BombedMazeFactory�������� ���� ������, BombedWall�� Wall�� ����Ŭ�����̹Ƿ� �����մϴ�.
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