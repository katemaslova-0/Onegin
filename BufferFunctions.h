#include "Data.h"

#ifndef ONEGIN_BUFFERFUNCTIONS_H
#define ONEGIN_BUFFERFUNCTIONS_H

void GetFileInfo (int * size_of_buffer, int * num_of_lines, char ** buffer, Text ** text, const char * filename);
/* получение размера файла, заполнение буфера и массива указателей данными файла*/
int CountLines (char * buffer); // считает количество строк
void ReadPoem (char * buffer, int * num_of_lines, FILE * fp, int * size_of_buffer); // считывание файла в буфер
void ReworkBuffer (char * buffer, char sym_to_find, char sym_to_put_instead, int size_of_buffer); /* замена в буфере всех символов
одного вида на символы другого вида */
void FillStructBuff (char * buffer, int num_of_lines, Text * text); // заполняет массив указателей

#endif // ONEGIN_BUFFERFUNCTIONS_H
