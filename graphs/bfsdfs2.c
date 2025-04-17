#include<stdio.h>
#include<stdlib.h>
int n, g[10][10], dfs_visited[10];

struct node
{
  int data;
  struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;
struct node *temp;

void enqueue(int k)
{
  struct node *new = malloc(sizeof(struct node));
  new->data = k;
  new->next = NULL;
  if(front == NULL)
  {
    front = rear = new;
    return;
  }
  rear->next = new;
  rear = new;
}

int isEmpty()
{
  return front == NULL;
}

int dequeue()
{
  int data;
  temp = front;
  data = temp->data;
  front = temp->next;
  free(temp);
  return data;
}


void bfs(int i)
{
  int visited[n], j, node;
  for(j=0;j<n;j++)
  {
    visited[j] = 0;
  }
  printf("%d  ",i);
  visited[i] = 1;
  enqueue(i);
  while(!isEmpty())
  {
    node = dequeue();
    for(j=0;j<n;j++)
    {
      if(g[node][j] == 1 && visited[j] == 0)
      {
        printf("%d  ",j);
        visited[j] = 1;
        enqueue(j);
      }
    }
  }
  printf("\n\n");
}

void dfs(int i)
{
  int j;
  printf("%d  ",i);
  dfs_visited[i] = 1;
  for(j=0;j<n;j++)
  {
    if(g[i][j] == 1 && dfs_visited[j] == 0)
      dfs(j);
  }
}

int main()
{
  int i,j,valid = 0;
  printf("Enter how many nodes : ");
  scanf("%d",&n);
  printf("Enter the adjacency matrix : ");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      scanf("%d",&g[i][j]);
      if(g[i][j] != 0 && g[i][j] != 1)
      {
        valid = 1;
      }
    }
  }
  if(valid == 1)
  {
    printf("\nInvalid adjacency matrix. Enter only 0 or 1...\n");
    exit(1);
  }
  printf("\n\nBFS Traversal\n*************\n");
  printf("Enter the starting vertex : ");
  scanf("%d",&i);
  bfs(i);
  printf("\nDFS Traversal\n*************\n");
  printf("Enter the starting vertex : ");
  scanf("%d",&i);
  dfs(i);
}
