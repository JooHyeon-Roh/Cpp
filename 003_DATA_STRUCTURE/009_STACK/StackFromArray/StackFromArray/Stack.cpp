#include "Stack.h"
#include <cstdio>

void Init(Stack* stack)
{
	stack->arr[MAX_SIZE] = { 0, };
	stack->end = 0;
}

void Push(Stack* stack, int data)
{
	if (stack->end == MAX_SIZE)
	{
		printf("스택이 가득차 있습니다.\n");
	}
	else
	{
		stack->arr[stack->end] = data;
		++(stack->end);
	}

	return;
}

int Pop(Stack* stack)
{
	if (stack->end == 0)
	{
		printf("큐가 비어 있습니다.\n");
		return -1;
	}
	else
	{
		int result = stack->arr[stack->end - 1];
		stack->arr[stack->end] = 0;
		--(stack->end);
		return result;
	}
}

int Peek(Stack* stack)
{
	if (stack->end == 0)
	{
		printf("큐가 비어 있습니다.\n");
		return -1;
	}
	else
	{
		return stack->arr[stack->end - 1];
	}
}

void Print(Stack* stack)
{
	for (int i = stack->end; i > 0; --i)
	{
		printf("Print = [%d].\n", i, stack->arr[i]);
	}
}
