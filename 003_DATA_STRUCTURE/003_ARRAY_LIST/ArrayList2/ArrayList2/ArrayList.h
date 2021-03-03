#pragma once
#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

const int MAX_SIZE = 100;

typedef struct _ArrayList
{
	int arr[MAX_SIZE] = { 0, };
	int dataSize;
	int curPos;
} ArrayList;


void Init(ArrayList* plist);
bool Insert(ArrayList* plist, int data);

bool First(ArrayList* plist, int& pdata);
bool Next(ArrayList* plist, int& pdata);

int Remove(ArrayList* plist);
int Count(ArrayList* plist);

#endif