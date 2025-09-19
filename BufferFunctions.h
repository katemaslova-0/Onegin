#ifndef ONEGIN_BUFFERFUNCTIONS_H
#define ONEGIN_BUFFERFUNCTIONS_H

int CountLines (char * buffer); // считает количество строк
void ReadPoem (char * buffer, int * num_of_lines, FILE * fp, int size_of_buffer); // считывание файла в буфер
void ReworkBuffer (char * buffer, char sym_to_find, char sym_to_put_instead, int size_of_buffer); /* замена в буфере всех символов
одного вида на символы другого вида */
void FillPointBuff (char * buffer, int num_of_lines, char ** text); // заполняет массив указателей

#endif // ONEGIN_BUFFERFUNCTIONS_H