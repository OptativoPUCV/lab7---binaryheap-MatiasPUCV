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
  {
    pq->capac = pq->capac*2 + 1;
    pq->heapArray = realloc(pq->heapArray, pq->capac * sizeof(heapElem));
  }

  heapElem new;
  new.data = data;
  new.priority = priority;

  pq->heapArray[pq->size] = new;
  pq->size++;
  
  int index = pq->size - 1;

  while( pq->heapArray[index].priority > pq->heapArray[(index - 1) / 2].priority)
  {
    heapElem temp = pq->heapArray[index];
    pq->heapArray[index] = pq->heapArray[(index - 1) / 2];
    pq->heapArray[(index - 1) / 2] = temp;

    index = (index - 1) / 2;
  }
}

void heap_pop(Heap *pq) {
  if (pq == NULL)
    return;

  pq->heapArray[0] = pq->heapArray[pq->size - 1];
  pq->size--;

  int index = 0;

  int flag = 0;

  while (flag == 0)
  {
      int child = 2*index + 1;
      if(pq->heapArray[index].priority < pq->heapArray[child].priority)
      {
        heapElem temp = pq->heapArray[index];
        pq->heapArray[index] = pq->heapArray[child];
        pq->heapArray[child] = temp;

        index = child;
        continue;
      }

      child = 2*index + 2;
      printf("[%i]\n",  pq->heapArray[child].priority);
      if(pq->heapArray[index].priority < pq->heapArray[child].priority)
      {
        printf("SI\n");

        index = child;
        continue;
      }

      flag = 1;
  }

}

Heap *createHeap() {

  Heap *temp = malloc(sizeof(Heap));
  temp->size = 0;
  temp->capac = 3;
  temp->heapArray = malloc(sizeof(heapElem) * temp->capac);

  return temp;
}
