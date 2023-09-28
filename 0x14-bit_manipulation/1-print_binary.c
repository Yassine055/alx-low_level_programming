#include "main.h"
#include <stdio.h>

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to be printed in binary.
 */
void print_binary(unsigned long int n)
{
	int shift = 0;

	while ((n >> shift) > 0)
	{
		shift++;
	}

	if (shift == 0)
	{
		putchar('0');
		putchar('\n');
		return;
	}

	while (--shift >= 0)
	{
		char bit = (n >> shift) & 1;

		putchar(bit ? '1' : '0');
	}

	putchar('\n');
}
