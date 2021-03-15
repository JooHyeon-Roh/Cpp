#pragma once
#ifndef __SINGLY_LINKED_LIST_H__
#define __SINGLY_LINKED_LIST_H__

typedef struct _Node
{
	int data;
	struct _Node* next;
}Node;

typedef struct _NodeInfo
{
	int dataSize;
	struct _Node* head;
}NodeInfo;

void Init(NodeInfo* pNodeInfo);
bool Insert(NodeInfo* pNodeInfo, int data);

bool Delete(NodeInfo* pNodeInfo, int data);

void PrintData(NodeInfo* pNodeInfo);
int Count(NodeInfo* pNodeInfo);

#endif