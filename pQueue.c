#include <stdio.h>
#include <stdlib.h>
#include "pQueue.h"

void enqueue(Queue_t *queue, Command_t *cmd)
{
    queue->cmds[queue->size++] = cmd;
    sort(queue);
}

void sort(Queue_t *queue)
{
    int currPrty;
    int nextPrty;
    for (int i = queue->size - 1; i > 0; i--)
    {
        currPrty = queue->cmds[i]->priority;
        nextPrty = queue->cmds[i - 1]->priority;
        if (currPrty < nextPrty)
        {
            Command_t *temp = queue->cmds[i];
            queue->cmds[i] = queue->cmds[i - 1];
            queue->cmds[i - 1] = temp;
        }
    }
}

Command_t *dequeue(Queue_t *queue)
{
    Command_t *out = queue->cmds[0];

    for (int i = 0; i < queue->size; i++)
    {
        queue->cmds[i] = queue->cmds[i + 1];
    }

    queue->size -= 1;    
    queue->cmds[queue->size] = NULL;
    return out;
}
