#include "search_algos.h"

/**
 * linear_search - searches for a value in an array
 * Return: -1 if not found, index if found
 * --------------------------
 * Prototype: int linear_search(int *array, size_t size, int value);
 * --------------------------
 * @arr: array of integers
 * @n: size of the array
 * @target: value to search for
 * --------------------------
 * Description:
 * Traverse the array and compare each element to the target
 * --------------------------
 * By Muhammed Refaat
 */

int linear_search(int *arr, size_t n, int target)
{
	size_t index = 0;

	/* traverse the array */
	while (index < n)
	{
		/* print the array element being checked */
		printf("Value checked array[%lu] = [%d]\n", index, arr[index]);

		/* check if element matches target */
		if (arr[index] == target)
			return (index);

		/* increment index */
		index++;
	}

	/* if not found, return -1 */
	return (-1);
}
