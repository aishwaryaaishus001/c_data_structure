#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *header = NULL;

void insertatfront(int k)
{
  struct node *new = malloc(sizeof(struct node)), *temp = header;
  new->data = k;
  new->next = NULL;
  new->next = temp;
  header = new;
}

void insertatend(int k)
{
  struct node *new = malloc(sizeof(struct node)), *temp = header;
  new->data = k;
  new->next = NULL;
  if(temp == NULL)
  {
    header = new;
    return;
  }
  while(temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = new;
}

void insertafteranode(int k, int n)
{
  struct node *new = malloc(sizeof(struct node)), *temp = header;
  int flag = 0;
  new->data = k;
  new->next = NULL;
  if(temp == NULL)
  {
    printf("\n%d does not exit in the list\n\n",n);
    return;
  }
  while(temp != NULL && flag == 0)
  {
    if(temp->data == n)
    {
      flag = 1;
      break;
    }
    temp = temp->next;
  }
  if(flag == 0)
  {
    printf("\n%d does not exit in the list\n\n",n);
    return;
  }
  new->next = temp->next;
  temp->next = new;
}

int deletefromfront()
{
  struct node *temp = header;
  int data;
  if(temp == NULL)
  {
    printf("\nThe list is empty\n\n");
    return 0;
  }
  data = temp->data;
  header = temp->next;
  free(temp);
  return data;
}

int deletefromend()
{
  struct node *temp = header, *prev;
  int data;
  if(temp == NULL)
  {
    printf("\nThe list is empty\n\n");
    return 0;
  }
  if(temp->next == NULL)
  {
    data = temp->data;
    header = NULL;
    free(temp);
    return data;
  }
  while(temp->next != NULL)
  {
    prev = temp;
    temp = temp->next;
  }
  data = temp->data;
  prev->next = NULL;
  free(temp);
  return data;
}

void delete(int k)
{
  struct node *temp = header, *prev;
  if(temp == NULL)
  {
    printf("\nThe list is empty\n\n");
    return;
  }
  if(temp->next == NULL && temp->data == k)
  {
    free(temp);
    header = NULL;
    return;
  }
  while(temp != NULL)
  {
    if(temp->data == k)
    {
      prev->next = temp->next;
      free(temp);
      return;
    }
    prev = temp;
    temp = temp->next;
  }
  if(temp == NULL)
  {
    printf("\n%d does not exit in the list\n\n",k);
  }
}

void search(int k)
{
  struct node *temp = header;
  while(temp != NULL)
  {
    if(temp->data == k)
    {
      printf("\n%d is found in the list\n\n",k);
      return;
    }
    temp = temp->next;
  }
  printf("\n%d does not exit in the list\n\n",k);
}

void display()
{
  struct node *temp = header;
  if(temp == NULL)
  {
    printf("\nThe list is empty\n\n");
    return;
  }
  printf("\n");
  while(temp != NULL)
  {
    printf("%d  ",temp->data);
    temp = temp->next;
  }
  printf("\n\n");
}
