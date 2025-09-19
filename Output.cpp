#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "Output.h"

void OutputToFile (char ** text, FILE * fp_out, int num_of_lines)
{
    assert(text != NULL);
    assert(fp_out != NULL);

    for (int count = 0; count < num_of_lines; count++)
    {
        fwrite(text[count], sizeof(char), strlen(text[count]), fp_out);
        fprintf(fp_out, "\n");
    }
    fprintf(fp_out, "\n");
}


void PrintLines (char ** text, int num_of_lines)
{
    assert(text != NULL);

    for (int count = 0; count < num_of_lines; count++)
    {
        printf("%s\n", text[count]);
    }

    printf("\n");
}
