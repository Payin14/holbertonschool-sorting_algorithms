#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *               using the Bubble sort algorithm.
 * @array: The array of integers to sort
 * @size: The size of the array of integers
 */
void bubble_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    size_t pass, idx;
    int temp;

    for (pass = 0; pass < size - 1; pass++)
    {
        for (idx = 0; idx < size - pass - 1; idx++)
        {
            if (array[idx] > array[idx + 1])
            {
           
                temp = array[idx];
                array[idx] = array[idx + 1];
                array[idx + 1] = temp;
                print_array(array, size);
            }
        }
    }
}
