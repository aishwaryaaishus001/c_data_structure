#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *left;
  struct node *right;
};

struct node *root = NULL;

void insert(int k)
{
  struct node *new = malloc(sizeof(struct node)), *ptr = root, *pre;
  int flag = 0;
  new->data = k;
  new->left = NULL;
  new->right = NULL;
  while(ptr != NULL && flag == 0)
  {
    if(k < ptr->data)
    {
      pre = ptr;
      ptr = ptr->left;
    }
    else if(k > ptr->data)
    {
      pre = ptr;
      ptr = ptr->right;
    }
    else
    {
      flag = 1;
    }
  }
  if(flag == 0)
  {
    if(root == NULL)
    {
      root = new;
      return;
    }
    if(k < pre->data)
    {
      pre->left = new;
    }
    else
    {
      pre->right = new;
    }
  }
  else
  {
    printf("\n%d already exits\n\n",k);
  }
}

struct node* getSuccessor(struct node *p)
{
  struct node *succ;
  succ = p->right;
  while(succ != NULL)
  {
    succ = succ->left;
  }
  return succ;
}

void delete(int k)
{
  struct node *ptr = root, *parent;
  int flag = 0;
  if(ptr->left == NULL && ptr->right == NULL)
  {
    if(k == ptr->data)
    {
      free(ptr);
      root = NULL;
      return;
    }
    printf("\n%d does not exit in the tree\n\n",k);
    return;
  }
  while(ptr != NULL && flag == 0)
  {
    if(k < ptr->data)
    {
      parent = ptr;
      ptr = ptr->left;
    }
    else if(k > ptr->data)
    {
      parent = ptr;
      ptr = ptr->right;
    }
    else
    {
      flag = 1;
    }
  }
  if(flag == 0)
  {
    printf("\n%d does not exit\n\n",k);
    return;
  }

  if(ptr->left == NULL && ptr->right == NULL) //case 1
  {
    if(ptr == parent->left)
    {
      parent->left = NULL;
    }
    else
    {
      parent->right = NULL;
    }
  }

  else if(ptr->left != NULL && ptr->right != NULL) //case 3
  {
    /*if(ptr == root)
    {

    }*/
    struct node *successor;
    int data_successor;
    successor = getSuccessor(ptr);
    data_successor = successor->data;
    delete(data_successor);
    ptr->data = data_successor;
  }

  else //case 2
  {
    if(ptr = parent->left)
    {
      if(ptr->left == NULL)
      {
        parent->left = ptr->right;
      }
      else
      {
        parent->left = ptr->left;
      }
    }
    else
    {
      if(ptr->left == NULL)
      {
        parent->right = ptr->right;
      }
      else
      {
        parent->right = ptr->left;
      }
    }
  }
}


void search(int k)
{
  struct node *ptr = root;
  int flag = 0;
  while(ptr != NULL && flag == 0)
  {
    if(k < ptr->data)
    {
      ptr = ptr->left;
    }
    else if(k > ptr->data)
    {
      ptr = ptr->right;
    }
    else
    {
      flag = 1;
      printf("\n%d is found in the tree\n\n",k);
    }
  }
  if(flag == 0)
  {
    printf("\n%d does not exit in the tree\n\n",k);
  }
}

void inorder(struct node *root)
{
  if(root == NULL)
  {
    return;
  }
  inorder(root->left);
  printf("%d  ",root->data);
  inorder(root->right);
}
