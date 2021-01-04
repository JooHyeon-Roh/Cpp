#pragma once

#include "MapSite.h"

class CWall : public CMapSite
{
public:
	CWall();
	~CWall();

public:
	virtual void Enter();
};