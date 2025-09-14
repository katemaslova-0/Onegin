#include <stdio.h>
#include <assert.h>

#define SIZE 7

void FillTriangleArr(int * triangle_array, int size);
void FillRhombusArr(int * rhombus_array, int size);
void FillCircleArr(int * rhombus_array, int size);
void PrintArr(int * array, int size);
int CountSumOfArr(int * triangle_array, int size);

int main (void)
{
    int triangle_array[SIZE][SIZE] = {};
    int rhombus_array[SIZE][SIZE] = {};
    //int circle_array[SIZE][SIZE] = {};

    FillTriangleArr(*triangle_array, SIZE);
    PrintArr(*triangle_array, SIZE);

    //FillCircleArr(*circle_array, SIZE);
    //PrintArr(*circle_array, SIZE);

    FillRhombusArr(*rhombus_array, SIZE);
    PrintArr(*rhombus_array, SIZE);

    printf("\n\nСумма элементов массива: %d\n", CountSumOfArr(*triangle_array, SIZE));
    printf("\n\nСумма элементов массива: %d\n", CountSumOfArr(*rhombus_array, SIZE));
//  printf("\n\nСумма элементов массива: %d\n", CountSumOfArr(*circle_array, SIZE));

    return 0;
}


void FillTriangleArr(int * triangle_array, int size)
{
    assert(triangle_array != NULL);

    int max_count = (((size * size) - size) / 2) + size;
    int count = 0, x = 0, y = 0;

    while (count < max_count)
    {
        *((int *)triangle_array + y * size + x) = 1;
        x++;
        if (x > y)
        {
            y++;
            x = 0;
        }
        count++;
    }
}


void FillRhombusArr(int * rhombus_array, int size)
{
    assert(rhombus_array != NULL);

    int count = 0, x = size / 2, y = 0;

    while (x >= 0)
    {
        *((int *)rhombus_array + y * size + x) = 1;
        x++;
        if (x >= size - (size/2 - y))
        {
            y++;
            x = size / 2 - y;
        }
        count++;
    }

    x = 1;

    while (y != size)
    {
        *((int *)rhombus_array + y * size + x) = 1;
        x++;
        if (x >= size - (y - size / 2))
        {
            y++;
            x = y - size/2;
        }
    }

}


void PrintArr(int * array, int size)
{
    assert(array != NULL);

    int max_count = size * size;
    int count = 0;

    while (count < max_count)
    {
        printf("%d ", *((int *)array + count));
        count++;
        if (count%size == 0)
        {
            printf("\n");
        }
    }

    printf("\n\n");
}


int CountSumOfArr(int * triangle_array, int size)
{
    assert(triangle_array != NULL);

    int max_count = size * size;
    int count = 0, sum = 0;

    while (count < max_count)
    {
        sum += *((int *)triangle_array + count);
        count++;
    }

    return sum;
}
