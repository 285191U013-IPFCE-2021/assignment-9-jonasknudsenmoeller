/*
 * Search an expression using DFS.
 */

#include <stdio.h>		/* scanf, printf */
#include <stdlib.h>		/* abort */
#include <stdbool.h>		/* bool, true, false */
#include <assert.h> // assert 
#include "dfs.h" 


void DFT (node * root)
{
   // initialising 
  stack *topp = NULL;
  node *temp = NULL;

  topp = push(topp, root); // topp is set to topp of our tree

  
  while (isEmpty(topp) == false) //while stack is not empty
  {
    temp = top(topp); // temporary node-pointer is set to point to current top
    print_node(temp);

    // pop top of stack and assess left- and right-child and then push them back to stack if they aren't NULL and has not yet been visited.
    topp = pop(topp);
    if(temp -> rchild != NULL && temp -> rchild -> visited == false)
    {
      topp = push(topp, temp -> rchild);
      temp -> rchild -> visited = true;
    }

    if(temp -> lchild != NULL && temp -> lchild -> visited == false)
    {
      topp = push(topp, temp -> lchild);
      temp -> lchild -> visited = true;
    }
  }
}

node *make_node (int num, node * left, node * right)
{
    node *knot = (node*) malloc(sizeof(stack));
    knot -> num = num;
    knot -> visited = false;
    knot -> lchild = left;
    knot -> rchild = right;
    return knot;
}

void free_node (node * p)
{
	if (p -> lchild == NULL && p -> rchild == NULL)
    free (p);
  else 
  {
    free_node (p -> lchild);
    free_node (p -> rchild);
    free (p);
  }
}


void print_node (node * p)
{

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("%d", p->num);
}


void print_tree (node * p, int depth)
{
  for (int i = 0; i < depth; i = i + 1)
    printf (" ");
  printf ("| ");

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("[%d]\n", p->num);


  if (p->lchild)
    {
      print_tree (p->lchild, depth + 1);
    }

  if (p->rchild)
    print_tree (p->rchild, depth + 1);
}

stack *push (stack * topp, node * node)
{
  assert(node != NULL); // precondition

  struct stack * temp = (struct stack*)malloc(sizeof(struct stack*));
  temp -> node = node;
  temp -> next = topp; //now temp is a the top of the stack

	return temp;
}

bool isEmpty (stack * topp)
{
  if (topp == NULL)
    return true;
  else 
    return false;
}

node *top (stack * topp)
{
	return topp -> node;
}

stack *pop (stack * topp)
{

  assert(topp != NULL); // precondition

  stack * temp = topp;
  topp = topp -> next;

  free(temp);

	return topp;

  
}

void print_stack (stack * topp)
{
  struct stack *temp = topp;

  while (temp != NULL)
    {

      print_node (temp->node);
      printf ("\n");

      temp = temp->next;
    }

  printf ("====\n");

  return;
}
