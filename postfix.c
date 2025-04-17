#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

struct node
{
  int data;
  struct node *next;
};

struct node *top = NULL;

void push(int k)
{
  struct node *new = malloc(sizeof(struct node));
  new->data = k;
  new->next = top;
  top = new;
}

int pop()
{
  int data;
  struct node *temp = top;
  data = temp->data;
  top = temp->next;
  free(temp);
  return data;
}

int main()
{
  char postfix[100], e;
  int i, a, b, r, key, c;
  printf("Enter the postfix expression : ");
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
  printf("\n\nResult = %d\n\n",r);
}
