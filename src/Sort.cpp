#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "Sort.h"
#include "StrFunctions.h"
#include "Data.h"

/*int SortStructsFromStart (const void * ptr_struct1, const void * ptr_struct2)
{
    assert(ptr_struct1 != NULL);
    assert(ptr_struct2 != NULL);

    const Text * struct1 = (const Text *) ptr_struct1;
    const Text * struct2 = (const Text *) ptr_struct2;

    int res_of_compare = ReworkedStrcmp(struct1->lineptr, struct2->lineptr);

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
}*/


/*void SwapStructs (Text * s1, Text * s2)
{
    Text ptr = *s1;
    *s1 = *s2;
    *s2 = ptr;
}*/


/*void SortLinesFromEnd (Text * text, int num_of_lines)
{
    assert(text != NULL);

    bool if_sorted = false;

    while (if_sorted == false)
    {
        if_sorted = true;
        for (int count = 0; count < num_of_lines - 1; count++)
        {
            if (ReverseStrcmp((text[count]).lineptr, (text[count + 1]).lineptr) > 0)
            {
                SwapStructs(&text[count], &text[count + 1]);
                if_sorted = false;
            }
        }
    }
}*/


int MergeSort(void * array, void * answ_array, size_t num_of_el, size_t size_of_el, int (*compar)(const void *, const void *))
{
    assert(array != NULL);
    assert(answ_array != NULL);
    assert(compar != NULL); // ?

    if (num_of_el == 1)
    {
        free(answ_array);
        return 0;
    }

    void * ptr_buf1 = calloc (num_of_el / 2, size_of_el);
    void * ptr_buf2 = calloc (num_of_el - num_of_el / 2, size_of_el);

   // printf("В два следующих вызова передаются %d и %d количество элементов при общем количестве %d\n", (int)num_of_el / 2, (int)(num_of_el - num_of_el / 2), (int)num_of_el);

    MergeSort(array, ptr_buf1, num_of_el / 2, size_of_el, compar);
    MergeSort((void *)((char *)array + size_of_el * (num_of_el / 2)), ptr_buf2, num_of_el - (num_of_el / 2), size_of_el, compar);

    void * ptr_el1 = array;
    void * ptr_el2 = (void *)((char *)array + size_of_el * (num_of_el / 2));

    // printf("ptr_el1 = %p ptr_el2 = %p\n", ptr_el1, ptr_el2);
    // printf("Текущее количество элементов: %d\n", (int)num_of_el);

    const void * const max_pointer      = (void *)((char *)array + size_of_el * (num_of_el / 2));
    const void * const max_half_pointer = (void *)((char *)array + size_of_el * num_of_el);

    // printf("max_pointer = %p, max_half_pointer = %p\n\n", max_pointer, max_half_pointer);

    while (ptr_el1 < max_half_pointer || ptr_el2 < max_pointer)
    {
        // printf("Начало цикла while, количество элементов: %d \n", (int)num_of_el);
        if (((*compar)(ptr_el1, ptr_el2) < 0  || ptr_el2 == max_pointer) && ptr_el1 != max_half_pointer)
        {
            // printf("Вход в if\n");
            // printf("адрес answ_array до смещения указателя: %p\n", answ_array);
            memcpy(answ_array, ptr_el1, size_of_el);
            answ_array = (void *)((char *)answ_array + size_of_el);
            // printf("адрес answ_array после смещения указателя: %p\n", answ_array);
            ptr_el1 = (void *)((char *)ptr_el1 + size_of_el);
        }
        else
        {
            // printf("Вход в else\n");
            memcpy(answ_array, ptr_el2, size_of_el);
            answ_array = (void *)((char *)answ_array + size_of_el);
            ptr_el2 = (void *)((char *)ptr_el1 + size_of_el);
        }
    }

    free(ptr_buf1);
    free(ptr_buf2);
    return 0;
}
