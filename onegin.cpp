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

int main (void)
{
    struct stat st = {};
    stat("onegin1.txt", &st); // получение данных о файле

    int size_of_buffer = (int)st.st_size; // задание размера буфера
    int num_of_lines = 0;

    char * buffer = (char *) calloc((size_t)size_of_buffer + 1, sizeof(char)); // создание буфера

    FILE * fp = fopen("onegin1.txt", "r"); // открытие файла
    assert(fp != NULL);

    ReadPoem(buffer, &num_of_lines, fp, size_of_buffer); // считывание файла в буфер
    char ** text = (char **) calloc((size_t)num_of_lines, sizeof(char *)); // создание массива указателей
    FillPointBuff(buffer, num_of_lines, text); // заполнение массива указателей
    fclose(fp); // закрытие файла

    FILE * fp_out = fopen("onegin_output.txt", "w");

    SortLinesFromStart(text, num_of_lines); // прямая сортировка, вывод в файл, вывод в консоль
    OutputToFile(text, fp_out, num_of_lines);
    PrintLines(text, num_of_lines);

    SortLinesFromEnd(text, num_of_lines); // обратная сортировка, вывод в файл, вывод в консоль
    OutputToFile(text, fp_out, num_of_lines);
    PrintLines(text, num_of_lines);

    ReworkBuffer(buffer, '\0', '\n', size_of_buffer); // возврат к оригиналу, вывод в файл, вывод в консоль
    fputs(buffer, fp_out);
    puts(buffer);

    fclose(fp_out); // закрытие файла, очистка памяти
    free(buffer);
    free(text);

    return 0;
}

