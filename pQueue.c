#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int priority;
    int id;
    int cmd;
    int args[7];
    int outgoing; // 0 = rx, 1 = tx
} Command_t;

void enqueue(Command_t *);
void swap(int *, int *);
void sort();
Command_t *dequeue();

int size = 0;
Command_t *cmds[10];

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

    Command_t *test = dequeue();
    printf("%d\n", test->priority);

    Command_t *test2 = dequeue();
    printf("%d\n", test2->priority);

    Command_t *test3 = dequeue();
    printf("%d\n", test3->priority);

    printf("End of processing");
}

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void enqueue(Command_t *cmd)
{
    int prty = cmd->priority;
    cmds[0] = cmd;
    cmds[size] = cmd;
    size++;
    sort();
    printf("%d\n", prty);
}

void sort()
{
    int currPrty;
    int nextPrty;
    for (int i = 0; i < size; i++)
    {
        currPrty = cmds[i]->priority;
        if (cmds[i + 1] != NULL)
        {
            nextPrty = cmds[i + 1]->priority;
            if (currPrty < nextPrty)
            {
                Command_t *temp = cmds[i];
                cmds[i] = cmds[i + 1];
                cmds[i + 1] = temp;
            }
        }
    }
}

Command_t *dequeue()
{
    Command_t *out = cmds[0];
    size--;
    for (int i = 0; i < size; i++)
    {
        cmds[i] = cmds[i + 1];
    }
    return out;
}
