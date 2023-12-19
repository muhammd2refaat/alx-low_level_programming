/*
 * 0x15. C - File I/O
 * task 3
 * --------------------------
 * By: Muhammed Refaat
 */
#include "main.h"
/*prototypes*/
void check_args(int acc);
void close_fd(int fd);
/**
 * main - check the code
 * @acc: arguments count
 * @avv: arguments vactor
 * Return: 0 success Otherwise failed
 */
int main(int acc, char **avv)
{
	int fdd__from, fdd__to, nnrr;
	char buffer[1024];

	check_args(acc);
	fdd__to = open(avv[2], O_WRONLY | O_TRUNC);
	if (fdd__to == -1)
		fdd__to = open(avv[2], O_WRONLY | O_CREAT, 0664);
	if (fdd__to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", avv[2]);
		exit(99);
	}
	fdd__from = open(avv[1], O_RDONLY);
	if (fdd__from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", avv[1]);
		exit(98);
	}

	while ((nnrr = read(fdd__from, buffer, 1024)))
	{
		if (nnrr == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", avv[1]);
			close_fd(fdd__from);
			close_fd(fdd__to);
			exit(98);
		}
		if (nnrr != write(fdd__to, buffer, nnrr))
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", avv[2]);
			close_fd(fdd__from);
			close_fd(fdd__to);
			exit(99);
		}

	}
	close_fd(fdd__from);
	close_fd(fdd__to);
	return (0);
}
/**
 * check_args - check agrs count
 * @acc: arguments count
 * If the number is not 3 exit: 97
 */
void check_args(int acc)
{
	if (acc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}
/**
 * close_fd - check agrs count
 * @fd: file descriptor
 * If close failed exit(100)
 */
void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
