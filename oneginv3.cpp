#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

const int NUM_OF_LINES = 14;
const int LENGTH_OF_LINE = 100;

void ReadPoem (char ** text, FILE * fp);
void SortLines (char ** text);
void PrintLines (char ** text);

int main (void)
{
    char * text[NUM_OF_LINES] = {};
    FILE * fp = fopen("onegin.txt", "r");

    ReadPoem(text, fp);
    fclose(fp);

    SortLines(text);
    PrintLines(text);

    return 0;
}


void ReadPoem (char ** text, FILE * fp)
{
    assert(text != NULL);
    assert(fp != NULL);

    char str[LENGTH_OF_LINE] = {};

    for (int count = 0; count < NUM_OF_LINES; count++)
    {
        fgets(str, LENGTH_OF_LINE, fp);
        text[count] = strdup(str);

        assert(text[count] != NULL);
    }
}


void SortLines (char ** text)
{
    assert(text != NULL);

    bool if_sorted = false;

    while (if_sorted == false)
    {
        if_sorted = true;
        for (int count = 0; count < NUM_OF_LINES - 1; count++)
        {
            if ((int)*(text[count]) > (int)*(text[count + 1]))
            {
                char * ptr = text[count];
                text[count] = text[count + 1];
                text[count + 1] = ptr;
                if_sorted = false;
                printf("tag");
            }
        }
    }
}


void PrintLines (char ** text)
{
    assert(text != NULL);

    for (int count = 0; count < NUM_OF_LINES; count++)
    {
        printf("%s", text[count]);
        free(text[count]);
    }
}
