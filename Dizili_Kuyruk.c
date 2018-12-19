#include <stdio.h>

#define QUEUESIZE 5

void Ekle(int item, int *front, int *Queue[QUEUESIZE - 1], int* rear)
{
	if (*rear > 4)
	{
		printf("\n**********");
		printf("\nKuyruk Dolu");
	}
	else
	{
		if (*front == -1)
		{
			*front = *front + 1;
		}
		*rear = *rear + 1;
		Queue[*rear] = item;
	}
}

void Sil(int* front, int* rear)
{
	if (*front == -1 || *front > *rear)
	{
		printf("\n**********");
		printf("\nKuyruk boş");
	}
	else
	{
		*front = *front + 1;
	}

}

void Goster(int front,int Queue[QUEUESIZE - 1],int rear)
{
	int i;
	if (front == -1 || front > rear)
	{
		printf("\n**********");
		printf("\nKuyruk boş");
	}
	else
	{
		for (i = rear; i >= front; i--)
		{
			printf("%d->", Queue[i]);
		}
		printf("Bas\n");
	}
}
int main()
{
	int sec, item;
	int Queue[QUEUESIZE - 1];
	int front = -1, rear = -1;

	do
	{
		printf("**MENU**\n1-Ekle\n2-Sil\n3-Cik\nSecim..");
		scanf("%d", &sec);

		switch (sec)
		{
		case 1:
			printf("bir sayi gir..");
			scanf("%d", &item);
			Ekle(item, &front,&Queue, &rear);
			Goster(front,Queue,rear);
			break;
		case 2:
			Sil(&front,&rear);
			Goster(front, Queue, rear);
			break;
		}

	} while (sec < 3 && sec>0);
	return 0;
}
