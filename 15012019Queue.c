#include <stdio.h>
#include <stdlib.h>

typedef struct kuyruk {
	int data;
	struct kuyruk* next;
	struct kuyruk* prev;
}que;

void enqueue(que** h,que** t,int dat) {
	if (*h==NULL)
	{
		que* ek = (que*)malloc(sizeof(que));
		ek->data = dat;
		ek->next = NULL;
		ek->prev = NULL;
		*h = ek;
		*t = ek;
		return;
	}
	que* ek = (que*)malloc(sizeof(que));
	ek->data = dat;
	ek->next = NULL;
	ek->prev = *t;
	(*t)->next = ek;
	(*t) = ek;
}

void dequeue(que** h) {
	que* ybas = (*h)->next;
	free(*h);
	*h = ybas;
}

void goster(que* h) {
	printf("\n|Gise|");
	while (h !=NULL)
	{
		printf("<|%d|", h->data);
		h = h->next;
	}
	printf("\n\n");
}

int main() {
	int sec,dat;
	que* head = NULL;
	que* tail = NULL;
	do
	{
		printf("***MENU***\n1-Ekle\n2-Sil\n3-Cikis\nSecim..");
		scanf("%d", &sec);
		switch (sec)
		{
		case 1:
			//EKLE
			printf("Sayi : ");
			scanf("%d", &dat);
			enqueue(&head, &tail, dat);
			goster(head);
			break;
		case 2:
			//SİL
			dequeue(&head);
			goster(head);
			break;
		default:
			break;
		}

	} while (sec>0&&sec<3);


	return 0;
}
