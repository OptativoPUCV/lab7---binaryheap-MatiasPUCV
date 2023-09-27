#include "heap.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo {
  void *data;
  int priority;
} heapElem;

typedef struct Heap {
  heapElem *heapArray;
  int size;
  int capac;
} Heap;

void *heap_top(Heap *pq) {

  if (pq == NULL)
    return NULL;

  if (pq->size == 0)
    return NULL;

  return pq->heapArray[0].data;
}

void heap_push(Heap *pq, void *data, int priority)
{
  if (pq == NULL)
    return;
  
  if (pq->capac == pq->size)
    return;

  heapElem new;
  new.data = data;
  new.priority = priority;

  pq->heapArray[pq->size] = new;
  pq->size++;
  
  int index = pq->size - 1;

  heapElem temp = pq->heapArray[index];
  pq->heapArray[(index - 1) / 2] = temp;


    
  index = (index-1)/2;
  

  
}

void heap_pop(Heap *pq) {
  if (pq == NULL)
    return;

  heapElem temp = pq->heapArray[pq->size - 1];
  pq->size--;

  printf("%i\n", pq->heapArray[0].priority);

  pq->heapArray[0] = temp;
  printf("%i\n", pq->heapArray[0].priority);

  int index = 0;

  if (pq->heapArray[index].priority < pq->heapArray[2*index].priority)
  {
    
  }
  else
  {
    
  }
}

Heap *createHeap() {

  Heap *temp = malloc(sizeof(Heap));
  temp->size = 0;
  temp->capac = 3;
  temp->heapArray = malloc(sizeof(heapElem) * 3);

  return temp;
}
