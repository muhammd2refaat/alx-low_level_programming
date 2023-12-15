/*
 * 0x14. C - Bit manipulation
 * task adv 1
 */
#include "main.h"
/**
 * get_endianness - checks the endianness.
 * Return: 0 or 1
 */

int get_endianness(void)
{
	unsigned int z = 1;
	char *c;

	c = (char *) &z;
	return ((int) *c);
}
