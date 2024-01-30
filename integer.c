#include "main.h"

/**
 * store_uinto - Store an octal number
 *
 * @args: Argument list.
 * @buff: Pointer to buffer.
 * @buff_index: Pointer to current index of buffer.
 * @buff_size: Pointer to the size of buffer.
 * Return: Void.
 */
void store_uinto(va_list args, char *buff, int *buff_index,
int *buff_size)
{
	unsigned int number = va_arg(args, unsigned int);

	w_int(&buff, buff_index, number, 8, buff_size);
}
/**
 * store_uintu - Store an unsigned number
 *
 * @args: Argument list.
 * @buff: Pointer to buffer.
 * @buff_index: Pointer to current index of buffer.
 * @buff_size: Pointer to the size of buffer.
 * Return: Void.
 */
void store_uintu(va_list args, char *buff, int *buff_index,
int *buff_size)
{
	unsigned int number = va_arg(args, unsigned int);

	w_int(&buff, buff_index, number, 10, buff_size);
}
/**
 * store_uintx - Store a hexa number
 *
 * @args: Argument list.
 * @buff: Pointer to buffer.
 * @buff_index: Pointer to current index of buffer.
 * @buff_size: Pointer to the size of buffer.
 * Return: Void.
 */
void store_uintx(va_list args, char *buff, int *buff_index,
int *buff_size)
{
	unsigned int number = va_arg(args, unsigned int);

	w_int(&buff, buff_index, number, 16, buff_size);
}
/**
 * store_uintX - Store a hexa number in capital
 *
 * @args: Argument list.
 * @buff: Pointer to buffer.
 * @buff_index: Pointer to current index of buffer.
 * @buff_size: Pointer to the size of buffer.
 * Return: Void.
 */
void store_uintX(va_list args, char *buff, int *buff_index,
int *buff_size)
{
	unsigned int number = va_arg(args, unsigned int);

	w_intX(&buff, buff_index, number, 16, buff_size);
}
/**
 * w_intX -  Writes a hexa integer to the buffer.
 *
 * @buffer: Pointer to the buffer.
 * @index: Pointer to the current index in the buffer.
 * @num: Integer to write.
 * @base: Base for conversion (e.g., 10 for decimal).
 * @size: Pointer to the size of the buffer.
 */
void w_intX(char **buffer, int *index, long num, int base, int *size)
{
	char temp[1000];
	int i = 0;

	if (num == 0)
	{
		w_char(buffer, index, '0', size);
		return;
	}
	if (num < 0)
	{
		w_char(buffer, index, '-', size);
		num = -num;
	}
	while (num > 0)
	{
		int digit = num % base;

		temp[i++] = (digit < 10) ? digit + '0' : digit - 10 + 'A';
		num /= base;
	}
	while (i > 0)
	{
		w_char(buffer, index, temp[--i], size);
	}
}
