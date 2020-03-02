#include "MazeGame.h"

CMazeGame::CMazeGame()
{
}

CMazeGame::~CMazeGame()
{
}

/*
CreateMaze 는 방 사이에 문이 있는 두 개의 방으로 구성된 미로를 만듭니다.

문제는 코드의 유연성이 떨어진다는 것입니다. 생성패턴은 이런 상황에서 어떻게 유연한 설계를 할 수 있는 지에 대한 해법을 제공합니다.
특히 미로의 구성요소를 정의하는 클래스를 쉽게 변경할 수 있는 방법을 제공합니다

기존 미로가 갖고 있는 레이아웃을 재사용하면서 마법 주문이 걸린 미로가 있는 게임을 만들고 싶다고 가정해 봅시다.
이 마법의 미로 게임을 만들기 위해서는 단어를 맞추면 문이 열리는 DoorNeedingSpell이라든지, 마법 키나 단어 등 특별한 항목을 포함하는 EnchantedRoom과
같은 새로운 구성요소가 필요합니다.

지금 시점에서 가장 큰 장애 요인은 클래스들의 인스턴스를 직접 생성하도록 하드 코딩한다는 점입니다. 생성 패턴은 이런 어려움을 이길 수 있는 여러가지 방법을 제공합니다.

	- CreateMaze가 방, 벽, 문을 생성하기 위해서 생성자를 이용하지 않고 가상함수를 호출하도록 구현되어 있다면, 이 가상 함수의 실제 구현을 다양한 방법으로
	변경할 수 있을 것입니다. 이 방법은 팩토리 메서드 패턴의 한 예입니다.

	- CreateMaze가 방, 벽, 문을 생성하기 위해 생성 방법을 알고 있는 객체를 매개변수로 넘겨받을 수 있다면, 
	생성 방법이 바뀔 때마다 새로운 매개 변수를 넘겨받음으로써 생성할 객체의 유형을 달리할 수 있습니다. 이는 추상 팩토리 패턴의 예입니다.

	- CreateMaze가 생성하고자 하는 미로에 방, 문, 벽을 추가하는 연산을 사용해서 새로운 미로를 만들 수 있는 
	객체를 넘겨받는다면 미로를 만드는 방법이나 변경을 이 객체의 상속을 통해서 해결할 수 있습니다. 이는 빌더 패턴의 예입니다.

	- CreateMaze를 이미 만든 다양한 방, 문, 벽 객체로 매개변수화하는 방법도 가능한데, 이미 만든 객체를 복사해서 미로에 추가하면, 
	이들 인스턴스를 교체하여 미로의 복합 방법을 변경할 수 있습니다. 이는 프로토타입 패턴의 예입니다.


다섯 개 생성 패턴 중에서 위에 쓰지 않은 싱글턴 패턴이란 것이 있습니다. 이 패턴은 한 게임에 오로지 하나의 미로 객체만 존재할 수 있고 
그 게임에서 돌아가는 모든 게임 객체들이 이 미로에 접근이 가능하도록 보장합니다. 전역 변수나 전역 함수에 의존할 필요 없이 이런 일이 가능합니다. 
또한 싱글턴 패턴은 기존 코드를 건드리지 않고도 미로를 쉽게 대체하거나 확장할 수 있도록 해 줍니다.
*/

CMaze* CMazeGame::CreateMaze(CMazeFactory& factory)
{
	CMaze* aMaze = factory.MakeMaze();
	CRoom* r1 = factory.MakeRoom(1);
	CRoom* r2 = factory.MakeRoom(2);
	CDoor* aDoor = factory.MakeDoor(r1, r2);

	aMaze->AddRoom(r1);
	aMaze->AddRoom(r2);

	r1->SetSide(E_DIRECTION::North, factory.MakeWall());
	r1->SetSide(E_DIRECTION::East, aDoor);
	r1->SetSide(E_DIRECTION::South, factory.MakeWall());
	r1->SetSide(E_DIRECTION::West, factory.MakeWall());

	r2->SetSide(E_DIRECTION::North, factory.MakeWall());
	r2->SetSide(E_DIRECTION::East, factory.MakeWall());
	r2->SetSide(E_DIRECTION::South, factory.MakeWall());
	r2->SetSide(E_DIRECTION::West, aDoor);

	return aMaze;
}
