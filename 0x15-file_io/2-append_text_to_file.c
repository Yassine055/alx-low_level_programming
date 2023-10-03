#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: Pointer to the name of the file.
 * @text_content: The string to add to the end of the file.
 *
 * Return: -1 on failure, 1 on success.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor, write_result, len = 0;

	if (!filename)
		return (-1);

	if (text_content)
	{
		while (text_content[len])
			len++;
	}

	file_descriptor = open(filename, O_WRONLY | O_APPEND);
	if (file_descriptor == -1)
		return (-1);

	write_result = write(file_descriptor, text_content, len);
	if (write_result == -1)
	{
		close(file_descriptor);
		return (-1);
	}

	close(file_descriptor);
	return (1);
}
