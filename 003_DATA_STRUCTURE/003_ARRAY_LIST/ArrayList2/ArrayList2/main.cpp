#include <cstdio>
#include "ArrayList.h"

int main(void)
{
	/*** ArrayList�� ���� �� �ʱ�ȭ ***/
	ArrayList list;
	int data;
	Init(&list);

	/*** 5���� ������ ���� ***/
	Insert(&list, 11);
	Insert(&list, 11);
	Insert(&list, 22);
	Insert(&list, 22);
	Insert(&list, 33);

	/*** ����� �������� ��ü ��� ***/
	printf("���� �������� ��: %d \n", Count(&list));

	if (First(&list, data))    // ù ��° ������ ��ȸ
	{
		printf("%d ", data);

		while (Next(&list, data))    // �� ��° ������ ������ ��ȸ
			printf("%d ", data);
	}
	printf("\n\n");

	/*** ���� 22�� Ž���Ͽ� ��� ���� ***/
	if (First(&list, data))
	{
		if (data == 22)
			Remove(&list);

		while (Next(&list, data))
		{
			if (data == 22)
				Remove(&list);
		}
	}

	/*** ���� �� ����� ������ ��ü ��� ***/
	printf("���� �������� ��: %d \n", Count(&list));

	if (First(&list, data))
	{
		printf("%d ", data);

		while (Next(&list, data))
			printf("%d ", data);
	}
	printf("\n\n");
	return 0;
}