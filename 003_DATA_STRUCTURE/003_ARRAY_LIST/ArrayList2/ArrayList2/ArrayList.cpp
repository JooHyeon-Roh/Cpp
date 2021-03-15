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
		printf("�����Ͱ� ������ �߰��Ҽ� �����ϴ�.\n");
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
		printf("�����Ͱ� �����ϴ�.\n");
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
		printf("����� �����Ͱ� �����ϴ�.\n");
	}

	return;
}

int Count(ArrayList* plist)
{
	return plist->dataSize;
}
