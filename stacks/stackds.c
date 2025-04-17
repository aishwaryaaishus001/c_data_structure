#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};

struct node *top = NULL;


//PUSH
void push(int n)
{
  struct node *new;
  new = (struct node *)malloc(sizeof(struct node));
  if(new==NULL)
  {
    printf("          Stack Overflow!!!\n\n");
    return;
  }
  new->data = n;
  new->next = top;
  top = new;
}


//POP
void pop()
{
  struct node *temp;
  int data;
  temp = top;
  if(temp==NULL)
  {
    printf("          Stack is empty!!!\n\n");
    return;
  }
  data = temp->data;
  top = temp->next;
  free(temp);
  printf("          Poped item : %d\n\n",data);
}


//TOP
void gettop()
{
  if(top==NULL)
  {
    printf("          Stack is empty!!!\n\n");
    return;
  }
  printf("            Top : %d\n\n",top->data);
}


//DISPLAY
void display()
{
  struct node *temp;
  temp = top;
  if(temp==NULL)
  {
    printf("          Stack is empty!!!\n\n");
    return;
  }
  printf("          The stack is : ");
  while(temp!=NULL)
  {
    printf("%d  ",temp->data);
    temp = temp->next;
  }
  printf("\n\n");
}
