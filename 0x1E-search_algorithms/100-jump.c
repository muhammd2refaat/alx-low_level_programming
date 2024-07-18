#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array of integers using
 * the Jump search algorithm
 * Return: the first index where value is located, or -1 if value is
 * not present in array or if array is NULL
 * --------------------------
 * Prototype: int jump_search(int *array, size_t size, int value);
 * --------------------------
 * @array: array of integers
 * @count: number of elements in array
 * @target: value to search for
 * --------------------------
 * Description:
 * Finds a value in a sorted array of integers using Jump search algorithm
 * --------------------------
 * By Muhammed Refaat
 */


int jump_search(int *array, size_t count, int target)
{
	size_t jump_range = (size_t)sqrt(count);
	size_t prev_index = 0;
	size_t index;
	/* check if array is NULL */
	if (array == NULL)
		return (-1);

	printf("Value checked array[%lu] = [%d]\n", prev_index, array[prev_index]);
	/* iterate over array to find the start of the range */
	/* where the target could be present */

	while (array[jump_range] < target && jump_range < count)
	{
		printf("Value checked array[%lu] = [%d]\n", jump_range, array[jump_range]);
		prev_index = jump_range;
		jump_range += (size_t)sqrt(count);
		if (jump_range >= count)
			break;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
	prev_index, jump_range);

	/* iterate through the range to find the target */
	index = prev_index;
	while (index <= jump_range && index < count)
	{
		printf("Value checked array[%lu] = [%d]\n", index, array[index]);
		if (array[index] == target)
			return (index);
		index++;
	}

	return (-1);
}
