#include "MazeGame.h"

CMazeGame::CMazeGame()
{
}

CMazeGame::~CMazeGame()
{
}

CMaze* CMazeGame::CreateMaze()
{
	printf("미로 생성 시작!\n");
	CMaze* aMaze = new CMaze;
	printf("미로 생성 완료!\n");


	printf("방1 생성 시작!\n");
	CRoom* r1 = new CRoom(1);
	printf("방1 생성 완료!\n");
	printf("방2 생성 시작!\n");
	CRoom* r2 = new CRoom(2);
	printf("방2 생성 완료!\n");

	printf("문 생성 시작!\n");
	CDoor* theDoor = new CDoor(r1, r2);
	printf("문 생성 완료!\n");

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
		printf("이동하실 방향을 선택해주세요(동:E, 서:W, 남:S, 북:N) : ");
		scanf_s("%c", &direct, sizeof(direct));

		if (direct != 'E' && direct != 'W' && direct != 'S' && direct != 'N')
		{
			continue;
		}
		else
		{
			printf("선택한 방향 = [%c]", direct);
			break;
		}
	}

	return aMaze;
}
