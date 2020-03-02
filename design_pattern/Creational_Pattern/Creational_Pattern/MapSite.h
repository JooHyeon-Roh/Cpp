#pragma once

#include "cstring"

/*
		- 각 방은 네개의 방향을 갖는데, C++ 구현 시에는 열거형 타입으로 정의한 Direction을 사용하여 선언합니다
*/

enum class E_DIRECTION
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

/*
		- CMapSite 클래스는 미로의 구성요소들에 필요한 모든 연산을 정의한 공통 추상 클래스 입니다. 예를 단순하게 하기 위해서 CMapSite는 Enter() 연산 하나만을
		정의 하도록 합니다. Enter() 메서드느 무엇에 들어가느냐에 따라 그 의미가 달라질 것입니다. 즉, 방에 들어간다면 위치가 바뀌도록 구현해야할 것입니다. 들어가는
		것이 문이라면 이렇게 구현합니다. 문이 열려있으면 문을 통해 다른 방으로 들어가도록 구현하고, 문이 닫혀있다면 상처를 입도록 구현하면 됩니다.
*/

class CMapSite
{
public:
	CMapSite();
	~CMapSite();

public:
	virtual void Enter() = 0; //구현부를 갖지 않는 순수 가상 메서드

};

/*
		- CMapSite 에 정의된 Enter()는 좀더 섬세한 게임 동작을 만드는 데 쓸수 있는 기본 연산입니다. 만약, 방에 있을 때 "동쪽으로 가시오" 라고 구현하고
		싶으면, 게임은 어떤 CMapSite가 동쪽에 인접한 것인지 판단한 후 그 대상에 정의된 Enter()를 호출하도록 메서드를 구현합니다. CMapSite의 서브 클래스가
		어떤 것이냐에 따라 Enter()는 위치를 변경하도록 구현할 수도 있고, 이동을 못하고 상처를 입도록 구현 할 수도 있습니다.
*/