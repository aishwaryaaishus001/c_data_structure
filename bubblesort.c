#include<stdio.h>
#include<stdlib.h>
int main()
{
  int *a, n, i, j, temp, c = 0;
  printf("\nEnter how many numbers : ");
  scanf("%d",&n);
  a = malloc(n*sizeof(int));
  printf("\nEnter %d numbers : ",n);
  for(i=0;i<n;i++)
  {
    scanf("%d",a+i);
  }
  for(i=0;i<=n-2;i++)
  {
    for(j=0;j<=n-i-2;j++)
    {
      c++;
      if(a[j] > a[j+1])
      {
        temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
      }
    }
  }

  printf("\nSorted array : ");
  for(i=0;i<n;i++)
  {
    printf("%d  ",a[i]);
  }
  printf("\nNo.of comparisons : %d\n\n",c);
}
