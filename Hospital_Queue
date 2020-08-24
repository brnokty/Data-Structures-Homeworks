#include <stdio.h>
#include <stdlib.h>

typedef struct node { //struct node type yapı olusturduk
	int hasta_no;
	char hastaAdi[20];
	char hastaSoyadi[20];
	float hasta_ucret;
	struct node * next;
	struct node * previous;
}nodeT;

void Ekle(nodeT **head, nodeT**tail)
{
	nodeT* NewNode = (nodeT*)malloc(sizeof(nodeT)); //dugum olusturduk

	printf(" Hasta No girin..");
	scanf("%d", &NewNode->hasta_no);
	printf(" Hasta Adi girin..");
	scanf("%s", &NewNode->hastaAdi);
	printf("Hasta Soyadi girin..");
	scanf("%s", &NewNode->hastaSoyadi);
	printf("Hastane ucreti girin..");
	scanf("%f", &NewNode->hasta_ucret);

	NewNode->next = NewNode;  //ilk ekleme yaptıgımız icin
	NewNode->previous = NewNode;
	if ((*head) == NULL) //bossa kuyrugun basıda o eleman sonuda
	{
		*head = NewNode; //yeni eklenicek sey hem
		*tail = NewNode;
	}
	else
	{
		NewNode->next = *head; //kuyrugun ilerisi bası tutucak
		NewNode->previous = *tail; //kuyrugun sonunu gosterir
		(*head)->previous = NewNode;
		(*tail)->next = NewNode;
		(*tail) = NewNode;
	}

}
void print(nodeT* head, nodeT* tail, int el) {

	if (head == NULL) return;
	nodeT* current = head; // Anlık pointeri en başa almak amaçlı //
	if (el != 0)
	{
		do
		{
			printf("\n HastaNo : %d\n", current->hasta_no);
			printf("\n HastaAdi : %s\n", current->hastaAdi);
			printf("\n HastaSoyadi: : %s\n", current->hastaSoyadi);
			printf("\n Hastaucret: : %f\n", current->hasta_ucret);
			current = current->next;
		} while (current != head);
	}


}

void del(nodeT* head, nodeT* tail) {  //bası ve sonu yolladık 

	if (head == tail)
	{
		head = NULL;
		tail = NULL;

	}
	else
	{
		if (head == NULL)return;
		nodeT* temp = (head);
		nodeT* current = (head);
		while (current->next != (head))
		{
			temp = current;
			current = current->next;
		}
		temp->next = (head);
		(tail) = temp;
		(head)->previous = (tail);
		free(current);
	}

	//*el--;

}

void First(nodeT** head )
{
	if (*head != NULL)
	{
		if ((*head)->next != NULL)
		{
			struct node* temp2 = *head;
			*head = (*head)->next;
			(*head)->previous->previous->next = (*head);
			(*head)->previous = (*head)->previous->previous;
			free(temp2);
		}
		else
		{
			free(*head);
			*head = NULL;
			(*head)->next = NULL;
			(*head)->previous = NULL;

		}
	}
	else
	{
		printf("\nThere is no item to be deleted, Please add item...");
	}
}


int main()
{
	nodeT *head = NULL;
	nodeT *tail = NULL;
	int el = 0;
	int c;
	while (1)
	{
		printf(" 1 - Hasta Ekle\n 2 - Hasta Sil \n 3 - Hastalari listele \n  Secim : ");
		scanf("%d", &c);

		switch (c)
		{
		case 1:
			Ekle(&head, &tail);
			el++;
			print(head, tail, el);
			break;
		case 2:
			//del(head, tail);
			First(&head);
			el--;

			print(head, tail, el);


			break;
		case 3:
			printf(" Hastalar \n");
			print(head, tail, el);
			break;
		}
	}
}
