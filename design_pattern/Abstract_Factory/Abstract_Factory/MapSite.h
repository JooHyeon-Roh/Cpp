#pragma once

/*
생성 패턴(Creational pattern)
     - 객체 생성에 관련된 패턴
     - 인스턴스를 만드는 절차를 추상화하는 패턴
    
     - 클래스 생성 패턴
        -> 인스턴스로 만들 클래를 다야하게 만들기 위한 용도로 상속을 사용
     - 객체 생성 패턴
        -> 인스턴스화 작업을 다른 객체에 떠넘김
    
     - 객체를 생성, 합성하는 방법이나 객체의 표현 방법과 시스템을 분리
     - 시스템이 어떤 구체 클래스를 사용하는지에 대한 정보를 캡슐화
     - 이들 클래스의 인스턴스들이 어떻게 만들고 어떻게 서로 맞붙는지에 대한 부분을 완전히 가려줌
    
     - 무엇이 생성되고, 누가 이것을 생성하며, 이것이 어떻게 생성되는지, 언제 생성할 것인지 결정하는데 유연성 확보
        -> 객체의 생성과 조합을 캡슐화해 특정 객체가 생성되거나 변경되어도 프로그램 주고에 영향을 크게 받지 않도록 유연성을 제공

생성 패턴 선택의 어려움
    - 프로토타입 패턴과 추상 팩토리 패턴중 무엇을 선택할지 고민해야 할 때
    - 빌더 패턴은 어떤 구성요소를 만들지 구현하는 데에 다른 생성 패턴 중 하나를 사용할수 있음
    - 원형 패턴은 자기 자신의 구현을 위해 컴퓨짓 패턴을 사용하기도 함

생성 패턴을 설명하기 위한 예제
    - 생성 패턴 간에는 매우 밀접한 관련성이 있기 때문에, 이들 간의 공통점과 차이점을 중심으로 다섯 개의 패턴을 공부하겠습니다.
    하나의 예제를 통해 각 패턴의 설명을 진행합니다. 컴퓨터 게임에 넣을 미로를 만드는 문제입니다. 패턴에 따라 미로와 게임이 어떻게 조금씩 다르게 만들어지는지
    잘 보시기 바랍니다. 주어진 예제에서 중요한 상은 미로를 어떻게 만들것인가 입니다. 미로는 방들의 집합이고, 각 방은 옆에 무엇이 있는지 알고 있는데, 방 옆에 있는
    것이 방일 수도 있고, 문일 수도 있고, 벽일 수도 있습니다.
    

        - 클래스 Room, Door, Wall은 우리가 개발하는 미로를 만드는 데 필요한 구성요소입니다.
*/


/*
        - 각 방은 네개의 방향을 갖는데, C++ 구현 시에는 열거형 타입으로 정의한 Direction을 사용하여 선언합니다
*/
enum class E_DIRECTION
{
    North,
    South,
    East,
    West
};

/*
        - CMapSite 클래스는 미로의 구성요소들에 필요한 모든 연산을 정의한 공통 추상 클래스 입니다. 예를 단순하게 하기 위해서 CMapSite는 Enter() 연산 하나만을
        정의 하도록 합니다. Enter() 메서드느 무엇에 들어가느냐에 따라 그 의미가 달라질 것입니다. 즉, 방에 들어간다면 위치가 바뀌도록 구현해야할 것입니다. 들어가는
        것이 문이라면 이렇게 구현합니다. 문이 열려있으면 문을 통해 다른 방으로 들어가도록 구현하고, 문이 닫혀있다면 상처를 입도록 구현하면 됩니다.
*/

#include "cstring"

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