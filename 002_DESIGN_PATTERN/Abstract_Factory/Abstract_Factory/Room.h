#pragma once

#include "MapSite.h"

/*
Room 클래스 설명
	- CMapSite 를 상속받은 구체적인 클래스로 미로에 있는 다른 요소와 관련성을 갖도록 정의 합니다. 다른 요소들 어느 거솨도 관련성을 가질수 있으므로 Room은 다른
	요소들의 부모 클래스인 CMapSite와 연결 관계를 갖는 것으로 모델링합니다. Room 클래스는 방 번호를 저장하는데, 이 번호로 미로에 있는 방을 식별 할 수 있습니다.
*/

class CRoom : public CMapSite
{
public:
	CRoom();
	CRoom(int roomNo);
	~CRoom();

public:
	CMapSite* GetSite(E_DIRECTION e_direction) const;
	void SetSide(E_DIRECTION e_direction, CMapSite* p_cMapSite);
	virtual void Enter();

private:
	CMapSite* _sides[4];

	int _roomNumber;

};