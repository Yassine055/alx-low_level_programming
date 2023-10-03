#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
 * create_buffer - Allocates a buffer of a given size.
 * @size: The size of the buffer.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(size_t size)
{
	char *buffer = malloc(size);

	if (buffer == NULL)
	{
		perror("Error allocating buffer");
		exit(EXIT_FAILURE);
	}

	return (buffer);
}

/**
 * close_file - Closes a file descriptor.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		perror("Error closing file descriptor");
		exit(EXIT_FAILURE);
	}
}

/**
 * write_to_file - Writes data from source to destination file.
 * @from: Source file descriptor.
 * @to: Destination file descriptor.
 * @buffer: Buffer for reading and writing data.
 */
void write_to_file(int from, int to, char *buffer)
{
	int r, w;

	do

	{
		r = read(from, buffer, BUFFER_SIZE);
		if (r == -1)
		{
			perror("Error reading from source file");
			exit(EXIT_FAILURE);
		}

		w = write(to, buffer, r);
		if (w == -1)
		{
			perror("Error writing to destination file");
			exit(EXIT_FAILURE);
		}

	} while (r > 0);
}

/**
 * copy_file - Copies the contents of one file to another.
 * @src: The source file path.
 * @dest: The destination file path.
 */
void copy_file(const char *src, const char *dest)
{
	int from, to;
	char *buffer;

	buffer = create_buffer(BUFFER_SIZE);

	from = open(src, O_RDONLY);
	if (from == -1)
	{
		perror("Error opening source file");
		free(buffer);
		exit(EXIT_FAILURE);
	}

	to = open(dest, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (to == -1)
	{
		perror("Error opening destination file");
		free(buffer);
		close_file(from);
		exit(EXIT_FAILURE);
	}

	write_to_file(from, to, buffer);

	free(buffer);
	close_file(from);
	close_file(to);
}

/**
 * main - Entry point.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	copy_file(argv[1], argv[2]);

	return (EXIT_SUCCESS);
}
