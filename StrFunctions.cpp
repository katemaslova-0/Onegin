#include <stdio.h>
#include <assert.h>
#include <ctype.h>

#include "StrFunctions.h"

int ReworkedStrcmp (const char * str1, const char * str2)
{
    assert(str1 != NULL);
    assert(str2 != NULL);

    while (*str1 != '\0' && *str2 != '\0')
    {
       while (ispunct(*str1) != 0)
        {
            str1++;
        }

        while (ispunct(*str2) != 0)
        {
            str2++;
        }

        if (toupper(*str1) != toupper(*str2))
        {
            break;
        }

        str1++;
        str2++;
    }

    return toupper(*str1) - toupper(*str2);
}

int ReverseStrcmp (const char * str1, const char * str2)
{
    assert(str1 != NULL);
    assert(str2 != NULL);

    const char * str1_start = str1;
    const char * str2_start = str2;

    while (*str1 != '\0')
    {
        str1++;
    }
    while (*str2 != '\0')
    {
        str2++;
    }

    while (str1 != str1_start && str2 != str2_start)
    {
        while (ispunct(*str1) != 0)
        {
            str1--;
        }

        while (ispunct(*str2) != 0)
        {
            str2--;
        }

        if (toupper(*str1) != toupper(*str2))
        {
            break;
        }
        str1--;
        str2--;
    }

    return toupper(*str1) - toupper(*str2);
}
