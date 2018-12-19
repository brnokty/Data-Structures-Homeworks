#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// _CRT_SECURE_NO_WARNINGS scanf hatası kaldırmak için


typedef struct NodeList {

	char baslik[20]; //kitabın özellikleri burada olacak
	char yazar[20];
	char yayimci[20];
	int isbn;
	int ucret;
	struct NodeList *next;
	struct NodeList *prev;
}Node;

void createStack(Node **pNode) {

	*pNode = (Node *)malloc(sizeof(Node)); //başlangıçta düğüm oluşturmam için stack oluştur fonksiyonu
	(*pNode)->next = NULL; //başlangıçta prev ve next NULL olmalıkı konumumu bileyim
	(*pNode)->prev = NULL;

}
void printstack(Node *pNode) { //stack taki verileri yazdırma fonksiyonum
	Node *pMove; //düğümde diğer pointerım yernine dolaşacak olan pointer diğer pointerın point ettiği adres değişmesin diye
	pMove = pNode->next; //düğümün bir ilerisi Null mı dye kontrol için kolaylık olsun diye direk düğümün nextini point ediyoruz
	while (pMove != NULL) { //boşmu kontrolü

		printf("\nBaslik  : %s ", pMove->baslik); //stackın içinden göstermek istediğim veriler
		printf("\nYazar   : %s ", pMove->yazar);
		printf("\nyayimci : %s ", pMove->yayimci);
		printf("\nisbn    : %d ", pMove->isbn);
		printf("\nucret : %d\n ", pMove->ucret);
		pMove = pMove->next;
	}
	printf("\n");


}

void pop(Node *pNode) {

		Node *pNext; // yığında benim yerime hareket edecek pointer
		pNext = pNode->next; //düğümün nextini tutmasını sağlıyoruz
		pNode->next = pNext->next; //artık düğümümüz silineceği için  next düğümünün nextini düğümümüze yerleştiriyoruz yani normal düğümün nextinin nextini düğüme düğümün nextine tanımlamış oluyoruz
		free(pNext); //bellekten siliyoruz
		pNext = NULL; //ve alanı null olarak tanımlıyoruz
	
}


void push(Node *pNode) {

	Node *pInsert; //ekleme işlemi için kullanacağım düğüm
	pInsert = (Node *)malloc(sizeof(Node)); //bellekte yeni düğüme alan açıyorum
	pInsert->next = NULL; //ve nextini null yapıyorum
	printf("\nbaslik girin..."); //verilerimi alıp stackteki yerlerine yerleştiriyorum
	scanf("%s", &pInsert->baslik);
	printf("Yazar ismi girin...");
	scanf("%s", &pInsert->yazar);
	printf("Yayimci girin...");
	scanf("%s", &pInsert->yayimci);
	printf("isbn girin...");
	scanf("%d", &pInsert->isbn);
	printf("ucret girin...");
	scanf("%d", &pInsert->ucret);

	pInsert->next = pNode->next; //yeni düğümü kendi düğümümüme eklemek için yeni düğümü kendi düğümümün bir önüne koyuyorum
	pNode->next = pInsert; //arkadan benim düğümümünde diğer düğümü görmesini sağlıyorum
	pInsert->prev = pNode; //previni de bir önce gelemsi gereken kendi düğümüme eşitliyorum
}

int main() {

	Node *pList; //düğümümü oluşturdum
	int  sec;

	createStack(&pList); //stack yarrattım

	do //sonsuz döngü için do while kullandım
	{
		printf("***Menu***\n1- Kitap Ekle\n2-Kitap Sil\n3-Programdan Cik\nSecim.."); //menümü oluşturdum
		scanf("%d", &sec); 

		switch (sec) //switchhle yapmak istedğimim işelmi seçtirdim
		{
		case 1:
			push(pList); //önce ekleme yapıp 
			printstack(pList); //sonra düğümü yazdırdım
			break;
		case 2:
			pop(pList);    //önce sildirdim
			printstack(pList); // sonra tekrar yazdırdım
			break;
		default:
			break;
		}

	} while (sec>0&&sec<3); //istedğim aralıklardamı girdi diye kontrol ettirmek için 1 veya 2 girerse switchte caselerine gidicekler ama farklı bişey girerlerse program sona erecek

	return 0;
}
