#include "Stack.h"
#include <cstdio>
#include <stdlib.h>

void Init(Stack* stack)
{
	stack->head = (Node*)malloc(sizeof(Node));
	stack->head->next = nullptr;
	stack->dataSize = 0;
	return;
}

void Push(Stack* stack, int data)
{
	if (stack->dataSize > 0)
	{
		Node* pNewNode = (Node*)malloc(sizeof(Node));
		Node* pNode = stack->head;
		pNewNode->data = data;
		pNewNode->next = pNode;
		stack->head = pNewNode;
	}
	else
	{
		stack->head->data = data;
	}

	++(stack->dataSize);

	return;
}

int Pop(Stack* stack)
{
	int result = stack->head->data;
	Node* pNode = (Node*)malloc(sizeof(Node));
	pNode = stack->head;

	stack->head = stack->head->next;

	free(pNode);
	return result;
}

int Peek(Stack* stack)
{
	return stack->head->data;
}

void Print(Stack* stack)
{
	Node* pNode = (Node*)malloc(sizeof(Node));

	pNode = stack->head;

	while (pNode != nullptr)
	{
		printf("[%d]\n", pNode->data);
		pNode = pNode->next;
	}

	free(pNode);
	return;
}
