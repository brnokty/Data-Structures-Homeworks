#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct  node* next;
}n;

void push(n** t,int dat) {
		n* ek = (n*)malloc(sizeof(n));		
		ek->data = dat;
		ek->next = *t;
		*t = ek;		
}

void pop(n** t) {
	n* gecici = (*t)->next;	
	free(*t);
	*t = gecici;
}

void goster(n* t) {
	printf("\n");
	while (t !=NULL)
	{
		printf("|%d|\n", t->data);
		t = t->next;
	}
	printf("\n");
}

int main() {
	n* top = NULL;
	int sec;
	int dat;
	do
	{
		printf("MENU\n1-Ekle\n2-Sil\n3-Goster\n4-Cikis\nsecim...");
		scanf("%d", &sec);
	switch (sec)
		{
		case 1://ekle						
			printf("Sayi..");
			scanf("%d", &dat);
			push(&top,dat);
			break;
		case 2://sil
			pop(&top);
			break;
		case 3://Göster			
			goster(top);
			break;
		default:
			break;
		}
	} while (sec>0&&sec<4);
	return 0;
}
