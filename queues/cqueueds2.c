#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int k)
{
  struct node *new = malloc(sizeof(struct node));
  new->data = k;
  new->next = NULL;
  if(rear == NULL)
  {
    front = rear = new;
    rear->next = front;
    return;
  }
  rear->next = new;
  rear = new;
  rear->next = front;
}

int dequeue()
{
  struct node *temp = front;
  int data;
  if(temp == NULL)
  {
    printf("\nQueue is empty\n\n");
    return 0;
  }
  else if(front == rear)
  {
    data = temp->data;
    front = rear = NULL;
    free(temp);
    return data;
  }
  else
  {
    data = temp->data;
    front = temp->next;
    rear->next = front;
    free(temp);
    return data;
  }
}

void search(int k)
{
  struct node *temp = front;
  int flag = 0;
  if(temp == NULL)
  {
    printf("\nQueue is empty\n\n");
    return;
  }
  while(temp->next != front && flag == 0)
  {
    if(temp->data == k)
    {
      flag = 1;
      printf("\n%d is found in the circular queue\n\n",k);
      return;
    }
    temp = temp->next;
  }
  if(temp->data == k)
  {
    flag = 1;
    printf("\n%d is found in the circular queue\n\n",k);
  }
  if(flag == 0)
  {
    printf("\n%d is not found in the circular queue\n\n",k);
  }
}

void display()
{
  struct node *temp = front;
  if(temp == NULL)
  {
    printf("\nQueue is empty\n\n");
    return;
  }
  while(temp->next != front)
  {
    printf("%d  ",temp->data);
    temp = temp->next;
  }
  printf("%d\n\n",temp->data);
}
