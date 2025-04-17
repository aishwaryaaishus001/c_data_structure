#include<stdio.h>
#include "bstds.c"
int main()
{
  int choice, n;
  do
  {
    printf("\n\n\nBST OPERATIONS\n**************\n");
    printf("1. Insertion\n");
    printf("2. Deletion\n");
    printf("3. Searching\n");
    printf("4. Inorder traversal\n");
    printf("5. Exit\n");
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
            printf("\nEnter the item to be deleted : ");
            scanf("%d",&n);
            delete(n);
            break;
      case 3 :
            printf("\nEnter the item to be deleted : ");
            scanf("%d",&n);
            search(n);
            break;
      case 4 :
            printf("\n");
            inorder(root);
            break;
      case 5 :
            printf("\nThank you...\n\n");
            break;
      default :
            printf("\nEnter a valid choice : ");
            break;
    }
  }while(choice != 5);
}
