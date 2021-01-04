#pragma once

#include "cstdio"
#include "cstdlib"
#include "cstring"

enum class E_DIRECTION
{
    North,
    South,
    East,
    West
};

class CMapSite
{
public:
    CMapSite();
    ~CMapSite();

public:
    virtual void Enter() = 0; //구현부를 갖지 않는 순수 가상 메서드

};