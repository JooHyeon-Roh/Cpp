#pragma once
#ifndef __QUEUE_FROM_POINTER_H__
#define __QUEUE_FROM_POINTER_H__

typedef struct _Node
{
	int data;
	_Node* next;
}Node;

typedef struct _Queue
{
	int dataSize;
	_Node* front;
}Queue;

void Init(Queue* queue);
void Push(Queue* queue, int data);

int Pop(Queue* queue);
int Peek(Queue* queue);

void Print(Queue* queue);

#endif