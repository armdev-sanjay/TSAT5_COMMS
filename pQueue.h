#ifndef PQUEUE_H
#define PQUEUE_H

#include "dataType.h"

void enqueue(Queue_t *queue, Command_t *cmd);
Command_t *dequeue(Queue_t *queue);

#endif