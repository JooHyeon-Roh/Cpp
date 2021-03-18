#pragma once
#ifndef __DEQUE_FROM_POINTER_H__
#define __DEQUE_FROM_POINTER_H__

typedef struct _Node
{
	int data;
	_Node* prev;
	_Node* next;
}Node;

typedef struct _Deque
{
	int dataSize;
	_Node* head;
	_Node* tail;
}Deque;

void Init(Deque* deque);

void PushHead(Deque* deque, int data);
void PushTail(Deque* deque, int data);

int PopHead(Deque* deque);
int PopTail(Deque* deque);

void Print(Deque* deque);

#endif