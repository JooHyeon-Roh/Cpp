#pragma once
#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

const int MAX_SIZE = 100;

typedef struct _ArrayList
{
	int arr[MAX_SIZE] = { 0, };
	int dataSize;
} ArrayList;

void Init(ArrayList* plist);
bool Insert(ArrayList* plist, int pos, int data);

bool Delete(ArrayList* plist, int pos);

void PrintData(ArrayList* plist);
int Count(ArrayList* plist);

#endif