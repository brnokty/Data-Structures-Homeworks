#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}n;

struct node* create()
{
	struct node* newN = (struct node*)malloc(sizeof(struct node));
	printf("bir sayi gir..");
	scanf("%d", &newN->data);
	newN->next = NULL;
	return newN;
};

void ekle(n* dugum, n** bas, n** son) {
	n* temp = create();

	if (*bas == NULL && *son == NULL)
	{
		*bas = temp;
		*son = temp;
		temp->next = NULL;
	}
	else
	{
		(*son)->next = temp;
		*son = temp;
		temp->next = NULL;
	}
}


void goster(n* dugum,n* bas) {
	if (bas == NULL)
	{
		return;
	}
	dugum = bas;
	printf("Bas");
	while (dugum->next != NULL)
	{
		printf("<-%d",dugum->data);
		dugum = dugum->next;
	}
	printf("<-%d\n", dugum->data);
}


void Sil(n** head,n** temp,n** tail)
{
	*temp = *head;
	if (head == NULL)
	{
		printf("\nQueue is empty, pls Enqueue");
		return;
	}
	if (*head == *tail)
	{
		*head = NULL;
		*tail = NULL;
		return;
	}
	*head = (*temp)->next;
	free(*temp);
}


int main() {
	int sec;
	n* bas = NULL;
	n* son = NULL;
	n* dugum = (n*)malloc(sizeof(n));
	do
	{
		printf("***MENU***\n1-Ekle\n2-Sil\n3-Cikis\nsecim..");
		scanf("%d", &sec);
		switch (sec)
		{
		case 1:
			//ekle
			ekle(dugum, &bas, &son);
			goster(dugum,bas);
			break;
		case 2:
			//sil
			Sil(&bas, dugum, &son);
			goster(dugum, bas);
			break;
		default:
			break;
		}
	} while (sec<3&&sec>0);


	return 0;
}
