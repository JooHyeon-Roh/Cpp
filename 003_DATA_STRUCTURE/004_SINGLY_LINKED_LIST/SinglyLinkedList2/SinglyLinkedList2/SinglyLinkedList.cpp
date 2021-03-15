#include "SinglyLinkedList.h"
#include <cstdio>
#include <stdlib.h>

void Init(NodeInfo* pNodeInfo)
{
	pNodeInfo->head = (Node*)malloc(sizeof(Node));
	pNodeInfo->head->next = nullptr;
	pNodeInfo->dataSize = 0;
	return;
}

bool Insert(NodeInfo* pNodeInfo, int data)
{
	if (pNodeInfo->dataSize > 0)
	{
		Node* pNewNode = (Node*)malloc(sizeof(Node));
		Node* pNode = pNodeInfo->head;
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
		pNodeInfo->head->data = data;
	}

	++(pNodeInfo->dataSize);

	return true;
}

bool Delete(NodeInfo* pNodeInfo, int data)
{
	if (pNodeInfo->dataSize > 0)
	{
		Node* pNode = pNodeInfo->head;

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

	--(pNodeInfo->dataSize);

	return true;
}

void PrintData(NodeInfo* pNodeInfo)
{
	if (pNodeInfo->dataSize > 0)
	{
		Node* pNode = (Node*)malloc(sizeof(Node));

		pNode = pNodeInfo->head;

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

int Count(NodeInfo* pNodeInfo)
{
	return pNodeInfo->dataSize;
}
