#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted
 * singly linked list of integers using linear skip.
 * @head: A pointer to the head of the linked list to search.
 * @target: The value to search for.
 *
 * Return: If the value is not present or the head of the list is NULL, NULL.
 *         Otherwise, a pointer to the first node where the value is located.
 *
 * Description: Prints a value every time it is compared in the list.
 *              Uses the square root of the list size as the jump step.
 */

skiplist_t *linear_skip(skiplist_t *head, int target)
{
	skiplist_t *current, *jump;

	if (head == NULL)
		return (NULL);

	for (current = jump = head; jump->next != NULL && jump->n < target;)
	{
		current = jump;
		if (jump->express != NULL)
		{
			jump = jump->express;
			printf("Value checked at index [%ld] = [%d]\n",
				 jump->index, jump->n);
		}
		else
		{
			while (jump->next != NULL)
				jump = jump->next;
		}
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
		 current->index, jump->index);

	for (; current->index < jump->index && current->n < target;
	current = current->next)
		printf("Value checked at index [%ld] = [%d]\n", current->index, current->n);
	printf("Value checked at index [%ld] = [%d]\n", current->index, current->n);

	return (current->n == target ? current : NULL);
}
