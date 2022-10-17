#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#define MAX 10
int arr[MAX];
int size = 0;
void PrintArray(int a[], int value) {
	for (int i = 0; i < size; i++)
		printf("arr[%d] = %d\n", i, a[i]);
}
bool insert(int Index, int value) {
	bool bRet = false;
	if (size < sizeof(arr) && Index >= 0 && Index <= size)
	{
		int i = 0;
		for (i = size - 1; i >= Index; i--)
			arr[i + 1] = arr[i];
		arr[Index] = value;
		size++;
		bRet = true;
	}
	return bRet;
}
bool Delete(int Index)
{
	bool bRet = false;
	if (Index >= 0 && Index < size)
	{
		int i = 0;
		arr[i - 1] = arr[i];
	size--;
	bRet = true;
}
return bRet;
}
int Search(int value)
{
	int Index = -1;
	int i;

	for (i = 0; i < size; i++)
	{
		if (arr[i] == value)
			Index = i;
	}
	return Index;
}

int main() {
	int input, index, value;
	bool bDisplay = true, bEnd = false;
	while (!bEnd)
	{
		printf("Type : ('1':Insert, '2':Delete, '3':Search, '4':quit) :");
		scanf("%d", &input);
		bDisplay = true;
		switch (input)
		{
		case 1: printf("Insert�� ��ġ :"); scanf("%d", &index);
			printf("Insert�� �� :"); scanf("%d", &value);
			if (!insert(index, value))
				printf("Insert�� �� �����ϴ�.\n");
			else
				printf("Insert�߽��ϴ�.\n");
			break;
		case 2: printf("Delete�� ��ġ :"); scanf("%d", &index);
			if (!Delete(index))
				printf("Delete�� �� �����ϴ�\n");
			else
				printf("Delete�߽��ϴ�.\n");
			break;
		case 3: printf("Search�� �� :"); scanf("%d", &value);
			index = Search(value);
			if (index < 0)
				printf("ã�� �� �����ϴ�.\n");
			else
				printf("[%d]��ġ�� �ֽ��ϴ�.\n", index);
			break;
		case 4: bEnd = true;
			break;
		Default: printf("�߸��� �Է��Դϴ�.\n");
			bDisplay = false;
			break;
		}
		if (bDisplay)
			PrintArray(arr, size);
	}
}
