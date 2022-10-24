#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#define MAX 10

typedef struct {
	int key;
	char grade;
} element;

int top = -1;
element stack[MAX];

void push(element item) {
	if (top >= MAX - 1) {
		printf("Stack is overflow !!\n");

	}
	else {
		top++;
		stack[top] = item;
	}
}
element pop() {
	if (top == -1)
	{
		printf("Stack is empty!!!");
	}
	else
		return stack[top--];

}

void main() {
	element data;
	bool bEnd = false;
	int i = 0, menu = 1;
	while (bEnd == false)
	{
		printf("번호입력 : 1 = push, 2 = pop, 3 = exit : ");
		scanf("%d", &menu);
		if (menu == 1) {
			printf("element 입력(번호_학점) :");
			scanf("%d %c", &data.key, &data.grade);
			push(data);

		}
		else if (menu == 2) {
			data = pop();
			printf("pop : %d %c\n", data.key, data.grade);
		}
		else if (menu == 3)
			bEnd = true;
	}
}