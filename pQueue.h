#ifndef PQUEUE_H
#define PQUEUE_H

#include "dataType.h"

void enqueue(Command_t *);
void swap(int *, int *);
void sort();
Command_t *dequeue();

#endif