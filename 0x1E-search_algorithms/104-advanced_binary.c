#include "search_algos.h"

int advancedBinaryRecursive(int *arr, size_t left, size_t right, int target);

/**
  * advancedBinaryRecursive - Recursively
  * searches for a value in a sorted array
  *                           using binary search.
  * @arr: A pointer to the first element of the array to search.
  * @left: The starting index of the subarray to search.
  * @right: The ending index of the subarray to search.
  * @target: The value to search for.
  *
  * Return: If the value is not present, -1. Otherwise, the index where
  *         the value is located.
  *
  * Description: Prints the subarray being searched after each change.
  */
int advancedBinaryRecursive(int *arr, size_t left, size_t right, int target)
{
	size_t index;

	if (right < left)
		return (-1);

	printf("Searching in array: ");
	for (index = left; index < right; index++)
		printf("%d, ", arr[index]);
	printf("%d\n", arr[index]);

	index = left + (right - left) / 2;
	if (arr[index] == target && (index == left || arr[index - 1] != target))
		return (index);
	if (arr[index] >= target)
		return (advancedBinaryRecursive(arr, left, index, target));
	return (advancedBinaryRecursive(arr, index + 1, right, target));
}

/**
  * advanced_binary - Searches for a value
  * in a sorted array using advanced binary search.
  * @arr: A pointer to the first element of the array to search.
  * @size: The number of elements in the array.
  * @target: The value to search for.
  *
  * Return: If the value is not present or the array is NULL, -1.
  *         Otherwise, the first index where the value is located.
  *
  * Description: Prints the subarray being searched after each change.
  */
int advanced_binary(int *arr, size_t size, int target)
{
	if (arr == NULL || size == 0)
		return (-1);

	return (advancedBinaryRecursive(arr, 0, size - 1, target));
}
