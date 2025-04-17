#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

struct node
{
  int data;
  struct node *next;
};

struct node *head[SIZE], *ptr;

int divisionHash(int k)
{
  return k%SIZE;
}

void insert(int k)
{
  int i;
  struct node *new = malloc(sizeof(struct node));
  new->data = k;
  new->next = NULL;
  i = divisionHash(k);
  if(head[i] == NULL)
  {
    head[i] = new;
    return;
  }
  ptr = head[i];
  while(ptr->next != NULL)
  {
    ptr = ptr->next;
  }
  ptr->next = new;
}

void search(int k)
{
  int i, flag = 0;
  i = divisionHash(k);
  ptr = head[i];
  if(ptr == NULL)
  {
    printf("\n%d is not in the list\n\n",k);
    return;
  }
  while(ptr != NULL && flag ==0)
  {
    if(ptr->data == k)
    {
      flag = 1;
      printf("\n%d is found at location : %d\n\n",k,i);
    }
    ptr = ptr->next;
  }
  if(flag == 0)
  {
    printf("\n%d is not found in the list\n\n",k);
  }
}

void display()
{
  int  i;
  printf("\n\n");
  for(i=0;i<SIZE;i++)
  {
    ptr = head[i];
    if(ptr != NULL)
    {
      while(ptr != NULL)
      {
        if(ptr->next != NULL)
          printf("%d-->",ptr->data);
        else
          printf("%d\n",ptr->data);
        ptr = ptr->next;
      }
    }
  }
  printf("\n");
}

int main()
{
  int choice, n;
  do
  {
    printf("\n\n1. Insertion\n2. Search\n3. Display\n4. Exit\n\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1 :
            printf("\nEnter the item to be inserted : ");
            scanf("%d",&n);
            insert(n);
            break;
      case 2 :
            printf("\nEnter the item to be searched : ");
            scanf("%d",&n);
            search(n);
            break;
      case 3 :
            display();
            break;
      case 4 :
            printf("\nThank you....\n\n");
            break;
      default :
            printf("\nEnter a valid choice...\n\n");
    }
  }while(choice != 4);
}
