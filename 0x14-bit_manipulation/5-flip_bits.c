/*
 * 0x14. C - Bit manipulation
 * task 5
 */
#include "main.h"
/**
 * flip_bits -  sets the value of a bit to 0 at a given index.
 * @n: number
 * @m: number
 * Return: number of bits you would need to flip
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, j;

	i = 64;
	j = 0;
	while (i--)
	{
		if ((n & 1) != (m & 1))
			j++;
		n >>= 1;
		m >>= 1;
	}
	return (j);
}
