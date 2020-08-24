#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
 
#define MAX 10
 
void Ekle(int [],int,int*);

void Goster(int [],int);
 
void Sil(int [],int*);
 
void main()
{
    int ITEM=0;
    int choice=0;
    int STACK[MAX],TOP;
    TOP=-1;
    
 
    while(1)
    {
        system("cls");
        printf("1: Goster\n2: Ekle (PUSH)\n3: Sil(POP))\n4: Cikis\nSecim..:");
        scanf("%d",&choice);
 
        switch(choice)
        {
            case 1:
                Goster(STACK,TOP);
                printf("Devam etmek icin bir tusa bas...");
                getch();
            break;
            case 2:
                printf("Bir sayi gir :");
                scanf("%d",&ITEM);
                Ekle(STACK,ITEM,&TOP);
            break;
            case 3:
                Sil(STACK,&TOP);
            break;
            case 4:
                exit(0);
            default:
            printf("\nGecersiz secim.");
            break;
        }
        
    }
    getch();
 
}
 
 
 
void Goster(int stack[],int top)
{
    int i=0;
    if(top==-1)
    {
        printf("Stack Bos .\n");
        return;
    }
 
    printf("Top -->%d ",stack[top]);
    for(i=top-1;i >=0;i--)
    {
        printf("-->%d",stack[i]);
    }
    printf("\n\n");
}
 
void Ekle(int stack[],int item,int* top)
{
    if(*top==MAX-1)
    {
        printf("\nStack dolu daha fazla eleman ekleyemezsin!\n");
        return;
    }
    (*top)++;
    stack[(*top)]=item;
}
 
 void Sil(int stack[],int* top)
{
    int deletedItem;
    if((*top)==-1)
    {
        printf("Stack Bos.\n");
        return;
    }
 
    deletedItem=stack[(*top)];
    (*top)--;
    printf("%d Silindi\n",deletedItem);
    return;
}
