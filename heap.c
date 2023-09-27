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

void *heap_top(Heap *pq) { return NULL; }

void heap_push(Heap *pq, void *data, int priority) {}

void heap_pop(Heap *pq) {}

Heap *createHeap() {

  Heap *temp = malloc(sizeof(Heap));
  temp->size = 0;
  temp->capac = 3;
  temp->heapArray = malloc(sizeof(heapElem) * 3);

  return temp;
}
