#include "Queue.h"
#include <cstdio>
#include <stdlib.h>

void Init(Queue* queue)
{
	queue->front = (Node*)malloc(sizeof(Node));
	queue->front->next = nullptr;
	queue->dataSize = 0;
	return;
}

void Push(Queue* queue, int data)
{
	if (queue->dataSize > 0)
	{
		Node* pNewNode = (Node*)malloc(sizeof(Node));
		Node* pNode = queue->front;
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
		queue->front->data = data;
	}

	++(queue->dataSize);

	return;
}

int Pop(Queue* queue)
{
	int result = queue->front->data;

	queue->front = queue->front->next;

	return result;
}

int Peek(Queue* queue)
{
	return queue->front->data;
}

void Print(Queue* queue)
{
	Node* pNode = (Node*)malloc(sizeof(Node));

	pNode = queue->front;

	while (pNode != nullptr)
	{
		printf("[%d]\n", pNode->data);
		pNode = pNode->next;
	}

	free(pNode);
	return;
}
