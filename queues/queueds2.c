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
  if(front == NULL)
  {
    front = rear = new;
    return;
  }
  rear->next = new;
  rear = new;
}


int dequeue()
{
  struct node *temp = front;
  int data;
  if(temp == NULL)
  {
    printf("\nQueue is empty...\n\n");
    return 0;
  }
  data = temp->data;
  front = temp->next;
  free(temp);
  return(data);
}


void search(int k)
{
  struct node *temp = front;
  int flag = 0;
  if(temp == NULL)
  {
    printf("\nQueue is empty...\n\n");
    return;
  }
  while(temp != NULL && flag == 0)
  {
    if(temp->data == k)
    {
      flag = 1;
      printf("\n%d is found in the queue\n\n",k);
    }
    temp = temp->next;
  }
  if(flag == 0)
  {
    printf("\n%d is not found in the queue\n\n",k);
  }
}


void display()
{
  struct node *temp = front;
  if(temp == NULL)
  {
    printf("\nQueue is empty...\n\n");
    return;
  }
  printf("\nThe queue is : ");
  while(temp != NULL)
  {
    printf("%d  ",temp->data);
    temp = temp->next;
  }
  printf("\n\n");
}
