/* Main function of the C program. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FreeRTOS_CLI.h"

/* Dimensions the buffer into which input characters are placed. */
#define cmdMAX_INPUT_SIZE	60

/* Dimensions the buffer into which string outputs can be placed. */
#define cmdMAX_OUTPUT_SIZE	1024

/* Dimensions the buffer passed to the recvfrom() call. */
#define cmdSOCKET_INPUT_BUFFER_SIZE 60


int main()
{
    static signed char cInputString[ cmdMAX_INPUT_SIZE ], cOutputString[ cmdMAX_OUTPUT_SIZE ], cLocalBuffer[ cmdSOCKET_INPUT_BUFFER_SIZE ];
    char c ;
    BaseType_t xMoreDataToFollow;
    puts("Hello World!");
    
    while(1)
    {
        
        c = getchar();
        
        printf("Char %c\n", c);
        /* Pass the string to FreeRTOS+CLI. */
        strcpy(cInputString, "help");
		xMoreDataToFollow = FreeRTOS_CLIProcessCommand( cInputString, cOutputString, cmdMAX_OUTPUT_SIZE );
		printf(cOutputString);
        
    }
    
    
    
    
    return EXIT_SUCCESS;
}


