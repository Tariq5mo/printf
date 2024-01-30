#include "main.h"
/**
 * store_uintb - store a binary number
 *
 * @args: Argument list.
 * @buff: Pointer to the buffer.
 * @buff_index: Pointer to current index in the buffer.
 * @buff_size: Pointer to the size of buffer.
 * Return: Void
 */
void store_uintb(va_list args, char *buff, int *buff_index,
int *buff_size)
{
	unsigned int number = va_arg(args, unsigned int);

	w_intX(&buff, buff_index, number, 2, buff_size);
}
/**
 * pre_st_bin - Prepare arguments for store_uintb function
 *
 * @pb: Pointer to buffer
 * @ar: The list of arguments
 * @size: pointer to size
 * @buf: Pointer to buffer
 * @len_buf: Check if buffer is full or not
 * Return: the next address
 */
char *pre_st_bin(char *pb, va_list *ar, int *size, char **buf, int len_buf)
{
	int buff_index;

	(void)(len_buf);
	buff_index = pb - *buf;
	store_uintb(*ar, *buf, &buff_index, size);
	return ((buff_index - 1) + *buf);
}
