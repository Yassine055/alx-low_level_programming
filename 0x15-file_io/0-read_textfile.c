#include "main.h"
#include <stdlib.h>

/**
 * read_and_print_text - Reads text from a file and prints it to STDOUT.
 * @filename: The name of the text file to be read.
 * @max_letters: The maximum number of letters to be read.
 * Return: The actual number of bytes read and printed.
 *         0 when the function fails or filename is NULL.
 */
ssize_t read_and_print_text(const char *filename, size_t max_letters)
{
	char *buffer;
	ssize_t file_descriptor;
	ssize_t bytes_read;
	ssize_t bytes_written;

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (0);

	buffer = malloc(sizeof(char) * max_letters);
	bytes_read = read(file_descriptor, buffer, max_letters);
	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

	free(buffer);
	close(file_descriptor);

	return (bytes_written);
}
