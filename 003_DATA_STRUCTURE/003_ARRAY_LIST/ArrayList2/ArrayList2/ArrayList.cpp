#include <cstdio>
#include "ArrayList.h"

void Init(ArrayList* plist)
{
	plist->dataSize = 0;
	plist->curPos = -1;
	return;
}

bool Insert(ArrayList* plist, int data)
{
	if (plist->dataSize > MAX_SIZE)
	{
		printf("저장이 불가능합니다.");
		return false;
	}

	plist->arr[plist->dataSize] = data;
	(plist->dataSize)++;
	return false;
}

bool First(ArrayList* plist, int& pdata)
{
	if (plist->dataSize == 0)
		return false;

	(plist->curPos) = 0;
	pdata = plist->arr[0];

	return true;
}

bool Next(ArrayList* plist, int& pdata)
{
	if (plist->curPos >= (plist->dataSize) - 1)
		return false;

	(plist->curPos)++;
	pdata = plist->arr[plist->curPos];
	return true;
}

int Remove(ArrayList* plist)
{
	int rpos = plist->curPos;
	int num = plist->dataSize;
	int i;
	int rdata = plist->arr[rpos];

	for (i = rpos; i < num - 1; i++)
		plist->arr[i] = plist->arr[i + 1];

	(plist->dataSize)--;
	(plist->curPos)--;
	return rdata;
}

int Count(ArrayList* plist)
{
	return plist->dataSize;
}
