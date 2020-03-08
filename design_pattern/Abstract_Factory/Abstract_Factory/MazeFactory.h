#pragma once

/*
미로 생성 문제에 추상 팩토리 패턴을 사용해 봅시다. MazeFactory 클래스는 미로의 구성요소들을 생성합니다. 이는 방, 벽과 방 사이의 문을 만들어 냅니다.
이를 위해 파일에 정의된 미로에 대한 계획을 읽어 해당 미로를 구성할 수도 있을 것이고, 프로그램에서 임의적으로 미로를 만들수도 있을것입니다.
MazeFactory 객체를 인자로 받아 미로를 만드는 프로그램이기 때문에 방, 벽, 문에 대한 클래스를 명시해야 합니다.
*/

/*
MazeFactory는 단순히 팩토리 메서드들이 모인 집합체입니다. 이렇게 하는 것이 추상 팩토리 패턴을 구현하는 가장 일반적인 방법입니다.
또한, MazeFactory 는 추상 클래스가 아니므로 AbstractrFactory나 ConcreteFactory로 사용할 수도 있는데요, 추상 팩토리 패턴을 간단하게 응용하는 또 하나의
일반적인 구현 방법으로 보시면 되겠습니다. MazeFactory 는 팩토리 메서드를 모두 정의하는 구체 클래스이므로 변경할 연산을 재정의하고 서브클래스를 정의하여
새로운 MazeFactory를 쉽게 만들수 있습니다.
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

