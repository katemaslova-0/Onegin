#include <stdio.h>
#include <assert.h>

#include "BufferFunctions.h"

void ReadPoem (char * buffer, int * num_of_lines, FILE * fp, int size_of_buffer)
{
    assert(buffer != NULL);
    assert(num_of_lines != NULL);
    assert(fp != NULL);

    fread(buffer, sizeof(char), (size_t)size_of_buffer, fp);
    assert(ferror(fp) == 0);

    *num_of_lines = CountLines(buffer);

    ReworkBuffer(buffer, '\n', '\0', size_of_buffer);
}


void FillPointBuff (char * buffer, int num_of_lines, char ** text)
{
    assert(buffer != NULL);
    assert(text != NULL);

    int count = 0;
    char * ptr_buffer = buffer;
    text[count] = buffer;

    for (count = 1; count < num_of_lines; count++)
    {
        while (*ptr_buffer != '\0')
        {
            ptr_buffer++;
        }
        ptr_buffer++;
        text[count] = ptr_buffer;
    }
}


void ReworkBuffer (char * buffer, char sym_to_find, char sym_to_put_instead, int size_of_buffer)
{
    assert(buffer != NULL);

    int count = 0;

    while (count < size_of_buffer - 1)
    {
        if (*(buffer + count) == sym_to_find)
        {
            *(buffer + count) = sym_to_put_instead;
        }
        count++;
    }

    *(buffer + count) = '\0';
}


int CountLines (char * buffer)
{
    assert(buffer != NULL);

    int num_of_lines = 0;
    int count = 0;

    while(*(buffer + count) != '\0')
    {
        if (*(buffer + count) == '\n')
        {
            num_of_lines++;
        }
        count++;
    }

    return num_of_lines;
}
