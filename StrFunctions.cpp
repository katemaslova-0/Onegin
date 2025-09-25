#include <stdio.h>
#include <assert.h>
#include <ctype.h>

#include "StrFunctions.h"
#include "Data.h"

int ReworkedStrcmp (const void * ptr_struct1, const void * ptr_struct2)
{
    assert(ptr_struct1 != NULL);
    assert(ptr_struct2 != NULL);

    const Text * struct1 = (const Text *) ptr_struct1;
    const Text * struct2 = (const Text *) ptr_struct2;

    const char * str1 = struct1->lineptr;
    const char * str2 = struct2->lineptr;

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

    int res_of_compare = toupper(*str1) - toupper(*str2);

    if (res_of_compare > 0)
    {
        return 1;
    }
    else if (res_of_compare == 0)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}


int ReverseStrcmp (const void * ptr_struct1, const void * ptr_struct2)
{
    assert(ptr_struct1 != NULL);
    assert(ptr_struct2 != NULL);

    const Text * struct1 = (const Text *) ptr_struct1;
    const Text * struct2 = (const Text *) ptr_struct2;

    const char * str1 = struct1->lineptr;
    const char * str2 = struct2->lineptr;

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

    int res_of_compare = toupper(*str1) - toupper(*str2);

    if (res_of_compare > 0)
    {
        return 1;
    }
    else if (res_of_compare == 0)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}
