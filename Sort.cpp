#include <stdio.h>
#include <assert.h>

#include "Sort.h"
#include "StrFunctions.h"

void SortLinesFromStart (char ** text, int num_of_lines)
{
    assert(text != NULL);

    bool if_sorted = false;

    while (if_sorted == false)
    {
        if_sorted = true;
        for (int count = 0; count < num_of_lines - 1; count++)
        {
            if (ReworkedStrcmp(text[count], text[count + 1]) > 0)
            {
                char * ptr = text[count];
                text[count] = text[count + 1];
                text[count + 1] = ptr;
                if_sorted = false;
            }
        }
    }
}


void SortLinesFromEnd (char ** text, int num_of_lines)
{
    assert(text != NULL);

    bool if_sorted = false;

    while (if_sorted == false)
    {
        if_sorted = true;
        for (int count = 0; count < num_of_lines - 1; count++)
        {
            if (ReverseStrcmp(text[count], text[count + 1]) > 0)
            {
                char * ptr = text[count];
                text[count] = text[count + 1];
                text[count + 1] = ptr;
                if_sorted = false;
            }
        }
    }
}
