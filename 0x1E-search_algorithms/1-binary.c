#include "search_algos.h"

/**
 * binary_search - Searches for a value in a sorted
 * array of integers using Binary search algorithm
 * Return: -1 if not found, index if found
 * --------------------------
 * Prototype: int binary_search(int *array, size_t size, int value);
 * --------------------------
 * @array: array of integers
 * @size: size of the array
 * @target: value to search for
 * --------------------------
 * Description:
 * Finds a value in a sorted array of integers using Binary Search algorithm
 * --------------------------
 * By Muhammed Refaat
 */

int binary_search(int *array, size_t size, int target)
{
	size_t left = 0, right = size - 1, mid;

	if (array == NULL)
		return (-1);

	while (left <= right)
	{
		size_t i;

		printf("Searching in array: ");
		for (i = left; i <= right; i++)
		{
			if (i != left)
				printf(", ");
			printf("%d", array[i]);
		}
		printf("\n");

		mid = (left + right) / 2;

		if (array[mid] == target)
			return (mid);
		else if (array[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return (-1);
}
