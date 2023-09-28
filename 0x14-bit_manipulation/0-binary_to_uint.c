#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - Converts binary to unsigned int.
 * @b: Binary string.
 *
 * Return: Converted number or 0 for errors.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int dec_val = 0;
	int i;

	if (b == NULL)
		return (0);

	for (i = 0; b[i]; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
		dec_val = (dec_val << 1) | (b[i] - '0');
	}

	return (dec_val);
}
