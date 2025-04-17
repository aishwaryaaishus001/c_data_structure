#include<stdio.h>
#include<stdlib.h>
int main()
{
  int n, *a, i, j, temp, c = 0;
  printf("\nEnter how many numbers : ");
  scanf("%d",&n);
  a = malloc(n*sizeof(int));
  printf("\nEnter %d numbers : ",n);
  for(i=0;i<n;i++)
  {
    scanf("%d",a+i);
  }
  for(i=1;i<n;i++)
  {
    temp = a[i];
    j = i-1;
    while(j >= 0 && a[j] > temp)
    {
      c++;
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = temp;
  }
  printf("\nSorted array : ");
  for(i=0;i<n;i++)
  {
    printf("%d  ",a[i]);
  }
  printf("\n\nNo.of comparisons done : %d\n\n",c);
}
