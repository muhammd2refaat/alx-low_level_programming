#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "3-calc.h"
/*
 * 0x0F. C - Function pointers
 * task 3
 */
/**
 * main - prints its name, followed by a new line.
 * @argc: argument count
 * @argv: argument vector
 * Return: (0) success or (98, 99, 100) on field
 */

int main(int argc, char *argv[])
{
	int (*pf)(int, int), n1, n2;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}
	pf = get_op_func(argv[2]);
	if (pf == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	n1 = atoi(argv[1]);
	n2 = atoi(argv[3]);
	if (((argv[2][0] == '/') || (argv[2][0] == '%')) && (n2 == 0))
	{
		printf("Error\n");
		exit(100);
	}
	printf("%d\n", pf(n1, n2));
	return (0);
}
