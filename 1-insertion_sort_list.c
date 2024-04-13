#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using insertion sort.
 * @list: Pointer to the head of the list to be sorted.
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current = (*list)->next;

    while (current != NULL)
    {
        listint_t *temp = current->prev;
        int key = current->n;

        while (temp != NULL && temp->n > key)
        {
            temp->next->n = temp->n;
            temp = temp->prev;
        }

        if (temp == NULL)
        {
            (*list)->n = key;
        }
        else
        {
            temp->next->n = key;
        }

        current = current->next;
    }
}
