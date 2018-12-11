#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


typedef int elemType;
typedef struct NodeList {

	int data;
	struct NodeList *next;
}Node;

void createStack(Node **pNode);
void destroyStack(Node *pNode);
void push(Node *pNode, int value);
void pop(Node *pNode);
void top(Node *pNode);
int isEmpty(Node *pNode);
int isFull(Node *pNode);
void printStack(Node *pNode);



void createStack(Node **pNode) {

	*pNode = (Node *)malloc(sizeof(Node));
	(*pNode)->next = NULL;

	/*if (*pNode == NULL) {
		printf("islev yurutme, bellek ayirma basarisiz oldu, tek basina baglanan listenin baslatilmasi basarisiz oldu\n");
	}
	else {

		(*pNode)->next = NULL;
		printf("islev yurutme, onde gelen dugumle tek baglantili liste baslatmasi\n");
	}*/
}


void push(Node *pNode, int value) {

	Node *pInsert;
	pInsert = (Node *)malloc(sizeof(Node));//pInsert == NULL  ?
	memset(pInsert, 0, sizeof(Node));
	pInsert->next = NULL;
	pInsert->data = value;

	pInsert->next = pNode->next;
	pNode->next = pInsert;
}


void pop(Node *pNode) {

	if (!isEmpty(pNode)) {

		Node *pNext;
		pNext = pNode->next;

		pNode->next = pNext->next;
		free(pNext);
		pNext = NULL;
	}
}


void printStack(Node *pNode) {

	if (!isEmpty(pNode)) {

		Node *pMove;
		pMove = pNode->next;
		while (pMove != NULL) {
			printf("%d ", pMove->data);
			pMove = pMove->next;
		}
		printf("\n");
	}
	else {
		printf("Yigin bos, yazdirma basarisiz\n");
	}
}


void destroyStack(Node *pNode) {

	Node *pMove;
	pMove = pNode->next;
	while (pMove != NULL) {

		pNode->next = pMove->next;
		free(pMove);
		pMove = pNode->next;
	}
}


int isEmpty(Node *pNode) {

	if (pNode->next == NULL) {
		return 1;
	}
	return 0;
}


int isFull(Node *pNode);


void top(Node *pNode) {
	if (!isEmpty(pNode)) {
		printf("Yiginin orta elemani %d\n", pNode->next->data);
	}
}

int main(int argc, const char * argv[]) {

	Node *pList;
	int sayi, ct = 1, sec, kez = 0;;
	
	createStack(&pList);

	while (ct)
	{
		if (kez>0)
		{
			printf("Devam etmek icin bir tusa bas\n");
			system("pause");
			system("cls");
		}
		kez++;
		printf("Menu\n1-Ekle\n2-Sil\n3-ust eleman\n4-Stacki yok et\n5-Cikis\nSecim..");
		scanf("%d", &sec);

		switch (sec)
		{
		case 1:
			
			printf("Bir sayi gir :");
			scanf("%d", &sayi);
			push(pList, sayi);
			printStack(pList);
			
			break;
		case 2:
			pop(pList);
			printStack(pList); 
			break;
		case 3:
			printStack(pList);
			top(pList);
			break;
		case 4:
			destroyStack(pList);
			printStack(pList);
			break;
		case 5:
			ct = 0;
			break;
		default:
			break;
		}
	}

	/*for (int i = 0; i < 5; i++)
	{
		printf("Bir sayi gir :");
		scanf("%d", &sayi);
		push(pList, sayi);
	}*/

	/*push(pList, 3);
	push(pList, 1);
	push(pList, 2); 
	push(pList, 4); 
	push(pList, 7);*/
	/*printStack(pList);*/

	/*pop(pList); 
	pop(pList);
	printf("icinden pop liste yigininin ogeleri: \n");
	printStack(pList);*/

	/*top(pList);

	destroyStack(pList);
	printStack(pList);*/

	system("pause");

	return 0;
}