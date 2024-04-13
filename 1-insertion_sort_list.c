#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using the Insertion Sort algorithm.
 * @list: Pointer to the head of the list to be sorted.
 */
void insertion_sort_list(listint_t **list)
{
    if (!list || !(*list) || !(*list)->next)
        return;

    listint_t *current = *list;

    while (current->next)
    {
        if (current->n > current->next->n)
        {
            swap_nodes(current, &(current->next));
            print_list(*list);
            current = current->prev;
            while (current->prev && current->prev->n > current->n)
            {
                if (!swap_nodes(current->prev, &(current)))
                    break;
                print_list(*list);
            }
        }
        else
        {
            current = current->next;
        }
    }
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @left: Pointer to the left node to swap.
 * @right: Pointer to the right node to swap.
 *
 * Return: 1 on success, 0 on failure.
 */
int swap_nodes(listint_t *left, listint_t **right)
{
    if (!left || !(*right))
        return 0;

    listint_t *tmp = *right;
    if (left->prev)
        left->prev->next = tmp;
    if (tmp->next)
        tmp->next->prev = left;

    left->next = tmp->next;
    tmp->prev = left->prev;
    left->prev = tmp;
    tmp->next = left;

    *right = tmp;

    return 1;
}
