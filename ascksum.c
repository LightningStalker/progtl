/* Cross sum and XOR all ASCII byte values on each line of the stdin
 * Project Crew™ 6/21/2026
 */

#define     PROGNAME    "ascksum"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>


int
main(int argc, char *argv[])
{
    uint8_t sum;
    int i, j;
    char *asciis;

    if(argc > 1)
    {
        puts("\n"
             "    Hi, I am \'" PROGNAME"\'.  I will cross sum values of ASCII characters on each\n"
             "  line of the input.  The result is exclusive OR + the total.  It's like the\n"
             "  simple checksum.  The result is store in an 8-bit variable and output in the\n"
             "  hexidecimal form.\n"
            );
        exit(EXIT_FAILURE);
    }

    while((asciis = readline(NULL)) != NULL && (j = strlen(asciis)) > 0)
    {
        for(i = sum = 0; i < j; i++)
        {
            sum += (asciis[i] + asciis[j - i]) ^ i;
        }
        free(asciis);
        printf("0x%x\n", sum);
    }
    exit(EXIT_SUCCESS);
}
