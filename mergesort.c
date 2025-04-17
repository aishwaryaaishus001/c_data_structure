#include<stdio.h>
#include<stdlib.h>
int n, c;

void merge(int *a,int lb,int mid,int ub)
{
  int i, j, k, *b;
  i = lb;
  j = mid+1;
  k = lb;
  b = malloc(n*sizeof(int));
  while(i <= mid && j <= ub)
  {
    c++;
    if(a[i] <= a[j])
    {
      b[k] = a[i];
      i++;
    }
    else
    {
      b[k] = a[j];
      j++;
    }
    k++;
  }
  while(i<=mid)
  {
    b[k] = a[i];
    i++;
    k++;
  }
  while(j<=ub)
  {
    b[k] = a[j];
    j++;
    k++;
  }
  for(i=lb;i<=ub;i++)
  {
    a[i] = b[i];
  }
}

void mergesort(int *a,int lb,int ub)
{
  int mid;
  if(lb<ub)
  {
    mid = (lb + ub) / 2;
    mergesort(a,lb,mid);
    mergesort(a,mid+1,ub);
    merge(a,lb,mid,ub);
  }
}

int main()
{
  printf("\n\nn = %d\nc = %d\n\n",n,c);
  int *a, i;
  printf("Enter how many numbers : ");
  scanf("%d",&n);
  a = malloc(n*sizeof(int));
  printf("Enter %d numbers : ",n);
  for(i=0;i<n;i++)
  {
    scanf("%d",a+i);
  }
  mergesort(a,0,n-1);
  printf("\nSorted array : ");
  for(i=0;i<n;i++)
  {
    printf("%d  ",a[i]);
  }
  printf("\nNo.of comparisons done : %d\n\n",c);
}
