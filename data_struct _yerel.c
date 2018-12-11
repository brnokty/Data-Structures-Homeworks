#include <stdio.h>
#include <stdlib.h>

#define STACKLIMIT 5


int checkFull(int top)
{
	if (top >= STACKLIMIT - 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int checkEmpty(int  top)
{
	if (top < 0)
	{
		return 1;
	}
	else
	{
		return 0;

	}
}

void push(int item, int* top, int* stack[STACKLIMIT])
{
	int kontrol = checkFull(*top);
	if (kontrol == 0)
	{
		*top = *top + 1;
		stack[*top] = item;
	}
	else
	{
		printf("\nAkis uzerinde yigin!!...");
	}
}

void pop(int* top)
{
	int kontrol = checkEmpty(top);
	if (kontrol == 0)
	{
		*top=*top-1;
	}
	else
	{
		printf("\n Yýðýn zaten boþ bir þey yapamazsýn...");
	}
}

int peek(int top, int stack[STACKLIMIT])
{
	int kontrol = checkEmpty(top);
	if (kontrol == 1)
	{
		printf("\n Burada bir eþya yok...");
		return 0;
	}
	return stack[top];
}

void printStack(int top,int stack[STACKLIMIT])
{
	int i;
	printf("\nDip");
	
	for (int i = 0; i < top + 1; i++)
	{
		printf("<-%d", stack[i]);
	}
}

int main()
{
	int stack[STACKLIMIT - 1];

	int top = -1;

	int choise, item;
	int a;
	int b = 1;
	while (b == 1)
	{
		printf("\n 1-Push");
		printf("\n 2-Pop");
		printf("\n 3-Peek");
		printf("\n 4-Exit\nsecim...");

		scanf("%d", &choise);

		switch (choise)
		{
		case 1:
			printf("Girmek istediginiz elemani yazin...");
			scanf("%d", &item);
			push(item, &top, &stack);
			system("cls");
			printStack(top,stack);
			break;
		case 2:
			pop(&top);
			system("cls");
			printStack(top, stack);
			break;
		case 3:
			a = peek(top, stack);
			system("cls");
			printf("Yigininizin ust ogesi => %d", a);
			break;
		case 4:
			system("PAUSE");
			b = 0;
			break;
		}
	}
	return 0;
}
