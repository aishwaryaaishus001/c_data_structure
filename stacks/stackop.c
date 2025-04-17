#include<stdio.h>
#include "stackds.c"
int main()
{
  int choice, n;
  do
  {
    printf("\n\n****************\nSTACK OPERATIONS\n****************\n\n");
    printf("1.  PUSH\n");
    printf("2.  POP\n");
    printf("3.  TOP\n");
    printf("4.  DISPLAY\n");
    printf("5.  Exit\n");
    printf("          Enter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1 :
            printf("          Enter the item to be pushed :");
            scanf("%d",&n);
            push(n);
            break;
      case 2 :
            pop(n);
            break;
      case 3 :
            gettop();
            break;
      case 4 :
            display();
            break;
      case 5 :
            printf("          Thank you...\n\n");
            break;
      default :
            printf("          Enter a valid choice!!!\n\n");
    }
  }while(choice!=5);
}
