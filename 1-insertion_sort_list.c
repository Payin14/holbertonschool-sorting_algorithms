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

    bool flag = false;
    listint_t *tmp = NULL, *aux = NULL;

    tmp = *list;

    while (tmp != NULL)
    {
        aux = tmp->next;
        flag = false;

        while (aux != NULL && aux->prev != NULL)
        {
            if (aux->n < aux->prev->n)
            {
                if (aux->next != NULL)
                    aux->next->prev = aux->prev;
                aux->prev->next = aux->next;
                if (aux->prev->prev != NULL)
                    aux->prev->prev->next = aux;
                if (aux->next != NULL)
                    aux->prev->next = aux->next;
                aux->next = aux->prev;
                aux->prev = aux->prev->prev;
                aux->next->prev = aux;
                if (aux->prev == NULL)
                    *list = aux;
                flag = true;
                print_list(*list);
            }
            else
            {
                aux = aux->prev;
            }
        }
        if (!flag)
            tmp = tmp->next;
    }
}
