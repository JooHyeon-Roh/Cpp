#include "MazeGame.h"

CMazeGame::CMazeGame()
{
}

CMazeGame::~CMazeGame()
{
}

CMaze* CMazeGame::CreateMaze()
{
	printf("�̷� ���� ����!\n");
	CMaze* aMaze = new CMaze;
	printf("�̷� ���� �Ϸ�!\n");


	printf("��1 ���� ����!\n");
	CRoom* r1 = new CRoom(1);
	printf("��1 ���� �Ϸ�!\n");
	printf("��2 ���� ����!\n");
	CRoom* r2 = new CRoom(2);
	printf("��2 ���� �Ϸ�!\n");

	printf("�� ���� ����!\n");
	CDoor* theDoor = new CDoor(r1, r2);
	printf("�� ���� �Ϸ�!\n");

	aMaze->AddRoom(r1);
	aMaze->AddRoom(r2);

	r1->SetSide(E_DIRECTION::NORTH, new CWall);
	r1->SetSide(E_DIRECTION::EAST, theDoor);
	r1->SetSide(E_DIRECTION::SOUTH, new CWall);
	r1->SetSide(E_DIRECTION::WEST, new CWall);

	r2->SetSide(E_DIRECTION::NORTH, new CWall);
	r2->SetSide(E_DIRECTION::EAST, new CWall);
	r2->SetSide(E_DIRECTION::SOUTH, new CWall);
	r2->SetSide(E_DIRECTION::WEST, theDoor);

	while (true)
	{
		char direct;
		system("cls");
		printf("�̵��Ͻ� ������ �������ּ���(��:E, ��:W, ��:S, ��:N) : ");
		scanf_s("%c", &direct, sizeof(direct));

		if (direct != 'E' && direct != 'W' && direct != 'S' && direct != 'N')
		{
			continue;
		}
		else
		{
			printf("������ ���� = [%c]", direct);
			break;
		}
	}

	return aMaze;
}
