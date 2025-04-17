#include<stdio.h>
#include "queueds.c"
int main()
{
  int choice,n;
  do
  {
    printf("\n\n****************\nQUEUE OPERATIONS\n****************\n\n");
    printf("1.  ENQUEUE\n");
    printf("2.  DEQUEUE\n");
    printf("3.  FRONT\n");
    printf("4.  DISPLAY\n");
    printf("5.  Exit\n");
    printf("          Enter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1 :
            printf("          Enter the item to be enqueued :");
            scanf("%d",&n);
            enqueue(n);
            break;
      case 2 :
            dequeue(n);
            break;
      case 3 :
            getfront();
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
