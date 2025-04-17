#include<stdio.h>
#include "stackds3.c"
int main()
{
  int choice , n;
  do
  {
    printf("\n\nSTACK OPERATIONS\n****************\n\n");
    printf("1. Insertion\n");
    printf("2. Deletion\n");
    printf("3. Search\n");
    printf("4. Top\n");
    printf("5. Display\n");
    printf("6. Exit\n");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1 :
            printf("\nEnter the item to be inserted : ");
            scanf("%d",&n);
            insert(n);
            break;
      case 2 :
            n = delete();
            if(top != NULL)
              printf("\nDeleted item : %d\n\n",n);
            break;
      case 3 :
            printf("\nEnter the item to be searched : ");
            scanf("%d",&n);
            search(n);
            break;
      case 4 :
            n = getTop();
            printf("\nTop : %d\n\n",n);
            break;
      case 5 :
            display();
            break;
      case 6 :
            printf("\nThank you...\n\n");
            break;
      default :
            printf("\nEnte a valid choice...\n\n");
    }
  }while(choice != 6);
}
