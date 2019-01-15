#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int data;
	struct node* next;
	struct node* prev;
}n;

void ekle(n** r,int veri) {
	n* ek = (n*)malloc(sizeof(n));
	if (*r==NULL)
	{
		ek->data = veri;
		ek->next = NULL;
		ek->prev = NULL;
		*r = ek;
		return;
	}
	n* temp = *r;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	ek->data = veri;
	ek->next = NULL;
	ek->prev = temp;
	temp->next = ek;
}

void sil(n** r) {
	n* temp = *r;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	n* gecici = temp->prev;
	free(temp);
	if (gecici==NULL)
	{
		*r = NULL;
	}
	else
	{
		gecici->next = NULL;
	}
	
}

void goster(n* r) {
	while (r != NULL) {
		printf("|%d|->",r->data);
		r = r->next;
	}
	printf("NULL\n");
}

int main() {
	int sec,sayi;
	n* root = NULL;
	do
	{
		printf("**MENU**\n1-Ekle\n2-Sil\n3-Cikis\n4-Secim..");
		scanf("%d", &sec);
		switch (sec)
		{
		case 1:
			//Ekle
			printf("Sayi :");
			scanf("%d", &sayi);
			ekle(&root, sayi);
			goster(root);
			break;
		case 2:
			//Sil
			sil(&root);
			goster(root);
			break;
		default:
			break;
		}

	} while (sec>0&&sec<3);


	return 0;
}
