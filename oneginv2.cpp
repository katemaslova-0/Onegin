#include <stdio.h>
#include <assert.h>

const int NUM_OF_LINES = 14;
const int LENGTH_OF_LINE = 100;

void ReadPoem (char ** text, FILE * fp);

int main (void)
{
    char * text[NUM_OF_LINES] = {};
    FILE * fp = fopen("onegin.txt", "r");

    ReadPoem(text, fp);

    fclose(fp);

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
        text[count] = str;
    }

    for (int count = 0; count < NUM_OF_LINES; count++)
    {
        printf("%s", text[count]);
    }
}
