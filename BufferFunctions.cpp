#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "BufferFunctions.h"
#include "Data.h"

void GetFileInfo (int * size_of_buffer, int * num_of_lines, char ** buffer, Text ** text, const char * filename)
{
    assert(size_of_buffer != NULL);
    assert(num_of_lines != NULL);
    assert(buffer != NULL);
    assert(text != NULL);
    assert(filename != NULL);

    struct stat st = {};
    stat(filename, &st); // получение данных о файле

    *size_of_buffer = (int)st.st_size; // задание размера буфера

    FILE * fp = fopen(filename, "r"); // открытие файла

    *buffer = (char *) calloc((size_t)(*size_of_buffer) + 1, sizeof(char)); // создание буфера
    ReadPoem(*buffer, num_of_lines, fp, size_of_buffer); // считывание файла в буфер
    *text = (Text *) calloc((size_t)(*num_of_lines), sizeof(Text)); // создание массива структур
    FillStructBuff(*buffer, *num_of_lines, *text); // заполнение массива структур
    fclose(fp); // закрытие файла
}


void ReadPoem (char * buffer, int * num_of_lines, FILE * fp, int * size_of_buffer)
{
    assert(buffer != NULL);
    assert(num_of_lines != NULL);
    assert(fp != NULL);

    *size_of_buffer = (int)fread(buffer, sizeof(char), (size_t)(*size_of_buffer), fp);
    assert(ferror(fp) == 0);

    *num_of_lines = CountLines(buffer);

    ReworkBuffer(buffer, '\n', '\0', *size_of_buffer);
}


void FillStructBuff (char * buffer, int num_of_lines, Text * text)
{
    assert(buffer != NULL);
    assert(text != NULL);

    int count = 0;
    int size_of_line = 0;
    char * ptr_buffer = buffer;
    (text[count]).lineptr = buffer;

    for (count = 1; count < num_of_lines; count++)
    {
        while (*ptr_buffer != '\0')
        {
            ptr_buffer++;
            size_of_line++;
        }
        ptr_buffer++;
        (text[count]).size_of_line = size_of_line;
        (text[count]).lineptr = ptr_buffer;
    }
}


void ReworkBuffer (char * buffer, char sym_to_find, char sym_to_put_instead, int size_of_buffer)
{
    assert(buffer != NULL);

    int count = 0;

    while (count < size_of_buffer - 1)
    {
        if (*(buffer + count) == sym_to_find)
        {
            *(buffer + count) = sym_to_put_instead;
        }
        count++;
    }

    *(buffer + count) = '\0';
}


int CountLines (char * buffer)
{
    assert(buffer != NULL);

    int num_of_lines = 0;
    int count = 0;

    while(*(buffer + count) != '\0')
    {
        if (*(buffer + count) == '\n')
        {
            num_of_lines++;
        }
        count++;
    }

    return num_of_lines;
}
