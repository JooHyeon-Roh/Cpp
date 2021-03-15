#include "ArrayList.h"
#include <cstdio>

void Init(ArrayList* plist)
{
	plist->dataSize = 0;
}

bool Insert(ArrayList* plist, int pos, int data)
{
	int realPos = pos - 1;

	if (plist->dataSize > MAX_SIZE)
	{
		printf("데이터가 가득차 추가할수 없습니다.\n");
		return false;
	}

	if (plist->dataSize > 0)
	{
		if (plist->dataSize >= pos)
		{
			for (int i = plist->dataSize; i > pos; --i)
			{
				plist->arr[i] = plist->arr[i - 1];
			}
		}
	}

	plist->arr[realPos] = data;
	++(plist->dataSize);

	return true;
}

bool Delete(ArrayList* plist, int pos)
{
	int realPos = pos - 1;

	if (plist->dataSize < 1)
	{
		printf("데이터가 없습니다.\n");
		return false;
	}

	if (plist->dataSize > pos)
	{
		for (int i = pos; i < plist->dataSize; ++i)
		{
			plist->arr[i - 1] = plist->arr[i];
		}
	}

	plist->arr[plist->dataSize] = 0;
	--(plist->dataSize);

	return true;
}

void PrintData(ArrayList* plist)
{
	if (plist->dataSize > 0)
	{
		for (int i = 0; i < plist->dataSize; ++i)
		{
			printf("[%d] = [%d]\n", i + 1, plist->arr[i]);
		}
	}
	else
	{
		printf("저장된 데이터가 없습니다.\n");
	}

	return;
}

int Count(ArrayList* plist)
{
	return plist->dataSize;
}
