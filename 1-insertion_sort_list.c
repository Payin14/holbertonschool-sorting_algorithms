#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using Insertion Sort.
 * @list: Pointer to the head of the list to be sorted.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	if (!list || !(*list) || !(*list)->next)
		return;
	current = *list;
	while (current->next)
	{
		if (current->n > current->next->n)
		{
			listint_t *temp = current->next;
			if (current->prev)
				current->prev->next = temp;
			else
				*list = temp;
			current->next = temp->next;
			if (temp->next)
				temp->next->prev = current;
			temp->next = current;
			temp->prev = current->prev;
			current->prev = temp;
			current = (temp->prev) ? temp->prev : temp;
			print_list(*list);
			while (current->prev && current->prev->n > current->n)
			{
				listint_t *prev = current->prev;
				prev->next = current->next;
				if (current->next)
					current->next->prev = prev;
				current->next = prev;
				current->prev = prev->prev;
				prev->prev = current;
				if (current->prev)
					current->prev->next = current;
				current = (current->prev) ? current->prev : current;
				print_list(*list);
			}
		}
		else
		{
			current = current->next;
		}
	}
}
