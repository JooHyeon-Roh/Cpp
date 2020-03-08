#pragma once

/*
�̷� ���� ������ �߻� ���丮 ������ ����� ���ô�. MazeFactory Ŭ������ �̷��� ������ҵ��� �����մϴ�. �̴� ��, ���� �� ������ ���� ����� ���ϴ�.
�̸� ���� ���Ͽ� ���ǵ� �̷ο� ���� ��ȹ�� �о� �ش� �̷θ� ������ ���� ���� ���̰�, ���α׷����� ���������� �̷θ� ������� �������Դϴ�.
MazeFactory ��ü�� ���ڷ� �޾� �̷θ� ����� ���α׷��̱� ������ ��, ��, ���� ���� Ŭ������ ����ؾ� �մϴ�.
*/

/*
MazeFactory�� �ܼ��� ���丮 �޼������ ���� ����ü�Դϴ�. �̷��� �ϴ� ���� �߻� ���丮 ������ �����ϴ� ���� �Ϲ����� ����Դϴ�.
����, MazeFactory �� �߻� Ŭ������ �ƴϹǷ� AbstractrFactory�� ConcreteFactory�� ����� ���� �ִµ���, �߻� ���丮 ������ �����ϰ� �����ϴ� �� �ϳ���
�Ϲ����� ���� ������� ���ø� �ǰڽ��ϴ�. MazeFactory �� ���丮 �޼��带 ��� �����ϴ� ��ü Ŭ�����̹Ƿ� ������ ������ �������ϰ� ����Ŭ������ �����Ͽ�
���ο� MazeFactory�� ���� ����� �ֽ��ϴ�.
*/

#include "Maze.h"
#include "Room.h"
#include "Wall.h"
#include "Door.h"
#include "Spell.h"

class CMazeFactory
{
public:
	CMazeFactory();
	~CMazeFactory();

public:
	virtual CMaze* MakeMaze() const;
	virtual CWall* MakeWall() const;
	virtual CRoom* MakeRoom(int n) const;
	virtual CDoor* MakeDoor(CRoom* r1, CRoom* r2) const;
};

