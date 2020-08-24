#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Düğümde ad soyad ve yaş değerlerini tutuyoruz.
struct node {
	char name[20];
	char secondName[20];
	int age;
	struct node *next;
};

//Head: Kuyruğun ilk elemanı
//Tail: kuyruğun son elemanı
//temp: fonksiyonlarda kullanabilmemiz için geçici değişken


//İsim, soyisim ve yaş için global değişkenler

//Bu fonksiyon düğüm oluşturur ve return eder
struct node* createPerson(char name[], char secondName[], int age)
{


	struct node* newPerson = (struct node*)malloc(sizeof(struct node));
	strcpy(newPerson->name, name);
	strcpy(newPerson->secondName, secondName);
	newPerson->age = age;
	newPerson->next = NULL;

	return newPerson;
};

//Kuyruğa eleman ekleme (enqueue)
void enQueuePerson(char name[], char secondName[], int age, struct node** head, struct node** tail)
{
	struct node* person = createPerson(name, secondName, age);
	//Eğer ilk eleman ve son eleman boş ise, yeni gelen eleman ilk elemandır
	if (*head == NULL && *tail == NULL)
	{
		*head = person;
		*tail = person;
	}
	else
	{
		//Sonuncunun arkasına eleman eklenir
		(*tail)->next = person;
		//Sonuncu eleman yeni eklenen eleman olacak şekilde güncellenir.
		*tail = person;

		
	}
}

//Kuyruktan eleman çıkaran fonksiyon
void deQueue(struct node* head, struct node* temp, struct node* tail)
{
	temp = head;
	//Eğer kuyruğun ilk elemanı yoksa kuyruk zaten boştur.
	if (head == NULL)
	{
		printf("\nQueue is empty, pls Enqueue");
		return;
	}

	//Eğer kuyruğun en arkasındaki kişi aynı zamanda en önündeki kişi ise kuyrukta 1 kişi var demektir
	//Bu yüzden o kişi de kuyruktan çıktığında kuyruğun hiçbir elemanı kalmaz.
	if (head == tail)
	{
		head = NULL;
		tail = NULL;
		return;
	}

	//Eğer yukarıdaki iki ihtimalde sağlanmazsa aşağıdaki kısım çalışır.
	//Mantık kuyruğun ikinci sırasındaki kişi artık birinci (head) sırasına gelmiş olur
	head = temp->next;
	//Free komutu ile düğümü yok ediyoruz
	free(temp);
}

//Sırada kimin olduğunu gösteren fonksiyon
struct node* whoNext(struct node* head)
{
	if (head == NULL)
	{
		printf("\nThere is no item in queue...");
		return 0;
	}

	return head;
}

//Kuyruğu yazdıran fonksiyon
void printQueue(struct node* head, struct node* temp)
{
	int i = 1;
	if (head == NULL)
	{
		return;
	}
	*temp = *head;
	while (temp->next != NULL)
	{
		printf("\n%d. Position => %s %s %d ", i, temp->name, temp->secondName, temp->age);
		*temp = *temp->next;
		i++;
	}
	printf("\n%d. Position => %s %s %d ", i, temp->name, temp->secondName, temp->age);
}


int main()
{
	struct node* head = NULL;
	struct node* tail = NULL;
	struct node* temp = NULL;
	char firstName[20], secondName[20];
	int age;

	int choise;
	while (1 == 1)
	{
		printf("\n 1- Enqueue ... ");
		printf("\n 2- Dequeue ... ");
		printf("\n 3- Who's next? ");
		printf("\nmake your choise ");
		scanf("%d", &choise);
		switch (choise)
		{
		case 1:
			printf("\n Enter First Name ... ");
			scanf("%s", &firstName);
			printf("\n Enter Second Name ... ");
			scanf("%s", &secondName);
			printf("\n Enter Age ... ");
			scanf("%d", &age);
			enQueuePerson(firstName, secondName, age, &head, &tail);
			printQueue(head, &temp);
			break;
		case 2:
			deQueue(&head, &temp, &tail);
			printQueue(head, &temp);
			break;
		case 3:
			temp = whoNext(head);
			printf("\n ****** \n");
			if (temp != NULL)
			{
				printf("%s %s %d", temp->name, temp->secondName, temp->age);
			}

			break;

		}
	}
	return 0;
}
