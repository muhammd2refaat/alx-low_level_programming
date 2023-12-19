/**
 * task - elf header
 * --------------------
 * By: Muhammed Refaat
*/
#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
/** prototypes */
void magic(char *);
int class(char *);
void entry(char *, int, int);
int data(char *);
void version(char *);
void osabi(char *);
void abivers(char *);
void type(char *, int);
/**
 * main - check the code
 * @acc: arguments count
 * @avv: arguments vactor
 * Return: 0 success Otherwise failed
 */
int main(int acc, char **avv)
{
	int fdd, nr, tsize_class, size_data;
	char buffer[18];

	if (acc != 2)
	{
		write(STDERR_FILENO, "Usage: elf_header elf_filename\n", 31);
		exit(98);
	}
	fdd = open(avv[1], O_RDONLY);
	if (fdd == -1)
	{
		write(STDERR_FILENO, "Error: Can't open from file\n", 28);
		exit(98);
	}
	nr = read(fdd, buffer, 18);
	if (nr == -1)
	{
		write(STDERR_FILENO, "Error: Can't read from file\n", 28);
		exit(98);
	}
	magic(buffer);
	tsize_class = class(buffer);
	size_data = data(buffer);
	version(buffer);
	osabi(buffer);
	abivers(buffer);
	type(buffer, size_data);
	lseek(fdd, 24, SEEK_SET);
	read(fdd, (char *) buffer, tsize_class / 8);
	entry(buffer, tsize_class, size_data);
	if (close(fdd) == -1)
	{
		write(STDERR_FILENO, "Error: cannot close\n", 20);
		exit(98);
	}
	return (0);
}
/**
 * magic - print magic
 * @buffer: ELF bufferfer
 */
void magic(char *buffer)
{
	int i;

	if ((buffer[0] != 127) || (buffer[1] != 'E')
	|| (buffer[2] != 'L') || (buffer[3] != 'F'))
	{
		write(STDERR_FILENO, "Error: not ELF file\n", 20);
		exit(98);
	}
	printf("ELF Header:\n  Magic:  ");
	for (i = 0; i < 16; i++)
	{
		printf(" %.2x", buffer[i]);
	}
	printf("\n");
}

/**
 * class - print magic
 * @buffer: the ELF header
 * Return: 64 or 32
 */
int class(char *buffer)
{
	printf("  %-35s", "Class:");

	if (buffer[EI_CLASS] == ELFCLASS64)
	{
		printf("ELF64\n");
		return (64);
	}
	if (buffer[EI_CLASS] == ELFCLASS32)
	{
		printf("ELF32\n");
		return (32);
	}
	printf("<unknown: %x>\n", buffer[EI_CLASS]);
	return (32);
}
/**
 * abivers - print ELF ABI version
 * @buffer: ELF bufferfer
 */
void abivers(char *buffer)
{
	printf("  %-35s%u\n", "ABI Version:", buffer[EI_ABIVERSION]);
}
/**
 * data - print ELF data
 * @buffer: ELF buffer
 *
 * Return: 1 if big endian, otherwise 0
 */
int data(char *buffer)
{
	printf("  %-35s", "Data:");

	if (buffer[EI_DATA] == ELFDATA2MSB)
	{
		printf("2's complement, big endian\n");
		return (1);
	}
	if (buffer[EI_DATA] == ELFDATA2LSB)
	{
		printf("2's complement, little endian\n");
		return (0);
	}
	printf("Invalid data encoding\n");
	return (0);
}

/**
 * version - print ELF version
 * @buffer: the ELF buffer
 */
void version(char *buffer)
{
	printf("  %-35s%u", "Version:", buffer[EI_VERSION]);
	if (buffer[EI_VERSION] == EV_CURRENT && 1)
		printf(" (current)\n");
	else
		printf("\n");
}

/**
 * osabi - print ELF OS/ABI
 * @buffer: ELF buffer
 */
void osabi(char *buffer)
{
	char *table[19] = {
		"UNIX - System V", "UNIX - HP-UX", "UNIX - NetBSD",
		"UNIX - GNU", "<unknown: 4>", "<unknown: 5>", "UNIX - Solaris",
		"UNIX - AIX", "UNIX - IRIX", "UNIX - FreeBSD", "UNIX - Tru64",
		"Novell - Modesto", "UNIX - OpenBSD", "VMS - OpenVMS",
		"HP - Non-Stop Kernel", "AROS", "FenixOS",
		"Nuxi CloudABI", "Stratus Technologies OpenVOS"};
	printf("  %-35s", "OS/ABI:");
	if (buffer[EI_OSABI] < 19)
		printf("%s\n", table[(unsigned int) buffer[EI_OSABI]]);
	else
		printf("<unknown: %x>\n", buffer[EI_OSABI]);
}
/**
 * type - print type
 * @buffer: ELF buffer
 * @endian: endianness
 */
void type(char *buffer, int endian)
{
	int type;

	char *table[5] = {
		"NONE (No file type)",
		"REL (Relocatable file)",
		"EXEC (Executable file)",
		"DYN (Shared object file)",
		"CORE (Core file)"
	};

	printf("  %-35s", "Type:");

	if (endian)
		type = 256 * buffer[16] + buffer[17];
	else
		type = 256 * buffer[17] + buffer[16];

	if (type < 5)
		printf("%s\n", table[type]);
	else if (type >= ET_LOPROC && type <= ET_HIPROC)
	printf("Processor Specific: (%4x)\n", type);
	else if (type >= ET_LOOS && type <= ET_HIOS)
		printf("OS Specific: (%4x)\n", type);
	else
		printf("<unknown: %x>\n", type);
}

/**
 * entry - entry point address
 * @buffer: string containing the entry point address
 * @mode: (32 or 64)
 * @end: endianness
 */
void entry(char *buffer, int mode, int end)
{
	int size = mode / 8;

	printf("  %-35s0x", "Entry point address:");
	if (end)
	{
		while (size && !*(buffer))
		{
			++buffer;
			--size;
		}
		printf("%x", *buffer & 0xff);

		while (--size > 0)
			printf("%02x", *(++buffer) & 0xff);
	}
	else
	{
		buffer += size;
		while (size && !*(--buffer))
			--size;
		printf("%x", *buffer & 0xff);
		while (--size > 0)
			printf("%02x", *(--buffer) & 0xff);
	}
	printf("\n");
}
