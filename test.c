#include "test.h"
#include "dataType.h"
#include "helperFunctions.h"
#include "pQueue.h"
#include <stdlib.h>

#define QUEUE_SIZE 16

int main(void)
{

    Command_t *queue[QUEUE_SIZE];

    for (size_t i = 0; i < QUEUE_SIZE; i++) {
        queue[i] = NULL;
    }
    

    for (size_t i = 0; i < QUEUE_SIZE; i++)
    {
        Command_t *tempCommand = (Command_t *)malloc(sizeof(Command_t));

        /* Clear struct. */
        tempCommand->priority = 0;
        tempCommand->id = 0;
        tempCommand->cmd = 0;
        
        for (size_t i = 0; i < 7; i++)
        {
            tempCommand->args[i] = 0;
        }
        tempCommand->outgoing = 0;
    }
    

    /* Instantiate a new Command. */
    Command_t cmd = {
        .priority = 15,
        .id = 35,
        .cmd = 0x43,
        .args = {0x15, 0x44, 0x00, 0x00, 0x05, 0xff, 0x88},
        .outgoing = 1
    };

    enqueue(queue, &cmd);

    Command_t cmdTwo = {
        .priority = 12,
        .id = 35,
        .cmd = 0x43,
        .args = {0x15, 0x44, 0x00, 0x00, 0x05, 0xff, 0x88},
        .outgoing = 1
    };

    return 0; 
}