#include<stdio.h>
#include<stdlib.h>
int main()
{
  int *a, i, n, k, u, l, mid, flag = 0, c = 0;
  printf("Enter how many numbers : ");
  scanf("%d",&n);
  a = malloc(n*sizeof(int));
  printf("Enter %d numbers in ascending order : ",n);
  for(i=0;i<n;i++)
  {
    scanf("%d",a+i);
  }
  printf("\nEnter the item to be searched : ");
  scanf("%d",&k);
  l = 0;
  u = n-1;
  while(flag == 0 && l<=u)
  {
    c++;
    mid = (l+u)/2;
    if(a[mid] == k)
    {
      flag = 1;
      printf("\n%d is found at location : %d\n",k,mid+1);
      printf("No.of comparisons done : %d\n\n",c);
    }
    else if(k < a[mid])
    {
      u = mid-1;
    }
    else
    {
      l = mid+1;
    }
  }
  if(flag == 0)
  {
    printf("\n%d is not found in the list\n\n",k);
  }
}
