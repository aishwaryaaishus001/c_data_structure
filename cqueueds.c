#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int n)
{
  struct node *new;
  new = (struct node *)malloc(sizeof(struct node));
  new->data = n;
  new->next = NULL;
  if(rear == NULL)
  {
    front = rear = new;
    rear->next = front;
  }
  else
  {
    rear->next = new;
    rear = new;
    rear->next = front;
  }
}

int dequeue()
{
  struct node *temp;
  int data;
  temp = front;
  if(rear == NULL)
  {
    printf("Queue is empty\n\n");
    return 0;
  }
  else if(front == rear)
  {
    front = rear = NULL;
    data = temp->data;
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

void display()
{
  struct node *temp;
  temp = front;
  if(front == NULL)
  {
    printf("Queue is empty\n\n");
  }
  else
  {
    printf("The queue is : ");
    do
    {
      printf("%d  ",temp->data);
      temp = temp->next;
    }while(temp != front);
  }
  printf("\n");
}
