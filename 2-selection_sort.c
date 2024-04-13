#include "sort.h"

/**
  * selection_sort - Sorts an array of integers in ascending order
  *                  using the Selection Sort algorithm.
  * @array: Pointer to the first element of the array to be sorted.
  * @size: Number of elements in the array.
  */
void selection_sort(int *array, size_t size)
{
    size_t i = 0, j = 1, temp = 0, min_index = 0, limit = size - 1;

    if (size < 2)                    
        return;

    while (i < limit)
    {
        if (j == size)               
        {
            if (i != min_index)      
            {
                temp = array[i];     
                array[i] = array[min_index];
                array[min_index] = temp;
                print_array(array, size); 
            }

            ++i;                    
            min_index = i;          
            j = i + 1;              
            continue;               
        }

        if (array[min_index] > array[j]) 
            min_index = j;               

        ++j;                 
    }
}
