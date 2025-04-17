#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};

struct node *top = NULL;

void push(int k)
{
  struct node *new;
  new = malloc(sizeof(struct node));
  if(new == NULL)
  {
    printf("\nStack overflow\n\n");
    return;
  }
  new->data = k;
  new->next = top;
  top = new;
}

int pop()
{
  struct node *temp;
  int d;
  temp = top;
  if(temp ==NULL)
  {
    printf("\nStack is empty\n\n");
    return 'e';
  }
  top = temp->next;
  d = temp->data;
  free(temp);
  return d;
}

void gettop()
{
  if(top == NULL)
  {
    printf("\nStack is empty\n\n");
    return;
  }
  printf("Top : %d\n\n",top->data);
}

void display()
{
  struct node *temp;
  temp = top;
  if(top == NULL)
  {
    printf("\nStack is empty\n\n");
    return;
  }
  while(temp != NULL)
  {
    printf("%d  ",temp->data);
    temp = temp->next;
  }
  printf("\n\n");
}
