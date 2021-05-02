#include "test.h"
#include "dataType.h"
#include "helperFunctions.h"

int main(void)
{

    /* Instantiate a new Command. */
    Command_t cmd1 = {
        .priority = 15,
        .id = 35,
        .cmd = 0x43,
        .args = {0x15, 0x44, 0x00, 0x00, 0x05, 0xff, 0x88},
        .outgoing = 1
    };


    return 0; 
}