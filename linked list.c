#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}n;



void ekle(n** r) {
	int dat;
	if ((*r)==NULL)
	{
		n* temp= (n*)malloc(sizeof(n));
		
		temp->next = NULL;
		printf("Sayi...");
		scanf("%d", &dat);
		temp->data = dat;
		(*r) = temp;
		return;
	}
	n* t = (*r);
	while (t->next != NULL)
	{
		t = t->next;
	}
	n* temp = (n*)malloc(sizeof(n));
	printf("Sayi...");
	scanf("%d", &dat);
	temp->data = dat;
	temp->next = NULL;
	t->next = temp;
}

void goster(n* r) {

	while (r !=NULL)
	{
		printf("%d->",r->data);
		r = r->next;
	}
	printf("NULL\n");
}

int main() {
	n* root = NULL;
	int sec;

	do
	{
		printf("\nMENU\n1-Ekle\n2-Goster\n3-Cikis\nSecim...");
		scanf("%d", &sec);
		switch (sec)
		{
		case 1:
			//ekle
			ekle(&root);
			break;
		case 2:
			//göster
			goster(root);
			break;
		default:
			break;
		}
	} while (sec>0&&sec<3);


	return 0;
}
