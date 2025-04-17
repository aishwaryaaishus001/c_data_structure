#include<stdio.h>
#include<stdlib.h>
int main()
{
  int *a, i, j, n, temp, c = 0;
  printf("Enter how many numbers : ");
  scanf("%d",&n);
  a = malloc(n * sizeof(int));
  printf("Enter %d numbers : ",n);
  for(i=0;i<n;i++)
  {
    scanf("%d",a+i);
  }
  for(i=1;i<n;i++)
  {
    temp = a[i];
    j = i-1;
    while (j>=0 && a[j]>temp)
    {
      c++;
      a[j+1] = a[j];
      j--;
    }
    c++;
    a[j+1] = temp;
  }
  printf("\nNumbers after sorting : ");
  for(i=0;i<n;i++)
  {
    printf("%d  ",a[i]);
  }
  printf("\n\nNumber of comaparisons done : %d\n\n",c);
}
