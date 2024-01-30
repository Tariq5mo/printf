#include "main.h"

/**
 * resizes_buffer -  Resizes the buffer if necessary
 *
 * @buff: Pointer to buffer.
 * @buff_size: Pointer to size of the buffer.
 * @buff_index: The index where the new element will be added.
 * Return: 0 on success, -1 on failure.
 */
int resizes_buffer(char *buff, int *buff_size, int buff_index)
{
	int i;
	char *new_buff;

	i = 0;
	if (buff_index > *buff_size - 1)
	{
		new_buff = (char *)malloc(2 * (*buff_size));
		*buff_size *= 2;
		for (; i < buff_index; i++)
			new_buff[i] = buff[i];
		new_buff[i] = '\0';
		free(buff);
		buff = (char *)malloc(*buff_size);
		if (!buff)
			return (-1);
		{
			for (i = 0; i < buff_index; i++)
				buff[i] = new_buff[i];
		}
		buff[i] = '\0';
		free(new_buff);
	}
	return (0);
}
/**
 * store_int - Stores an integer to the buffer.
 *
 * @args: Argument list
 * @buff: Pointer to the buffer
 * @buff_index: Point to current index in the buffer
 * @buff_size: Point to the size of the buffer
 * Return: void
 */
void store_int(va_list args, char **buff, int *buff_index,
int *buff_size)
{
	int n;

	n = va_arg(args, int);
	w_int(buff, buff_index, n, 10, buff_size);
}
/**
 * w_int -  Writes an integer to the buffer.
 *
 * @buff: Pointer to buffer.
 * @ind: Pointer to current index in buffer.
 * @n: The integer to write.
 * @base: Base for conversion (e.g., 8 for octal).
 * @size: Pointer to the size of the buffer.
 */
void w_int(char **buff, int *ind, long n, int base, int *size)
{
	char remind[100];
	int i = 0;

	if (n == 0)
	{
		w_char(buff, ind, '0', size);
		return;
	}
	if (n < 0)
	{
		w_char(buff, ind, '-', size);
		n = -n;
	}
	while (n > 0)
	{
		int digit = n % base;

		remind[i++] = (digit < 10) ? digit + '0' : digit - 10 + 'a';
		n /= base;
	}
	while (i > 0)
		w_char(buff, ind, remind[--i], size);
}
/**
 * w_char -  Write a character to the buffer.
 *
 * @buff: Pointer to the buffer.
 * @ind: Pointer to the current index in the buffer.
 * @cha: Character to write.
 * @size: Pointer to the size of the buffer.
 */
void w_char(char **buff, int *ind, char cha, int *size)
{
	char *new_buff;
	int i;

	if (*ind >= *size - 1)
	{
		*size += 2;
		new_buff = (char *)malloc(*size);
		if (!new_buff)
		{
			free(*buff);
			return;
		}
		for (i = 0; i < *ind; i++)
			new_buff[i] = (*buff)[i];
		free(*buff);
		*buff = new_buff;
	}
	(*buff)[(*ind)++] = cha;
	/*(*buff)[*ind] = '\0';e*/
}
/**
 * store_nstr - Store a string, non printable characters replaced by (\x(hexa))
 *
 * @pb: Pointer to the buffer
 * @ar: List of arguments
 * @size: pointer to size of buffer
 * @buf: Pointer to all buffer
 * @len_buf: different between first and current address
 * Return: the next address
 */
char *store_nstr(char *pb, va_list *ar, int *size, char **buf, int len_buf)
{
	int i;
	char *str;

	str = va_arg(*ar, char *);
	for (; *str; str++, pb++)
	{
		i = pb - *buf;
		if (i == *size)
			pb = chlen(size, pb, buf, i);
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			w_char(buf, &i, '\\', size);
			w_char(buf, &i, 'x', size);
			if (*str < 16)
				w_char(buf, &i, '0', size);
			w_intX(buf, &i, *str, 16, size);
			pb = i - 1 + *buf;
		}
		else
			*pb = *str;
	}
	(void)(len_buf);
	return (--pb);
}
