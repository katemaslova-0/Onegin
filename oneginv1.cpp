#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <sys/param.h>

const int NUM_OF_LINES = 14;
const int LENGTH_OF_LINE = 100;

void SwapLines(char * str1, char * str2);

int main (void)
{
    char text[NUM_OF_LINES][LENGTH_OF_LINE] = {};

    FILE * fp = fopen("onegin.txt", "r");

    for (int count = 0; count < NUM_OF_LINES; count++)
    {
        fgets(text[count], LENGTH_OF_LINE, fp);
    }

    SwapLines(text[0], text[1]);

    for (int count = 0; count < NUM_OF_LINES; count++)
    {
        printf("%s", text[count]);
    }

    fclose(fp);

    return 0;
}

void SwapLines(char * str1, char * str2)
{
    assert(str1 != NULL);
    assert(str2 != NULL);

    int length1 = (int)strlen(str1);
    int length2 = (int)strlen(str2);

    for (int count = 0; count < MAX(length1, length2); count++)
    {
        char ch = str1[count];
        str1[count] = str2[count];
        str2[count] = ch;
    }
}
