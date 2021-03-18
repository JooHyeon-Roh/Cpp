#pragma once
#ifndef __STACK_FROM_POINTER_H__
#define __STACK_FROM_POINTER_H__

typedef struct _Node
{
	int data;
	_Node* next;
}Node;

typedef struct _Stack
{
	int dataSize;
	_Node* head;
}Stack;

void Init(Stack* stack);
void Push(Stack* stack, int data);

int Pop(Stack* stack);
int Peek(Stack* stack);

void Print(Stack* stack);

#endif