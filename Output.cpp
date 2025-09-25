#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "Output.h"
#include "Data.h"

void OutputToFile (Text * text, FILE * fp_out, int num_of_lines)
{
    assert(text != NULL);
    assert(fp_out != NULL);

    for (int count = 0; count < num_of_lines; count++)
    {
        fputs((text[count]).lineptr, fp_out);
        fprintf(fp_out, "\n");
    }
    fprintf(fp_out, "\n");
}


void PrintLines (Text * text, int num_of_lines)
{
    assert(text != NULL);

    for (int count = 0; count < num_of_lines; count++)
    {
        printf("%s\n", (text[count]).lineptr);
    }

    printf("\n\n\n\n\n ------------------------------  \n\n\n\n\n");
}
