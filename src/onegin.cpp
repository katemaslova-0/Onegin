#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <sys/stat.h>

#include "Sort.h"
#include "StrFunctions.h"
#include "Output.h"
#include "BufferFunctions.h"
#include "Data.h"

int main (void)
{
    int size_of_buffer = 0;
    int num_of_lines = 0;
    char * buffer = NULL;
    Text * text = {};
    const char * filename = "onegin1.txt";

    GetFileInfo (&size_of_buffer, &num_of_lines, &buffer, &text, filename); /* получение размера файла,
    заполнение буфера и массива указателей данными файла*/

    FILE * fp_out = fopen("onegin_output.txt", "w");

    qsort(text, (size_t)num_of_lines, sizeof(Text), &ReworkedStrcmp); // прямая сортировка, вывод в файл, вывод в консоль
    OutputToFile(text, fp_out, num_of_lines);
    PrintLines(text, num_of_lines);

    Text * sorted_text = (Text *) calloc ((size_t)num_of_lines, sizeof(Text));
    MergeSort(text, sorted_text, (size_t)num_of_lines, sizeof(Text), &ReverseStrcmp); // обратная сортировка, вывод в файл, вывод в консоль
    OutputToFile(sorted_text, fp_out, num_of_lines);
    PrintLines(sorted_text, num_of_lines);

    ReworkBuffer(buffer, '\0', '\n', size_of_buffer); // возврат к оригиналу, вывод в файл, вывод в консоль
    fputs(buffer, fp_out);
    puts(buffer);

    fclose(fp_out); // закрытие файла, очистка памяти
    free(buffer);
    free(text);
    free(sorted_text);

    return 0;
}
