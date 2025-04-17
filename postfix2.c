#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *top = NULL;

void push(int i)
{
  struct node *new = malloc(sizeof(struct node));
  new->data = i;
  new->next = top;
  top = new;
}

int pop()
{
  struct node *temp = top;
  int data ;
  data = temp->data;
  top = temp->next;
  free(temp);
  return data;
}

int main()
{
  char postfix[100], e;
  int i, r, a, b, key, c;
  printf("\nEnter the postfix expression : ");
  fgets(postfix,100,stdin);
  for(i=0;i<strlen(postfix)-1;i++)
  {
    e = postfix[i];
    if(isdigit(e))
    {
      key = 0;
      while(e != ' ')
      {
        c = e - '0';
        key = (key*10)+c;
         e = postfix[++i];
      }
      push(key);
    }
    else
    {
      if(e != ' ')
      {
        a = pop();
        b = pop();
        switch(e)
        {
          case '+' :
                r = b+a;
                break;
          case '-' :
                r = b-a;
                break;
          case '*' :
                r = b*a;
                break;
          case '/' :
                r = b/a;
                break;
          case '^' :
                r = pow(b,a);
        }
        push(r);
      }
    }
  }
  printf("\n\nResult : %d\n\n",r);
}
