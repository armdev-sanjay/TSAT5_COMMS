#include <stdio.h>
#include <stdlib.h>
#include "pQueue.h"

int size = 0;
Command_t *cmds[10];

/*

int main()
{
    Command_t *cmd;
    cmd = (Command_t *)malloc(sizeof(Command_t));
    cmd->priority = 15;
    enqueue(cmd);

    Command_t *cmd2;
    cmd2 = (Command_t *)malloc(sizeof(Command_t));
    cmd2->priority = 30;
    enqueue(cmd2);

    Command_t *cmd3;
    cmd3 = (Command_t *)malloc(sizeof(Command_t));
    cmd3->priority = 2;
    enqueue(cmd3);

    Command_t *cmd4;
    cmd4 = (Command_t *)malloc(sizeof(Command_t));
    cmd4->priority = 181;
    enqueue(cmd4);

    Command_t *cmd5;
    cmd5 = (Command_t *)malloc(sizeof(Command_t));
    cmd5->priority = 102;
    enqueue(cmd5);

    Command_t *cmd6;
    cmd6 = (Command_t *)malloc(sizeof(Command_t));
    cmd6->priority = 73;
    enqueue(cmd6);

    Command_t *test = dequeue();
    printf("%d\n", test->priority);

    test = dequeue();
    printf("%d\n", test->priority);

    test = dequeue();
    printf("%d\n", test->priority);

    test = dequeue();
    printf("%d\n", test->priority);

    test = dequeue();
    printf("%d\n", test->priority);

    test = dequeue();
    printf("%d\n", test->priority);

    printf("End of processing");
}

*/

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void enqueue(Command_t *arr[], Command_t *cmd)
{
    int prty = cmd->priority;
    cmds[size] = cmd;
    size++;
    sort(arr);
}

void sort(Command_t *arr[])
{
    int currPrty;
    int nextPrty;
    for (int i = size - 1; i > 0; i--)
    {
        currPrty = cmds[i]->priority;
        if (cmds[i - 1] != NULL)
        {
            nextPrty = cmds[i - 1]->priority;
            if (currPrty < nextPrty)
            {
                Command_t *temp = cmds[i];
                cmds[i] = cmds[i - 1];
                cmds[i - 1] = temp;
            }
        }
    }
}

Command_t *dequeue(Command_t *arr[])
{
    Command_t *out = cmds[0];
    size--;
    for (int i = 0; i < size; i++)
    {
        cmds[i] = cmds[i + 1];
    }
    return out;
}
