#pragma once
#ifndef __STACK_FROM_ARRAY_H__
#define __STACK_FROM_ARRAY_H__

const int MAX_SIZE = 10;

typedef struct _Stack
{
	int arr[MAX_SIZE];
	int end;
}Stack;

void Init(Stack* stack);
void Push(Stack* stack, int data);

int Pop(Stack* stack);
int Peek(Stack* stack);

void Print(Stack* stack);

#endif