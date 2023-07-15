/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Darc
 *
 * Created on January 19, 2018, 2:31 PM
 */

#include <stdio.h>
#include <stdlib.h>


//RECURSIVIDAD (una funcion se llama a si misma)
unsigned int multiply(unsigned int x, unsigned int y)
{
    if (x == 1)
    {
        /* Terminating case */
        return y;
    }
    else if (x > 1)
    {
        /* Recursive step */
        return y + multiply(x-1, y);//funcion llamandose a si misma
    }

    /* Catch scenario when x is zero */
    return 0;
}

//LINKED LIST (listas que crecen o se acortan tanto como se necesiten) nodo que apunta a otro nodo 
typedef struct node { // crea la lista
    int val; //valor
    struct node * next; //apuntador al siguiente nodo
} node_t; // es lo mismo que node * node_t (crea una instancia (node_t) del tipo node) 

void print_list(node_t * head) {//imprimir linked list
    node_t * current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

//agregar un valor al final de la lista
void push(node_t * head, int val) {
    node_t * current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}

//agregar un valor al inicio de la lista
void ini_push(node_t ** head, int val) {
    node_t * new_node;
    new_node = malloc(sizeof(node_t));

    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}

//Saca el primer elemento de la lista
int pop(node_t ** head) {
    int retval = -1;
    node_t * next_node = NULL;

    if (*head == NULL) { //Si la lista esta vacia
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}

//Saca el ultimo elemento de la lista
int remove_last(node_t * head) {
    int retval = 0;
    /* if there is only one item in the list, remove it */
    if (head->next == NULL) {
        retval = head->val;
        free(head);
        return retval;
    }

    /* get to the second to last node in the list */
    node_t * current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    /* now current points to the second to last item of the list, so let's remove current->next */
    retval = current->next->val;
    free(current->next);
    current->next = NULL;
    return retval;
}

//Remover un item especifico por su lugar en la lista (index)
int remove_by_index(node_t ** head, int n) {
    int i = 0;
    int retval = -1;
    node_t * current = *head;
    node_t * temp_node = NULL;

    if (n == 0) {// si quiere sacar el primer item
        return pop(head);
    }

    for (int i = 0; i < n-1; i++) {
        if (current->next == NULL) {// si intenta ir a index mas alla del numero de items que tiene
            return -1;
        }
        current = current->next;
    }

    temp_node = current->next;
    retval = temp_node->val;
    current->next = temp_node->next;
    free(temp_node);

    return retval;
}

//Remover un item por su valor
int remove_by_value(node_t ** head, int val) {
    node_t *previous, *current;

    if (*head == NULL) {//lista vacia
        return -1;
    }

    if ((*head)->val == val) {//el valor esta de primeras
        return pop(head);
    }

    previous = current = (*head)->next;
    while (current) {
        if (current->val == val) {
            previous->next = current->next;
            free(current);
            return val;
        }

        previous = current;
        current  = current->next;
    }
    return -1;   //no lo encontro 
}

//Borra una lista
void delete_list(node_t *head) {
    node_t  *current = head, 
            *next = head;

    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
}

////BYNARY TREES (estructura en la cual cada nodo tiene a lo maximo dos hijos)
typedef struct tree
{
  int val;
  struct tree * left;
  struct tree * right;
} tree_t;

//inserta valor en el arbol
void insert(tree_t * tree, int val)
{
  if (tree->val == 0)
  {
    /* insert on current (empty) position */
    tree->val=val;
  }
  else
  {
    if (val < tree->val)
    {
      /* insert left */
      if (tree->left != NULL)
      {
        insert(tree->left, val);
      }
      else
      {
        tree->left = malloc(sizeof(tree_t));
        /* set values explicitly, alternative would be calloc() */
        tree->left->val = val;
        tree->left->left = NULL;
        tree->left->right = NULL;
      }
    }
    else
    {
      if (val >= tree->val)
      {
        /* insert right */
        if (tree->right != NULL)
        {
          insert(tree->right,val);
        }
        else
        {
          tree->right=malloc(sizeof(tree_t));
          /* set values explicitly, alternative would be calloc() */
          tree->right->val=val;
          tree->right->left = NULL;
          tree->right->right = NULL;
        }
      }
    }
  }
}

void print_tree(tree_t * current);
void printDFS(tree_t * current)
{
  //PRE ORDER MODE (current-left-right)
  /*
  if (current == NULL)         return;    //security measure 
  if (current != NULL)         printf("%d ", current->val);
  if (current->left != NULL)   printDFS(current->left);
  if (current->right != NULL)  printDFS(current->right);  
   */  
    
  //IN ORDER MODE(left-current-right)  
  if (current == NULL)         return;   /* security measure */
  if (current->left != NULL)   printDFS(current->left);
  if (current != NULL)         printf("%d ", current->val);
  if (current->right != NULL)  printDFS(current->right);
}

int main() {
    printf("3 times 5 is %d \n", multiply(3, 5));
    
    //LINKED LIST (listas que crecen o se acortan tanto como se necesiten) nodo que apunta a otro nodo 
    
    node_t * head = NULL; // primer elemento de la lista
    head = malloc(sizeof (node_t));
    head->val = 1;//agrega el primer valor a la lista
    head->next = malloc(sizeof (node_t)); // crea el siguiente nodo
    head->next->val = 2;// agrega el segundo valor a la lista
    head->next->next = NULL; // al estar vacio el siguiente nodo indica el final de la lista
    delete_list(head);
    
    
    node_t * test_list = malloc(sizeof(node_t));
    test_list->val = 1;
    test_list->next = malloc(sizeof(node_t));
    test_list->next->val = 2;
    test_list->next->next = malloc(sizeof(node_t));
    test_list->next->next->val = 3;
    test_list->next->next->next = malloc(sizeof(node_t));
    test_list->next->next->next->val = 4;
    test_list->next->next->next->next = NULL;

    remove_by_value(&test_list, 3);

    print_list(test_list);
    delete_list(test_list);
    
    //BYNARY TREES (estructura en la cual cada nodo tiene a lo maximo dos hijos)
    
    tree_t * test_tree = malloc(sizeof (tree_t));
    /* set values explicitly, alternative would be calloc() */
    test_tree->val = 0;
    test_tree->left = NULL;
    test_tree->right = NULL;

    insert(test_tree, 5);
    insert(test_tree, 8);
    insert(test_tree, 4);
    insert(test_tree, 3);

    printDFS(test_tree);
    printf("\n");
    
    

    return 0;
}

