#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using Insertion sort.
 * @list: A pointer to a pointer to the head of the list
 *
 * Description: This function sorts a doubly linked list of integers
 *              in ascending order using the Insertion sort algorithm.
 *              It prints the list after each time two elements are swapped.
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current = (*list)->next;

    while (current != NULL)
    {
        listint_t *prev = current->prev;
        listint_t *next = current->next;
        int value = current->n;

        while (prev != NULL && prev->n > value)
        {
            prev->next->n = prev->n;
            prev = prev->prev;
        }

        if (prev == NULL)
        {
            (*list)->n = value;
        }
        else
        {
            prev->next->n = value;
        }

        current = next;
        print_list(*list);
    }
}
