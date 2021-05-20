#include "test.h"
#include "dataType.h"
#include "helperFunctions.h"
#include "pQueue.h"
#include <stdlib.h>

int main(void)
{

    Queue_t *queueOne = malloc(sizeof(Queue_t));

    for (size_t i = 0; i < MAX_QUEUE_SIZE; i++) {
        queueOne->cmds[i] = NULL;
    }
    

    // for (size_t i = 0; i < MAX_QUEUE_SIZE; i++)
    // {
    //     Command_t *tempCommand = (Command_t *)malloc(sizeof(Command_t));

    //     /* Clear struct. */
    //     tempCommand->priority = 0;
    //     tempCommand->id = 0;
    //     tempCommand->cmd = 0;
        
    //     for (size_t i = 0; i < 7; i++)
    //     {
    //         tempCommand->args[i] = 0;
    //     }
    //     tempCommand->outgoing = 0;
    // }
    

    /* Instantiate a new Command. */
    Command_t cmd = {
        .priority = 15,
        .id = 35,
        .cmd = 0x43,
        .args = {0x15, 0x44, 0x00, 0x00, 0x05, 0xff, 0x88},
        .outgoing = 1
    };

    enqueue(queueOne, &cmd);

    Command_t cmdTwo = {
        .priority = 12,
        .id = 35,
        .cmd = 0x43,
        .args = {0x15, 0x44, 0x00, 0x00, 0x05, 0xff, 0x88},
        .outgoing = 1
    };

    enqueue(queueOne, &cmdTwo);

    printItem(dequeue(queueOne));
    printItem(dequeue(queueOne));

    return 0; 
}