#include "heap.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

void heap_pop_helper(Heap *pq, int offset)
{
  int index = 0;
  bool end = false;

  while (!end)
  {
    int child = 2*index + offset;
    if(pq->heapArray[index].priority < pq->heapArray[child].priority)
    {
      heapElem temp = pq->heapArray[index];
      pq->heapArray[index] = pq->heapArray[child];
      pq->heapArray[child] = temp;

      index = child;

      continue;
    }

    end = true;
  }
}

void heap_pop(Heap *pq) {
  if (pq == NULL)
    return;

  for (int i = 0; i < pq->size; i++)
  {
      printf("%i ", pq->heapArray[i].priority);    
  }
  printf("\n");

  pq->heapArray[0] = pq->heapArray[pq->size - 1];
  pq->size--;

  int index = 0;

  bool flag = true;

  while (flag)
  { 
      int child = 2*index + 1;
      if(pq->heapArray[index].priority < pq->heapArray[child].priority)
      {
        heap_pop_helper(pq, 1);
        continue;
      }
      child++;
      if(pq->heapArray[index].priority < pq->heapArray[child].priority)
      {
        heap_pop_helper(pq, 2);
        continue;
      }

      flag = false;
  }

}

Heap *createHeap() {

  Heap *temp = malloc(sizeof(Heap));
  temp->size = 0;
  temp->capac = 3;
  temp->heapArray = malloc(sizeof(heapElem) * temp->capac);

  return temp;
}
