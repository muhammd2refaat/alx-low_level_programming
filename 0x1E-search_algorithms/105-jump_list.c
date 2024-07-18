#include "search_algos.h"

/**
 * jump_list - Searches for a value in a sorted
 * singly linked list of integers using jump search.
 * @head: A pointer to the head of the linked list to search.
 * @size: The number of nodes in the list.
 * @target: The value to search for.
 *
 * Return: If the value is not present or the head of the list is NULL, NULL.
 *         Otherwise, a pointer to the first node where the value is located.
 *
 * Description: Prints a value every time it is compared in the list.
 *              Uses the square root of the list size as the jump step.
 */
listint_t *jump_list(listint_t *head, size_t size, int target)
{
	size_t step, stepSize;
	listint_t *current, *jump;

	if (head == NULL || size == 0)
		return (NULL);

	step = 0;
	stepSize = sqrt(size);
	for (current = jump = head; jump->index + 1 < size && jump->n < target;)
	{
		current = jump;
		for (step += stepSize; jump->index < step; jump = jump->next)
		{
			if (jump->index + 1 == size)
				break;
		}
		printf("Value checked at index [%ld] = [%d]\n", jump->index, jump->n);
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
		 current->index, jump->index);

	for (; current->index < jump->index && current->n < target;
	current = current->next)
		printf("Value checked at index [%ld] = [%d]\n", current->index, current->n);
	printf("Value checked at index [%ld] = [%d]\n", current->index, current->n);

	return (current->n == target ? current : NULL);
}
