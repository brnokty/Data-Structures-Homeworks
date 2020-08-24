#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int hasta_no;
	char name[20];
	struct node * next;
	struct node * previous;
}nodeT;

void Ekle(nodeT **head, nodeT**tail)
{
	nodeT* NewNode = (nodeT*)malloc(sizeof(nodeT));
	
	printf(" Hasta No girin..");
	scanf("%d",&NewNode->hasta_no);
	printf(" Hasta Adi girin..");
	scanf("%s",&NewNode->name);
	NewNode->next = NewNode;
	NewNode->previous = NewNode;
	if ((*head) == NULL)
	{
		*head = NewNode;
		*tail = NewNode;
	}
	else
	{
		NewNode->next = *head;
		NewNode->previous = *tail;
		(*head)->previous = NewNode;
		(*tail)->next = NewNode;
		(*head) = NewNode;
	}
	
}
void print(nodeT* head,nodeT* tail,int el) {
	
		if (head == NULL) return;
		nodeT* current = head; // Anlık pointeri en başa almak amaçlı //
		if (el!=0)
		{
			do
			{
				printf("%d-", current->hasta_no);
				printf("%s\n", current->name);
				current = current->next;
			} while (current != head);
		}
			
		
}

void del(nodeT* head, nodeT* tail) {

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

int main()
{
	nodeT *head = NULL;
	nodeT *tail = NULL;
	int el = 0;
	int c;
	while (1)
	{
		printf(" 1 - Hasta Ekle\n 2 - Hasta Sil \n 3 - Hastalari listele \n Secim : ");
		scanf("%d", &c);
		
		switch (c)
		{
		case 1: 
			Ekle(&head, &tail);
			el++;
			print(head,tail,el);
			break;
		case 2:
			del(head, tail);
			el--;
			
				print(head,tail,el);
			
			
			break;
		case 3: 
			printf(" Hastalar \n");
			print(head,tail,el); 
			break;
		}
	}
}
