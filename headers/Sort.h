#include "Data.h"

#ifndef ONEGIN_SORT_H
#define ONEGIN_SORT_H

/*int SortStructsFromStart (const void * ptr_struct1, const void * ptr_struct2); // прямая сортировка
void SortLinesFromEnd (Text * text, int num_of_lines); // обратная сортировка
void SwapStructs (Text * s1, Text * s2); // меняет местами две строки*/

int MergeSort(void * array, void * answ_array, size_t num_of_el, size_t size_of_el, int (*compar)(const void *, const void *));

#endif //ONEGIN_SORT_H
