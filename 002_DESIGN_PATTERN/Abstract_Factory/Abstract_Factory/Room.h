#pragma once

#include "MapSite.h"

/*
Room Ŭ���� ����
	- CMapSite �� ��ӹ��� ��ü���� Ŭ������ �̷ο� �ִ� �ٸ� ��ҿ� ���ü��� ������ ���� �մϴ�. �ٸ� ��ҵ� ��� �żݵ� ���ü��� ������ �����Ƿ� Room�� �ٸ�
	��ҵ��� �θ� Ŭ������ CMapSite�� ���� ���踦 ���� ������ �𵨸��մϴ�. Room Ŭ������ �� ��ȣ�� �����ϴµ�, �� ��ȣ�� �̷ο� �ִ� ���� �ĺ� �� �� �ֽ��ϴ�.
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