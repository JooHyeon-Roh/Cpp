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
	printf("[IsEmpty] ���� ����Ʈ�� ����ִ��� üũ�մϴ�.\n");

	if (list->size > 0)
	{
		printf("[IsEmpty] ���� ����Ʈ�� ������� �ʽ��ϴ�.\n");
		return false;
	}

	printf("[IsEmpty] ���� ����Ʈ�� ����ֽ��ϴ�.\n");
	return true;
}

bool IsFull(ArrayList* list, IncDec incDec)
{
	printf("[IsFull] ���� ����Ʈ�� ũ�⸦ üũ�մϴ�.\n");

	if (incDec == IncDec::Inc)
	{
		printf("[IsFull] ���� ����Ʈ�� �߰��� �����ϹǷ� ũ�⸦ �߰��Ͽ� üũ�մϴ�.\n");
		if (list->size + 1 > MAX_SIZE)
			return false;
	}
	else if (incDec == IncDec::Dec)
	{
		printf("[IsFull] ���� ����Ʈ�� ������ �����ϹǷ� ũ�⸦ �����Ͽ� üũ�մϴ�.\n");
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
		printf("[IsFull] ���� ����Ʈ�� üũ�� �����Ͽ����ϴ�.\n");
		return false;
	}

	printf("[IsFull] ���� ����Ʈ�� ������ ���� �ʽ��ϴ�.\n");
	return true;
}

bool PrintList(ArrayList* list)
{
	printf("[PrintList] ���� ����Ʈ�� ����մϴ�.\n");

	if (IsEmpty(list))
	{
		printf("[PrintList] -> [IsEmpty] ���� ����Ʈ�� ��� �־� �����͸� ��� �Ҽ� �����ϴ�.\n");
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
		printf("[GetValue] ���� ����Ʈ�� ũ�⺸�� ū ��ġ�� �����͸� ��û�Ͽ����ϴ�. size = [%d], pos = [%d]\n", list->size, pos);
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
		printf("[ListValueMove] ���� ����Ʈ�� �߰�, ���� ������ �߸��Ͽ����ϴ�.\n");
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
		printf("[InsertFirst] ���� ����Ʈ ���� ó���� �����͸� �߰��Ͽ����ϴ�.\n");
		return true;
	}

	printf("[InsertFirst] ���� ����Ʈ�� ũ�⸦ �ʰ��Ͽ� ���� �Է� �Ҽ� �����ϴ�.\n");
	return false;
}

bool Insert(ArrayList* list, int pos, int value)
{
	IncDec inc = IncDec::Inc;
	if (IsFull(list, inc))
	{
		if (list->size < pos)
		{
			printf("[InsertFirst] ������ �����͸� �Է����� �ʾ� �����͸� �Է� �Ҽ� �����ϴ�.\n");
			return false;
		}
		else if(list->size > pos)
		{
			if (!ListValueMove(list, pos, inc))
				return false;
		}

		list->arr[pos - 1] = value;
		list->size = list->size + 1;
		printf("[InsertFirst] ���� ����Ʈ [%d]�� �����͸� �߰��Ͽ����ϴ�.\n", pos);
		return true;
	}

	printf("[InsertFirst] ���� ����Ʈ�� ũ�⸦ �ʰ��Ͽ� ���� �Է� �Ҽ� �����ϴ�.\n");
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
		printf("[InsertLast] ���� ����Ʈ ���� �������� �����͸� �߰��Ͽ����ϴ�.\n");
		return true;
	}

	printf("[InsertLast] ���� ����Ʈ�� ũ�⸦ �ʰ��Ͽ� ���� �Է� �Ҽ� �����ϴ�.\n");
	return false;
}

bool Delete(ArrayList* list, int pos)
{
	printf("[Remove] -> [IsEmpty] ���� ����Ʈ [%d]�� �����͸� �����մϴ�.\n", pos);

	if (IsEmpty(list))
	{
		printf("[Remove] -> [IsEmpty] ���� ����Ʈ�� ��� �־� �����͸� ���� �Ҽ� �����ϴ�.\n");
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
	printf("[Clear] ���� ����Ʈ�� �ʱ�ȭ �մϴ�.\n");
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