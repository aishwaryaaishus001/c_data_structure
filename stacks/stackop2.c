#include<stdio.h>
#include "stackds2.c"
int main()
{
  int choice, n;
  do
  {
    printf("\nSTACK OPERATIONS\n****************\n\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Top\n");
    printf("4. Display\n");
    printf("5. Exit\n");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1 :
            printf("\nEnter item to be pushed : ");
            scanf("%d",&n);
            push(n);
            break;
      case 2 :
            n = pop();
            if(top != NULL)
            {
              printf("\nPopped item : %d\n\n",n);
            }
            break;
      case 3 :
            gettop();
            break;
      case 4 :
            display();
            break;
      case 5 :
            printf("\nThank you...\n\n");
            break;
      default :
            printf("\nEnter a valid choice...\n");
    }
  }while(choice!=5);
}
