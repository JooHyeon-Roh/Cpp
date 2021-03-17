#include "CircularLinkedList.h"
#include <cstdio>
#include <stdlib.h>

void Init(List* pList)
{
	pList->head = (Node*)malloc(sizeof(Node));
	pList->head->next = nullptr;
	pList->dataSize = 0;
	return;
}

bool Insert(List* pList, int data)
{
	if (pList->dataSize > 0)
	{
		Node* pNewNode = (Node*)malloc(sizeof(Node));
		Node* pNode = pList->head;
		pNewNode->data = data;

		while (pNode->next != nullptr && pNode->next->data != data)
		{
			pNode = pNode->next;
		}

		pNewNode->next = pNode->next;
		pNode->next = pNewNode;
	}
	else
	{
		pList->head->data = data;
	}

	if (pList->dataSize > 1)
	{
		Node* pNode = pList->head;
		for (int i = 0; i < pList->dataSize; ++i)
		{
			pNode = pNode->next;
			if (i + 1 == pList->dataSize)
			{
				pNode->next = pList->head;
			}

		}
	}

	++(pList->dataSize);

	return true;
}

bool Delete(List* pList, int data)
{
	if (pList->dataSize > 0)
	{
		Node* pNode = pList->head;

		while (pNode != nullptr)
		{
			if (pNode->next->data == data)
			{
				Node* pNext = pNode->next;
				pNode->next = pNode->next->next;
				free(pNext);
				break;
			}
		}

	}
	else
	{
		printf("저장된 데이터가 없습니다.\n");
		return false;
	}

	--(pList->dataSize);

	return true;
}

void PrintData(List* pList)
{
	if (pList->dataSize > 0)
	{
		Node* pNode = (Node*)malloc(sizeof(Node));

		pNode = pList->head;

		while (pNode != nullptr)
		{
			printf("[%d]\n", pNode->data);
			pNode = pNode->next;
		}

		free(pNode);
	}
	else
	{
		printf("저장된 데이터가 없습니다.\n");
	}

	return;
}

int Count(List* pList)
{
	return pList->dataSize;
}
