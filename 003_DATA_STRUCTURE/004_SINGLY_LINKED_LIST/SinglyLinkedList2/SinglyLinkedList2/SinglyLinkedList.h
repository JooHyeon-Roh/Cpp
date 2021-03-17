#pragma once
#ifndef __SINGLY_LINKED_LIST_H__
#define __SINGLY_LINKED_LIST_H__

typedef struct _Node
{
	int data;
	struct _Node* next;
}Node;

typedef struct _List
{
	int dataSize;
	struct _Node* head;
}List;

void Init(List* pList);
bool Insert(List* pList, int data);

bool Delete(List* pList, int data);

void PrintData(List* pList);
int Count(List* pList);

#endif