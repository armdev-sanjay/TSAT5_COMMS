#include "helperFunctions.h"
#include <stdio.h>

void printItem(Command_t *command)
{
    printf("****************************************");
    printf("Received from: %u (Priority %u)\n", command->id, command->priority);
    printf("Command: %u\tArgs: { ", command->cmd);

    for (size_t i = 0; i < 7; i++)
    {
        printf("%u", command->args[i]);
    }

    printf("}\nOutgoing? ");
    
    if (command->outgoing) printf("Yes\n");
        else printf("No\n");    

    printf("****************************************");
}