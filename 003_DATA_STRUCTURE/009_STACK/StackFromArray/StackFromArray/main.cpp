#include <cstdio>
#include "Stack.h"

int main()
{
	{
		Stack* stack = new Stack;

		Init(stack);

		Push(stack, 1);
		Push(stack, 2);
		Push(stack, 3);
		Push(stack, 4);

		int data = Pop(stack);
		printf("pop = [%d]\n\n", data);

		data = Peek(stack);
		printf("Peek = [%d]\n\n", data);

		Print(stack);

		delete stack;
	}

	//{
	//	Queue stack;
	//	Init(&stack);
	//}
	return 0;
}