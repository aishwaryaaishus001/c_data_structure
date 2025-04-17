#include<stdio.h>
#include "llistds2.c"
int main()
{
  int choice, n, k;
  do
  {
    printf("\n\nLINKED LIST OPERAIONS\n**********************\n\n");
    printf("1. Insertion at the front\n");
    printf("2. Insertion at the end\n");
    printf("3. Insertion after a node\n");
    printf("4. Deletion from the front\n");
    printf("5. Deletion from the end\n");
    printf("6. Deletion of a node\n");
    printf("7. Searching of a node\n");
    printf("8. Display\n");
    printf("9. Exit\n");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1 :
            printf("\nEnter the number to be inserted : ");
            scanf("%d",&n);
            insertatfront(n);
            break;
      case 2 :
            printf("\nEnter the number to be inserted : ");
            scanf("%d",&n);
            insertatend(n);
            break;
      case 3 :
            printf("\nEnter the number to be inserted : ");
            scanf("%d",&k);
            printf("\nEnter the item after which the item is to be inserted : ");
            scanf("%d",&n);
            insertafteranode(k,n);
            break;
      case 4 :
            n = deletefromfront();
            if(header != NULL)
            {
              printf("\nDeleted item : %d\n\n",n);
            }
            break;
      case 5 :
            n = deletefromend();
            if(header != NULL)
            {
              printf("\nDeleted item : %d\n\n",n);
            }
            break;
      case 6 :
            printf("\nEnter the item to be deleted : ");
            scanf("%d",&n);
            delete(n);
            break;
      case 7 :
            printf("\nEnter the item to be searched : ");
            scanf("%d",&n);
            search(n);
            break;
      case 8 :
            display();
            break;
      case 9 :
            printf("\nThank you...\n\n");
            break;
      default :
            printf("\nEnter a valid choice...\n\n");
    }
  }while(choice != 9);
}
