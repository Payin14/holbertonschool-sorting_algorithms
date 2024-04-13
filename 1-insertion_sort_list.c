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

    listint_t *sorted = NULL
    listint_t *current = *list;

    while (current != NULL)
    {
        listint_t *next = current->next;

        if (sorted == NULL || current->n < sorted->n)
        {
            current->next = sorted;
            current->prev = NULL;

            if (sorted != NULL)
                sorted->prev = current;

            sorted = current;
        }
        else
        {
            listint_t *tmp = sorted;

            while (tmp->next != NULL && tmp->next->n < current->n)
                tmp = tmp->next;

            current->next = tmp->next;

            if (tmp->next != NULL)
                tmp->next->prev = current;

            tmp->next = current;
            current->prev = tmp;
        }

        current = next;
    }

    *list = sorted;
}
