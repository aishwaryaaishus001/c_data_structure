#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;


//ENQUEUE
void enqueue(int n)
{
  struct node *new;
  new = (struct node *)malloc(sizeof(struct node));
  new->data = n;
  new->next = NULL;
  if(front==NULL && rear== NULL)
  {
    front = new;
    rear = new;
    return;
  }
  else
  {
    rear->next = new;
    rear = new;
  }
}


//DEQUEUE
void dequeue()
{
  struct node *temp;
  int data;
  if(front==NULL && rear== NULL)
  {
    printf("          Queue is empty!!!\n\n");
    return;
  }
  else if(front==rear)
  {
    data = front->data;
    front = rear = NULL;
    return;
  }
  else
  {
    temp = front;
    data = temp->data;
    front = temp->next;
    free(temp);
    printf("          Dequeued element : %d\n\n",data);
  }
}


//FRONT
void getfront()
{
  if(front==NULL)
  {
    printf("        Queue is empty!!!\n\n");
    return;
  }
  printf("          Front : %d\n\n",front->data);
}


//DISPLAY
void display()
{
  struct node *temp;
  temp = front;
  if(front==NULL && rear==NULL)
  {
    printf("        Queue is empty!!!\n\n");
    return;
  }
  printf("          The queue is : ");
  while(temp!=NULL)
  {
    printf("%d  ",temp->data);
    temp = temp->next;
  }
}
