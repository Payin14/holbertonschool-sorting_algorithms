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

    listint_t *current = (*list)->next, *prev, *next_node;

    while (current != NULL)
    {
        next_node = current->next;
        prev = current->prev;

        while (prev != NULL && prev->n > current->n)
        {
            if (prev->prev != NULL)
                prev->prev->next = current;
            if (current->next != NULL)
                current->next->prev = prev;

            prev->next = current->next;
            current->prev = prev->prev;
            prev->prev = current;
            current->next = prev;

            if (current->prev == NULL)
                *list = current;

            print_list(*list);

            prev = current->prev;
        }

        current = next_node;
    }
}
