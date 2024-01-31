#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int len, len2;

	len = _printf("% ");
	len2 = printf("% ");
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.11\n");
		fflush(stdout);
		return (1);
		}
	len = _printf("% % % % ");
	printf("\n");
	len2 = printf("% % % % ");
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.22\n");
		fflush(stdout);
		return (1);
		}
	return (0);
}
