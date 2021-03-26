#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    const void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(const void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List* lista = malloc(sizeof(List));
  //lista->tail= NULL;
  lista->head=NULL;
  lista->tail=NULL;
     return lista;
}

void * firstList(List * list) {
  if(list->head == NULL)return NULL;
  list->current=list->head;
    return (int*)(list->head->data);
}

void * nextList(List * list) {
  //if(list->current == NULL)return NULL;
  /*int *j = malloc(sizeof(int)*10);
  Node* aux =createNode(j);
   aux=list->current; */
   //Node *aux=list->current;
   if(list->current == NULL)return NULL; // cgracias de nada :3
   if(list->current->next == NULL)return NULL;
  list->current=list->current->next;
    return (int*)(list->current->data);
}

void * lastList(List * list) {
  list->current=list->tail;
    return (int*)(list->tail->data);
}

void * prevList(List * list) {
  if(list->current == NULL)return NULL;
  if(list->current->prev == NULL)return NULL;
  list->current=list->current->prev;
    return (int*)(list->current->data);
}

void pushFront(List * list, const void * data) {
  Node *nodo = createNode(data);
  if(list->head==NULL)
  {
    list->head=nodo;
  }
  nodo->next=list->head;
  if(list->head)
  list->head->prev = nodo;
  if(list->head == list->tail)//printf("cola y cabeza ==");
  list->tail = nodo;
  list->head = nodo;
  nodo->prev= NULL;
  //return (void)NULL;
}

void pushBack(List * list, const void * data) {
  //Node *nodo = createNode(data);
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, const void * data) {
  Node *nodo = createNode(data);
  if( list->current == list->tail)
  {
    nodo->prev = list->tail;
    if(list->tail)
    list->tail->next = nodo;
    list->tail=nodo;
    nodo->next=NULL;
  }
  else
  {
    if(list->current == list->head)
    {
      pushFront(list,data);
    }
    else
    {
      nodo->next= list->current;
      nodo->prev = list->current->prev;
      if(list->current)
      list->current->prev=nodo;
      list->current->prev->prev=nodo;
      list->current=nodo;
    }
    
  }
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}