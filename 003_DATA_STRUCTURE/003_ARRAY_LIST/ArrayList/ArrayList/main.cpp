#include <cstdio>

const int MAX_SIZE = 100;

typedef struct ArrayList
{
	int arr[MAX_SIZE] = { 0, };
	int size = 0;
} ArrayList;

enum class IncDec{
	Start,
	Inc,
	Dec,
	End
};

bool IsEmpty(ArrayList* list)
{
	printf("[IsEmpty] 순차 리스트가 비어있는지 체크합니다.\n");

	if (list->size > 0)
	{
		printf("[IsEmpty] 순차 리스트가 비어있지 않습니다.\n");
		return false;
	}

	printf("[IsEmpty] 순차 리스트가 비어있습니다.\n");
	return true;
}

bool IsFull(ArrayList* list, IncDec incDec)
{
	printf("[IsFull] 순차 리스트에 크기를 체크합니다.\n");

	if (incDec == IncDec::Inc)
	{
		printf("[IsFull] 순차 리스트에 추가를 실행하므로 크기를 추가하여 체크합니다.\n");
		if (list->size + 1 > MAX_SIZE)
			return false;
	}
	else if (incDec == IncDec::Dec)
	{
		printf("[IsFull] 순차 리스트에 삭제를 실행하므로 크기를 삭제하여 체크합니다.\n");
		if (list->size - 1 > MAX_SIZE)
			return false;
	}
	else if (incDec == IncDec::Start)
	{
		if (list->size > MAX_SIZE)
			return false;
	}
	else
	{
		printf("[IsFull] 순차 리스트의 체크에 실패하였습니다.\n");
		return false;
	}

	printf("[IsFull] 순차 리스트가 가득차 있지 않습니다.\n");
	return true;
}

bool PrintList(ArrayList* list)
{
	printf("[PrintList] 순차 리스트를 출력합니다.\n");

	if (IsEmpty(list))
	{
		printf("[PrintList] -> [IsEmpty] 순차 리스트가 비어 있어 데이터를 출력 할수 없습니다.\n");
		return false;
	}

	for (int i = 0; i < list->size; ++i)
	{
		printf("i = [%d], value = [%d]\n", i, list->arr[i]);
	}

	return true;
}

int GetValue(ArrayList* list, int pos)
{
	if (list->size < pos)
	{
		printf("[GetValue] 순차 리스트의 크기보다 큰 위치의 데이터를 요청하였습니다. size = [%d], pos = [%d]\n", list->size, pos);
		return -1;
	}

	return list->arr[pos - 1];
}

int GetSize(ArrayList* list)
{
	return list->size;
}

bool ListValueMove(ArrayList* list, int pos, IncDec incDec)
{
	int realSize;
	if (incDec == IncDec::Inc)
	{
		realSize = list->size + 1;

		for (int i = realSize; i >= pos; --i)
			list->arr[i] = list->arr[i - 1];

	}
	else if (incDec == IncDec::Dec)
	{
		realSize = list->size;

		for (int i = pos; i < realSize; ++i)
			list->arr[i] = list->arr[i + 1];
	}
	else
	{
		printf("[ListValueMove] 순차 리스트의 추가, 삭제 구분을 잘못하였습니다.\n");
		return false;
	}

	return true;
}

bool InsertFirst(ArrayList * list, int value)
{
	int firstNum = 0;
	IncDec inc = IncDec::Inc;
	if (IsFull(list, inc))
	{
		if (list->size > 0)
		{
			if (!ListValueMove(list, firstNum, inc))
				return false;
		}

		list->arr[firstNum] = value;
		list->size = list->size + 1;
		printf("[InsertFirst] 순차 리스트 가장 처음에 데이터를 추가하였습니다.\n");
		return true;
	}

	printf("[InsertFirst] 순차 리스트의 크기를 초과하여 값을 입력 할수 없습니다.\n");
	return false;
}

bool Insert(ArrayList* list, int pos, int value)
{
	IncDec inc = IncDec::Inc;
	if (IsFull(list, inc))
	{
		if (list->size < pos)
		{
			printf("[InsertFirst] 순차로 데이터를 입력하지 않아 데이터를 입력 할수 없습니다.\n");
			return false;
		}
		else if(list->size > pos)
		{
			if (!ListValueMove(list, pos, inc))
				return false;
		}

		list->arr[pos - 1] = value;
		list->size = list->size + 1;
		printf("[InsertFirst] 순차 리스트 [%d]에 데이터를 추가하였습니다.\n", pos);
		return true;
	}

	printf("[InsertFirst] 순차 리스트의 크기를 초과하여 값을 입력 할수 없습니다.\n");
	return false;
}

bool InsertLast(ArrayList* list, int value)
{
	int lastNum = list->size;
	IncDec inc = IncDec::Inc;
	if (IsFull(list, inc))
	{
		list->arr[lastNum] = value;
		list->size = lastNum + 1;
		printf("[InsertLast] 순차 리스트 가장 마지막에 데이터를 추가하였습니다.\n");
		return true;
	}

	printf("[InsertLast] 순차 리스트의 크기를 초과하여 값을 입력 할수 없습니다.\n");
	return false;
}

bool Delete(ArrayList* list, int pos)
{
	printf("[Remove] -> [IsEmpty] 순차 리스트 [%d]의 데이터를 삭제합니다.\n", pos);

	if (IsEmpty(list))
	{
		printf("[Remove] -> [IsEmpty] 순차 리스트가 비어 있어 데이터를 삭제 할수 없습니다.\n");
		return false;
	}
	
	if (GetValue(list, pos) == -1)
	{
		printf("[Remove] -> [GetValue]\n");
		return false;
	}

	if (list->size != pos)
	{
		IncDec dec = IncDec::Dec;
		if (!ListValueMove(list, pos, dec))
			return false;
	}
	else
		list->arr[pos] = 0;

	list->size = list->size - 1;
	return true;
}

void Clear(ArrayList* list)
{
	printf("[Clear] 순차 리스트를 초기화 합니다.\n");
	for (int i = 0; i < list->size; ++i)
	{
		list->arr[i] = 0;
	}

	list->size = 0;
	return;
}

int main()
{
	ArrayList arrayList;
	//IsEmpty(&arrayList);
	//IsFull(&arrayList, IncDec::Start);
	//PrintList(&arrayList);

	//InsertFirst(&arrayList, 1);
	//PrintList(&arrayList);

	//InsertLast(&arrayList, 2);
	//PrintList(&arrayList);

	//Insert(&arrayList, 10, 10);
	//InsertFirst(&arrayList, 1);
	//PrintList(&arrayList);

	//int size = GetSize(&arrayList);
	//printf("[GetSize] size = [%d]\n", size);

	//int pos = 1;
	//int value = GetValue(&arrayList, pos);
	//printf("[GetValue] value [%d] = [%d]\n", pos, value);

	//Delete(&arrayList, 2);
	//PrintList(&arrayList);

	//Clear(&arrayList);
	//PrintList(&arrayList);

	return 0;
}