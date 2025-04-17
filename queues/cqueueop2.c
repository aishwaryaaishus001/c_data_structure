#include<stdio.h>
#include "cqueueds2.c"
int main()
{
  int choice, n;
  do
  {
    printf("\n\nCIRCULAR QUEUE OPERATIONS\n**************************\n\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Search\n");
    printf("4. Display\n");
    printf("5. Exit\n");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1 :
          printf("\nEnter the item to be enqueued : ");
          scanf("%d",&n);
          enqueue(n);
          break;
      case 2 :
          n = dequeue();
          if(front != NULL)
          {
            printf("\nDequeued item : %d\n\n",n);
          }
          break;
      case 3 :
          printf("\nEnter the item to be searched : ");
          scanf("%d",&n);
          search(n);
          break;
      case 4 :
          display();
          break;
      case 5 :
          printf("\nThank you...\n\n");
          break;
      default :
          printf("\nEnter a valid choice...\n\n");
    }
  }while(choice != 5);
}
