#include "Deque.h"
#include <cstdio>
#include <stdlib.h>

void Init(Deque* deque)
{
	deque->head = nullptr;
	deque->tail = nullptr;
	deque->dataSize = 0;
	return;
}

void PushHead(Deque* deque, int data)
{
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	if (deque->head == nullptr)
	{
		deque->head = pNewNode;
		deque->head->data = data;
		deque->head->prev = nullptr;
		deque->head->next = deque->tail;
	}
	else
	{
		Node* pNewNode = (Node*)malloc(sizeof(Node));
		Node* pNode = deque->head;
		pNewNode->data = data;

		pNewNode->next = deque->head;
		pNewNode->prev = nullptr;
		deque->head->prev = pNewNode;
		deque->head = pNewNode;
	}
}

void PushTail(Deque* deque, int data)
{
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	if (deque->tail == nullptr)
	{
		deque->tail = pNewNode;
		deque->tail->data = data;
		deque->tail->next = nullptr;
		if (deque->head == nullptr)
		{
			deque->tail->prev = deque->head;
		}
		else
		{
			Node* pNode = deque->head;
			while (pNode != nullptr)
			{
				if (pNode->next == nullptr)
				{
					deque->tail->prev = pNode;
					pNode->next = deque->tail;
					break;
				}
				pNode = pNode->next;
			}
		}
	}
	else
	{
		Node* pNewNode = (Node*)malloc(sizeof(Node));
		Node* pNode = deque->tail;
		pNewNode->data = data;

		pNode->next = pNewNode;
		pNewNode->next = nullptr;
		pNewNode->prev = pNode;
		deque->tail = pNewNode;
	}

}

int PopHead(Deque* deque)
{
	Node* pNode = deque->head;
	int result = pNode->data;

	deque->head = pNode->next;
	deque->head->prev = nullptr;

	free(pNode);
	return result;
}

int PopTail(Deque* deque)
{
	Node* pNode = deque->tail;
	int result = pNode->data;

	deque->tail = pNode->prev;
	deque->tail->next = nullptr;

	free(pNode);
	return result;
}


void Print(Deque* deque)
{
	Node* pNode = (Node*)malloc(sizeof(Node));

	pNode = deque->head;

	while (pNode != nullptr)
	{
		printf("[%d]\n", pNode->data);
		pNode = pNode->next;
	}

	free(pNode);
	return;
}
