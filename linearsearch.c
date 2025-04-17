#include<stdio.h>
#include<stdlib.h>
int main()
{
  int *a, n, i, k, flag = 0;
  printf("Enter how many numbers : ");
  scanf("%d",&n);
  a = malloc(n*sizeof(int));
  printf("Enter %d numbers : ",n);
  for(i=0;i<n;i++)
  {
    scanf("%d",a+i);
  }
  printf("\nEnter the item to be searched : ");
  scanf("%d",&k);
  for(i=0;i<n;i++)
  {
    if(k == a[i])
    {
      flag = 1;
      printf("\n%d is found at location : %d\n",k,i+1);
      printf("No.of comparisons done : %d\n\n",i+1);
      //break;
    }
  }
  if(i == n && flag == 0)
  {
    printf("\n%d is not found in the array\n",k);
    printf("No.of comparisons done : %d\n\n",n);
  }
}
