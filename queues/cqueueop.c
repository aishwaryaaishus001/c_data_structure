#include<stdio.h>
#include "cqueueds.c"
int main()
{
  int choice, n;
  do
  {
    printf("\n*************************\nCIRCULAR QUEUE OPERATIONS\n*************************\n\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    printf("\n");
    switch(choice)
    {
      case 1 :
            printf("Enter the number to be enqueued : ");
            scanf("%d",&n);
            enqueue(n);
            break;
      case 2 :
            n = dequeue();
            if(n)
            {
              printf("The dequeued item : %d\n",n);
            }
            break;
      case 3 :
            display();
            break;
      case 4 :
            printf("Thank you\n\n");
            break;
      default :
            printf("Enter a valid choice\n");
    }
    printf("\n\n");
  }while(choice != 4);
}
