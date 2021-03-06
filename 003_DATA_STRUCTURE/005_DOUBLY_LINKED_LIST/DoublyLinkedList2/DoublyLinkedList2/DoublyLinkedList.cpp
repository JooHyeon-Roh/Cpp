#include "DoublyLinkedList.h"
#include <cstdio>
#include <stdlib.h>

void Init(List* pList)
{
	pList->head = (Node*)malloc(sizeof(Node));
	pList->head->next = nullptr;
	pList->head->prev = nullptr;
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
		pNewNode->prev = pNode;
		if (pNewNode->next != nullptr)
		{
			pNewNode->next->prev = pNode;
		}
		pNode->next = pNewNode;
	}
	else
	{
		pList->head->data = data;
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
				pNode->next->prev = pNode;
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
