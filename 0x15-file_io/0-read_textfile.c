/*
 * 0x15. C - File I/O
 * task 0
 * --------------------------
 * By: Muhammed Refaat
 */
#include "main.h"
/**
 * read_textfile - eads a text file and prints it to the POSIX standard output.
 * @filename: filename
 * @letters: number of letters it should read and print
 * Return: number, or 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_des;
	char *buffer;

	if (filename == NULL)
		return (0);
	file_des = open(filename, O_RDONLY);
	if (file_des == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	letters = read(file_des, buffer, letters);
	if ((size_t) write(STDOUT_FILENO, buffer, letters) != letters)
		return (0);
	close(file_des);
	free(buffer);
	return (letters);
}
