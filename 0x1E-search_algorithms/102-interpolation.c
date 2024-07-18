#include "search_algos.h"

/**
 * interpolation_search - Searches for a target in a sorted
 * array of integers using Interpolation search algorithm
 * Return: -1 if not found, index if found
 * --------------------------
 * Prototype: int interpolation_search(int *array, size_t size, int target);
 * --------------------------
 * @array: array of integers
 * @count: number of elements in array
 * @value_to_search: value to search for
 * --------------------------
 * Description:
 * Finds a value in a sorted array of integers using
 * Interpolation search algorithm
 * --------------------------
 * By Muhammed Refaat
 */

int interpolation_search(int *array, size_t count, int value_to_search)
{
	unsigned int left_index = 0;
	unsigned int right_index = count - 1;
	unsigned int index_to_check;

	if (array == NULL || count == 0)
		return (-1);

	while (array[left_index] != array[right_index])
	{
		/* calculate the position to check based on interpolation formula */
		index_to_check = left_index +
		(unsigned int)((double)(right_index - left_index) /
		(array[right_index] - array[left_index]) *
		(value_to_search - array[left_index]));

		/* check if the index is out of range */
		if (index_to_check >= count)
		{
			printf("Value checked array[%u] is out of range\n",
				index_to_check);
			return (-1);
		}

		/* print the value checked at the index */
		printf("Value checked array[%u] = [%d]\n", index_to_check,
			array[index_to_check]);

		/* update the range based on the value checked */
		if (value_to_search < array[index_to_check])
			right_index = index_to_check - 1;
		else if (value_to_search > array[index_to_check])
			left_index = index_to_check + 1;
		else
			return (index_to_check);
	}

	if (value_to_search == array[left_index])
		return (left_index);
	else
		return (-1);
}

