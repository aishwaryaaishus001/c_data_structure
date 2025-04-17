#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};

struct node *header;


//TRAVERSAL
void traverse()
{
  struct node *temp;
  temp = header;
  if(temp==NULL)
  {
    printf("            The list is empty!\n\n");
    return;
  }
  printf("            The list : ");
  while(temp!=NULL)
  {
    printf("%d  ",temp->data);
    temp=temp->next;
  }
  printf("\n\n");
}


//INSERTION AT FRONT
void insertatfront(int n)
{
  struct node *new;
  new = (struct node *)malloc(sizeof(struct node));
  new->data = n;
  new->next = header;
  header = new;
}


//INSERTION AT END
void insertionatend(int n)
{
  struct node *new, *temp;
  temp = header;
  new = (struct node *)malloc(sizeof(struct node));
  new->data = n;
  new->next = NULL;
  if(temp==NULL)
  {
    header = new;
    return;
  }
  while(temp->next!=NULL)
  {
    temp = temp->next;
  }
  temp->next = new;
}


//INSERTION AFTER A NODE
void insertionafteranode(int n, int k)
{
  struct node *new, *temp;
  temp = header;
  while(temp!=NULL)
  {
    if(temp->data==k)
    {
      new = (struct node *)malloc(sizeof(struct node));
      new->data = n;
      new->next = temp->next;
      temp->next = new;
      return;
    }
    temp = temp->next;
  }
  printf("            The node with data %d is not found\n\n",k);
}


//DELETE FROM FRONT
void deletefromfront()
{
  struct node *new, *temp;
  temp = header;
  if(temp==NULL)
  {
    printf("            The list is empty!\n\n");
    return;
  }
  header = temp->next;
  free(temp);
}



//DELETE FROM FRONT
void deletefromend()
{
  struct node *new, *temp, *prev;
  temp = header;
  if(temp==NULL)
  {
    printf("            The list is empty!\n\n");
    return;
  }
  if(temp->next==NULL)
  {
    header = NULL;
    free(temp);
    return;
  }
  while(temp->next!=NULL)
  {
    prev = temp;
    temp = temp->next;
  }
  prev->next = NULL;
  free(temp);
}


//ELETION OF A SPECIFIC  NODE
void deleteanode(int n)
{
  struct node *prev, *temp;
  if(header==NULL)
  {
    printf("            The list is empty\n\n");
    return;
  }
  temp = header;
  if(temp->data==n)
  {
    header = temp->next;
    free(temp);
    return;
  }
  while(temp!=NULL)
  {
    if(temp->data==n)
    {
      prev->next = temp->next;
      free(temp);
      return;
    }
    else
    {
      prev = temp;
      temp = temp->next;
    }
  }
}


//SEARCHING
int search(int n)
{
  struct node *temp;
  int flag = 0;
  temp = header;
  while(temp!=NULL)
  {
    if(temp->data==n)
    {
      flag = 1;
      break;
    }
    else
    {
      temp = temp->next;
    }
  }
  return flag;
}
