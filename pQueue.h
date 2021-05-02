#ifndef PQUEUE_H
#define PQUEUE_H

#include "dataType.h"

void enqueue(Command_t *arr[], Command_t *);
void swap(int *, int *);
void sort(Command_t *arr[]);
Command_t *dequeue(Command_t *arr[]);

#endif