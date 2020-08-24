#include <stdio.h>
#include <stdlib.h>



typedef struct node {
	char barkod[20];
	char urunadi[20];
	float ucret;
	struct node * next;
	struct node * prev;
}nodeT;

void Add(nodeT **head, nodeT **tail) {
	nodeT * newnode = (nodeT*)malloc(sizeof(nodeT));
	printf("Barkod Girin..");
	scanf("%s", newnode->barkod);

	printf("Urun Adi Girin..");
	scanf("%s", newnode->urunadi);

	printf("Ucret Girin..");
	scanf("%f", &newnode->ucret);
	
	newnode->next = newnode;
	newnode->prev = newnode;
	if (*head == NULL)
	{
		*head = newnode;
		*tail = newnode;
	}
	else
	{
		(*tail)->next = newnode;
		newnode->next = *head;
		newnode->prev = *tail;
		*tail = newnode;
		(*head)->prev = *tail;
	}
}
void display(nodeT *head) {
	if (head == NULL) return;
	nodeT *current = head; // Anlık pointeri en başa almak amaçlı //
	do
	{
		printf("\nBarkod :%s\n", current->barkod);
		printf("Urun Adi :%s\n", current->urunadi);
		printf("Ucret :%f\n", current->ucret);

		current = current->next;
	} while (current != head);
}

void sil(nodeT** head, nodeT** tail) {
	if (*head == NULL)return;
	nodeT* temp = (*head);
	nodeT* current = (*head);
	while (current->next != (*head))
	{
		temp = current;
		current = current->next;
	}
	temp->next = (*head);
	(*tail) = temp;
	(*head)->prev = (*tail);
	free(current);

}


int main() {
	nodeT * head = NULL;
	nodeT * tail = NULL;
	int sec;
	do
	{
		printf("\n**MENU**\n1-ekle\n2-sil\n3-cik\nsecim..");
		scanf("%d", &sec);
		switch (sec)
		{
		case 1:
			
			Add(&head, &tail);
			system("cls");
			display(head);
			break;
		case 2:
			
			sil(&head, &tail);
			system("cls");
			display(head);

			break;
		case 3:

			break;

		default:
			break;
		}

	} while (sec>0&&sec < 4);
	return 0;

}
