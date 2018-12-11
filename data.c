#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef int elemType;
typedef struct NodeList {

	int element;
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


//???????????
void createStack(Node **pNode) {

	*pNode = (Node *)malloc(sizeof(Node));
	if (*pNode == NULL) {
		printf("%sislev yurutme, bellek ayirma basarisiz oldu, tek basina baglanan listenin baslatilmasi basarisiz oldu\n", __FUNCTION__);
	}
	else {

		(*pNode)->next = NULL;
		printf("%sislev yurutme, onde gelen dugumle tek baglantili liste baslatmasi\n", __FUNCTION__);
	}
}

//??????
void push(Node *pNode, int value) {

	Node *pInsert;
	pInsert = (Node *)malloc(sizeof(Node));//???????????? pInsert == NULL  ?
	memset(pInsert, 0, sizeof(Node));
	pInsert->next = NULL;
	pInsert->element = value;

	pInsert->next = pNode->next;
	pNode->next = pInsert;
}

//??????
void pop(Node *pNode) {

	if (!isEmpty(pNode)) {

		Node *pNext;
		pNext = pNode->next;

		pNode->next = pNext->next;
		free(pNext);
		pNext = NULL;
	}
}

//?????
void printStack(Node *pNode) {

	if (!isEmpty(pNode)) {

		Node *pMove;
		pMove = pNode->next;
		while (pMove != NULL) {
			printf("%d ", pMove->element);
			pMove = pMove->next;
		}
		printf("\n");
	}
	else {
		printf("Yigin bos, yazdirma basarisiz\n");
	}
}

//?????
void destroyStack(Node *pNode) {

	Node *pMove;
	pMove = pNode->next;
	while (pMove != NULL) {

		pNode->next = pMove->next;
		free(pMove);
		pMove = pNode->next;
	}
}

//???????
int isEmpty(Node *pNode) {
	/**
	 *  ???????????,??????
	 */
	if (pNode->next == NULL) {
		return 1;
	}
	return 0;
}

//???????,??????????,?????????,??????????
int isFull(Node *pNode);

//?????
void top(Node *pNode) {
	if (!isEmpty(pNode)) {
		printf("Yiginin ust elemani %d\n", pNode->next->element);
	}
}

int main(int argc, const char * argv[]) {

	Node *pList;
	createStack(&pList);

	push(pList, 3); push(pList, 1); push(pList, 9); push(pList, 4); push(pList, 7);
	printStack(pList);

	pop(pList); pop(pList);
	printf("icinden pop liste yigininin ogeleri: \n");
	printStack(pList);

	top(pList);

	destroyStack(pList);
	printStack(pList);

	system("pause");

	return 0;
}