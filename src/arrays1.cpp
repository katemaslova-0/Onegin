#include <stdio.h>
#include <assert.h>
#include <math.h>

#define SIZE 31 // размер прямоугольной сетки, в которую вписана фигура
#define size_of_triangle_array ((SIZE * (SIZE - 1))/2 + SIZE) // количество ячеек, занимаемых в случае треугольного массива
#define size_of_rhombus_array (SIZE * SIZE / 2 + 1) // количество ячеек, занимаемых в случае ромбовидного массива
#define size_of_circle_array ()
#define limit_value fabs(size / 2 - y)

// limit_value обозначен номер клетки(от начала строки) квадратной сетки, с которой начинается печать элементов

void FillArr(int * array, int size); // заполняет массив элементами
void PrintTriangleArr(int * triangle_array, int size); // распечатка треугольного массива
void PrintRhombusArr(int * rhombus_array, int size); // распечатка ромбовидного массива

int main (void)
{
    int triangle_array[size_of_triangle_array] = {};

    FillArr(triangle_array, size_of_triangle_array);
    PrintTriangleArr(triangle_array, size_of_triangle_array);

    int rhombus_array[size_of_rhombus_array] = {};

    FillArr(rhombus_array, size_of_rhombus_array);
    PrintRhombusArr(rhombus_array, SIZE);

    int circle_array[size_of_circle_array] = {};
    FillArr(rhombus_array, size_of_circle_array);
    PrintfCircleArr(circle_array, SIZE);

    return 0;
}


void FillArr (int * array, int size)
{
    assert(array != NULL);

    int count = 0;

    while (count < size)
    {
        array[count] = 1;
        count++;
    }
}


void PrintTriangleArr (int * triangle_array, int size)
{
    assert(triangle_array != NULL);

    int count = 0, x = 0, y = 0;

    while (count < size)
    {
        printf("%d", *triangle_array);
        triangle_array++;
        x++;

        if (x > y)
        {
            printf("\n");
            y++;
            x = 0;
        }

        count++;
    }

    printf("\n\n");
}


void PrintRhombusArr (int * rhombus_array, int size)
{
    assert(rhombus_array != NULL);

    int x = 0, y = 0;

    while (y < size)
    {
        while (x < limit_value)
        {
            printf(" ");
            x++;
        }

        while (x < size - limit_value)
        {
            printf("%d", *rhombus_array);
            rhombus_array++;
            x++;
        }

        while (x < size)
        {
            printf(" ");
            x++;
        }

        y++;
        x = 0;
        printf("\n\n");
    }
}


void PrintfCircleArr(int * circle_array, int size)
{
    int x = 0, y = 0, radius = size / 2;

    for






}
