#include <cstdio>
#include "ArrayList.h"

int main()
{
	ArrayList* arrayList = new ArrayList;
	Init(arrayList);

	Insert(arrayList, 1, 1);
	Insert(arrayList, 2, 2);
	Insert(arrayList, 3, 3);

	Delete(arrayList, 2);

	//�� ������ �� 
	int count = Count(arrayList);
	printf("count = [%d]\n", count);

	// ������ ���
	PrintData(arrayList);

	delete arrayList;
	return 0;
}