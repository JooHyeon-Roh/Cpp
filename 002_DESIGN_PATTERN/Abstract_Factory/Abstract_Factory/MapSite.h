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
    virtual void Enter() = 0; //�����θ� ���� �ʴ� ���� ���� �޼���

};