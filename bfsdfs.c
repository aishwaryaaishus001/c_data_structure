#include<stdio.h>
#include<stdlib.h>
int g[10][10],n,dfs_visited[10];

struct node
{
  int data;
  struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int i)
{
  struct node *new;
  new = malloc(sizeof(struct node));
  new->data = i;
  new->next = NULL;
  if (front == NULL)
  {
    front = rear = new;
  }
  else
  {
    rear->next = new;
    rear = new;
  }
}

int dequeue()
{
  struct node *temp;
  int d;
  temp = front;
  d = temp->data;
  front = front->next;
  free(temp);
  return d;
}

int isEmpty()
{
  return front == NULL;
}

void bfs(int i)
{
  int visited[10], j, node;
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
}

void dfs(int i)
{
  int j;
  printf("%d  ",i);
  dfs_visited[i] = 1;
  for(j=0;j<n;j++)
  {
    if (g[i][j] == 1 && dfs_visited[j] == 0)
    {
      dfs(j);
    }
  }
}

int main()
{
  int i, j, valid = 0, s;
  printf("\nEnter how many nodes : ");
  scanf("%d",&n);
  printf("\nEnter the adjacency matrix : ");
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
  if (valid == 1)
  {
    printf("\nInvalid adjacency matrix. Enter only 1 or 0.\n");
    exit(1);
  }
  printf("\n\nBFS Traversal\n*************\n\n");
  printf("Where would you like to start the traversal : ");
  scanf("%d",&s);
  printf("\n");
  bfs(s);
  printf("\n_______________________________________________\n\nDFS Traversal\n*************\n\n");
  printf("Where would you like to start the traversal : ");
  scanf("%d",&s);
  printf("\n");
  dfs(s);
  printf("\n\n");
}
