#include "cstring"

/*
추상 팩토리(Abstract Factory)
	- 상세화된 서브 클래스를 정의하지 않고도 서로 관련성이 있거나 독립적인 여러 객체의 군을 생성하기 위한 인터페이스를 제공

	- 모티프와 프레젠테이션 매니저와 같은 인터페이스 툴킬을 살펴보면, 서로 다른 룩앤필 표준을 가지고 있습니다. 서로 다른 룩앤필은
	서로 다른 사용자 인터페이스의 표현 방식과 행동을 갖습니다. 스크롤바, 윈도우 버튼은 모양이 다르고 동작방식도 다릅니다. 개발한 응용 프로그램이 
	서로 다른 룩앤필 표준에 상관없이 이식성을 가지려면, 응용 프로그램이 각 사용자 인터페이스 툴킷에서 제공하는 위젯을 직접 사용하지 못하도록 해야 합니다.

	- 이런 문제는 구체적 사용자 인터페이스의 위젯을 사용하지 말고 추상 클래스인 WidgetFactory를 정의하여 해결하는 게 좋습니다. 
	WidgetFactory 클래스는 위젯의 기본 유저 인터페이스 요소(윈도우,스크롤바,버튼 등)를 생성할 수 있는 인터페이스를 정의합니다. 
	실제적으로 구현 종속적인 인스턴스를 생성하기 위해서는 팩토리와 구분하여 각각의 위젯별로 추상화된 클래스를 정의해야 하고 
	이를 상속하는 구체적인 서브클래스를 정의하여 구체적 룩앤필 표준에 대한 구현을 제공합니다

	- 이 패턴을 사용하기 위해서는 AbsractFactory에 해당하는 WidgetFactory뿐만 아니라 각 룩앤필 표준에 대한 WidgetFactory를 상속받는 구체 서브 클래스들을 정의해야 합니다

활용성
	- 추상 팩토리는 다음의 경우에 사용합니다

	- 객체가 생성되거나 구성, 표현되는 상식과 무관하게 시스템을 독립적으로 만들고자 할 때
	- 여러 제품군 중 하나를 선택해서 시스템을 설정해야 하고 한번 구성한 제품을 다른것으로 대체할 수 있을 때
	- 관련된 제품 객체들이 함께 사용되도록 설계되었고, 이부분에 대한 제약이 외부에도 지켜지도록 하고 싶을 때
	- 제뭎에 대한 클래스 라이브러리를 제공하고, 그들의 구현이 아닌 인터페이스를 노출시키고 싶은 때

참여자
	- AbstractFactory: 개념적 제품에 대한 객체를 생성하는 연산으로 인터페이스를 정의합니다
	- ConcreteFactory: 구체적인 제품에 대한 객체를 생성하는 연산을 구현합니다
	- AbstractProduct: 개념적 제품 객체에 대한 인터페이스를 정의합니다
	- ConcreteProduct: 구체적으로 팩토리가 생성할 객체를 정의하고 AbstractProduct가 정의하는 인터페이스를 구현합니다
	- Client : AbstractFactory와 AbstractProduct 클래스에 선언된 인터페이스를 사용합니다

협력방법
	- 일반적으로 ConcreteFactory클래스의 인스턴스 한개가 런타임에 만들어집니다. 
	이 구체 팩토리(Concrete Factory)는 어떤 특정 구현을 갖는 제품 객체를 생성합니다 서로 다른 제품 객체를 생성하려면 사용자는 서로 다른 구체 팩토리를 사용해야 합니다
	- AbstractFactory는 필요한 제품 객체를 생성하는 책임을 ConcreteFactory 서브클래스에게 위임합니다

결과
	- 추상 팩토리 패턴을 쓰면서 얻는 이익과 부담은 다음과 같습니다

	- 구체적인 클래스를 분리합니다 추상 팩토리 패턴을 쓰면 응용프로그램이 생성할 객체의 클래스를 제어할 수 있습니다 
	팩토리는 제품 객체를 생성하는 과정과 책임을 캡슐화한 것이기 때문에 구체적인 구현 클래스가 사용자에게서 분리됩니다. 
	일반 프로그램은 추상 인터페이스를 통해서만 인스턴스를 조작합니다. 제품 클래스 이름이 구체 팩토리의 구현에서 분리 되므로 사용자 코드에는 나타나지 않는 것입니다

	- 제품군을 쉽게 대체할 수 있도록 합니다 구체 팩토리의 클래스는 응용 프로그램에서 한 번만 나타나기 때문에 응용프로그램이 사용할 구체 팩토리를 변경하기는 쉽습니다. 
	또한 구체 팩토리를 변경함으로써 응용프로그램은 서로 다른 제품을 사용할 수 있게 됩니다.추상 팩토리는 필요한 모든 것을 생성하기 때문에 전체 제품군은 한번에 변경이 가능합니다

	- 제품 사이에 일관성을 증진시킵니다 하나의 군 안에 속한 제품 객체들이 함께 동작하도록 설계되어 있을 때 
	응용프로그램은 한번에 오직 한 군에서 만든 객체를 사용하도록 함으로써 프로그램의 일관성을 갖도록 해야 합니다 추상 팩토리를 쓰면 이 점을 아주 쉽게 보장할 수 있습니다

	- 새로운 종류의 제품을 제공하기 어렵습니다 새로운 종류의 제품을 만들기 위해 기존 추상 팩토리를 확장하기가 쉽지 않습니다. 
	생성하는 제품은 추상 팩토리가 생성할 수 있는 제품 집합에만 고정되어 있기 때문입니다

관련 패턴
	- AbstractFactory 클래스는 팩토리 메서드 패턴을 이용해서 구현되는데, Prototype 패턴을 이용할 때도 있습니다 구체 팩토리는 Singleton 패턴을 이용해 구현하는 경우가 많습니다

구현
	- 팩토리를 단일체로 정의합니다
	전형적으로 응용프로그램은 한 제품군에 대해서 하나의 ConcreteFactory 인스턴스만 있으면 됩니다. 즉, 갖가지 제품의 종류를 만들어 내는 팩토리는 제품군에 대해서 하나면 되는 것입니다.
	그러므로 단일체로 구현하는 것이 바람직합니다. 이 단일체 역시 생성 패턴의 한 종류입니다. 

	- 제품을 생성합니다
	AbstractFactory는 단지 제품을 생성하기 위한 인터페이스를 선언하는 것이고, 그것을 생성하는 책임은 Product의 서브클래스인 Concrete-Product에 있습니다.
	이를 위한 가장 공통적인 방법은 각 제품을 위해서 팩토리 메서드를 정의하는 것입니다. AbstractFactory는 각 제품을 위해서 팩토리 메서드를 재정의(overriding)함으로써
	각 제품의 인스턴스를 만듭니다 이 구현은 간단하지만, 제품군이 약간 다르다면 각 제품군을 위한 새로운 구체 팩토리 서브클래스가 필요합니다. 많은 제품군이 가능하다면
	구체 팩토리는 원형 패턴을 이용해서 구현할 수 있습니다 구체 팩토리가 한 군내의 각 제품 원형 인스턴스로 초기화 되고 원형의 복사를 통해서 인스턴스를 생성합니다.
	원형 기반의 접근법은 새로운 제품군별로 새로운 구체 팩토리를 생성할 필요를 없애줍니다. 클래스를 특정 팩토리 안에 저장하여 다양한 특정 제품을 생성할 수 있도록 하는 것입니다.
	이 클래스들은 특정 팩토리를 대신해서 인스턴스 초기화를 통해서 새로운 팩토리를 정의합니다.

	- 확장 가능한 팩토리들을 정의합니다
	생성할 각 제품의 종률 별로 서로 다른 연산을 정의 합니다. 이 제품들의 종류는 연산의 시그너처를 보면 알수 있습니다.Crete-ProductA를 통해 ProductA를 만듭니다 
	새로운 종류의 제품이 추가되면 AbstractFactory의 인터페이스에도 새로운 연산을 추가해야 합니다. 좀더 유연하게 하려면 생성할 객체를 매개변수로 만들어 연산에 넘기면 됩니다
	그리고 매개변수에다가 생성할 객체의 종류를 표현합니다 이렇게 되면 AbstractFactory에는 Make() 연산만 있으면 되고, Make() 연산의 매개변수로 생성할 제품에 대한 식별자를 넘겨주게 됩니다
	이것이 원형 및 클래스에 기반을 둔 추상 팩토리에서 쓴 기법입니다

*/
#include "MazeGame.h"

int main(int argc, char* argv[])
{
	CMazeGame c_mazeGame;

	c_mazeGame.CreateMaze();

	return 0;
}