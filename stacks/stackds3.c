#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *top = NULL;

void insert(int k)
{
  struct node *new;
  new = malloc(sizeof(struct node));
  new->data = k;
  new->next = NULL;
  if(top == NULL)
  {
    top = new;
    return;
  }
  new->next = top;
  top = new;
}

int delete()
{
  struct node *temp = top;
  int data;
  if(temp == NULL)
  {
    printf("\nStack is empty\n\n");
    return 0;
  }
  data = temp->data;
  top = temp->next;
  free(temp);
  return data;
}

void search(int k)
{
  struct node *temp = top;
  int flag = 0;
  if(temp == NULL)
  {
    printf("\nStack is empty\n\n");
    return;
  }
  while(temp != NULL && flag == 0)
  {
    if(temp->data == k)
    {
      flag = 1;
      printf("\n%d is found in the stack\n\n",k);
      return;
    }
    temp = temp->next;
  }
  if(flag == 0)
  {
    printf("\n%d is not found in the stack\n\n",k);
  }
}

int getTop()
{
  if(top == NULL)
  {
    printf("\nStack is empty\n\n");
    return 0;
  }
  return top->data;
}

void display()
{
  struct node *temp = top;
  if(temp == NULL)
  {
    printf("\nStack is empty\n\n");
    return;
  }
  printf("\n\nThe Stack is : ");
  while(temp != NULL)
  {
    printf("%d  ",temp->data);
    temp = temp->next;
  }
  printf("\n\n");
}
