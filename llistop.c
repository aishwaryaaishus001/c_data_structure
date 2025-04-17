#include<stdio.h>
#include "linklistds.c"
int main()
{
  int choice,n,k;
  do
  {
    printf("\n\n**********************\nLINKED LIST OPERATIONS\n**********************\n\n");
    printf("1.  Traversal\n");
    printf("2.  Insertion at front\n");
    printf("3.  Insertion at end\n");
    printf("4.  Insertion after a node\n");
    printf("5.  Deletion from front\n");
    printf("6.  Deletion from end\n");
    printf("7.  Deletion of a specific node\n");
    printf("8.  Searching\n");
    printf("9.  Exit\n");
    printf("\n            Enter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1 :
            traverse();
            break;
      case 2 :
            printf("            Enter the number to be inserted : ");
            scanf("%d",&n);
            insertatfront(n);
            break;
      case 3 :
            printf("            Enter the number to be inserted : ");
            scanf("%d",&n);
            insertionatend(n);
            break;
      case 4 :
            printf("            Enter the number to be inserted : ");
            scanf("%d",&n);
            printf("            Enter the number after which the new number to be inserted : ");
            scanf("%d",&k);
            insertionafteranode(n,k);
            break;
      case 5 :
            deletefromfront();
            break;
      case 6 :
            deletefromend();
            break;
      case 7 :
            printf("            Enter the number to be deleted : ");
            scanf("%d",&n);
            deleteanode(n);
            break;
      case 8 :
            printf("            Enter the number to be searched : ");
            scanf("%d",&n);
            if(search(n)==1)
            {
              printf("            %d is found in the list\n\n",n);
            }
            else
            {
              printf("            %d is not found in the list\n\n",n);
            }
            break;
      case 9 :
            printf("            Thank you...\n\n");
            break;
      default :
            printf("            Enter a valid choice...\n\n");
    }
  }while(choice!=9);
}
