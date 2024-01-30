#include "main.h"

/**
 * _printf - Emulation of printf's working
 *
 * @format: The unformatted string
 * Return: The number of printed characters
 */
int _printf(const char *format, ...)
{
	char *buffer, *pb;
	const char *pf;
	int n, m, sofb/*size of buffer*/;
	va_list arg;
	fs *form;

	if (!format)
		return (-1);
	sofb = 1024;
	pf = format;
	buffer = malloc(sizeof(char)  *  sofb);
	if (buffer == NULL)
		return (-1);
	pb = buffer;
	va_start(arg, format);
	arrofst(&form);/*point to array of structures*/
	m = store_buf(&form, &buffer, pb, &arg, &sofb, pf);/*Store in buffer*/
	if (m == -1)
		return (-1);
	write(1, buffer, n = _strlen(buffer));
	va_end(arg);
	free(form);
	free(buffer);
	return (n);
}
/**
 * store_per - St the percent
 *
 * @pb: Pointer point to the buffer
 * @ar: List of arguments
 * @size: Pointer to the size of buffer
 * @buf: Pointer to the buffer
 * @len_buf: the rest of buffer
 * Return: The next address
 */
char *store_per(char *pb, va_list *ar, int *size, char **buf, int len_buf)
{
	*pb = '%';
	(void)(size);
	(void)(buf);
	(void)(len_buf);
	(void)(ar);
	return (pb);
}
/**
 * _strlen - Calculate the length of a string
 *
 * @str: a string
 * Return: The length
 */
int _strlen(char *str)
{
	int j;

	for (j = 0; str[j] != '\0'; j++)
		;
	return (j);
}
/**
 * store_c - Store a character
 *
 * @pb: Pointer point to the buffer
 * @ar: List of arguments
 * @size: Pointer to the size of buffer
 * @buf: Pointer to the buffer
 * @len_buf: the rest of buffer
 * Return: The next address
 */
char *store_c(char *pb, va_list *ar, int *size, char **buf, int len_buf)
{
	char cha;

	(void)(size);
	(void)(buf);
	(void)(len_buf);
	cha = va_arg(*ar, int);
	if (cha == '\0')
		cha = '\a';
	*pb = cha;
	return (pb);
}
/**
 * store_str - Store a string
 *
 * @pb: Pointer point to the buffer
 * @ar: List of arguments
 * @size: Pointer to the size of buffer
 * @buf: Pointer to the buffer
 * @len_buf: the rest of buffer
 * Return: The next address
 */
char *store_str(char *pb, va_list *ar, int *size, char **buf, int len_buf)
{
	char *str;

	str = va_arg(*ar, char *);
	if (!str)
		str = "(null)";
	for (; *str; pb++, str++)
	{
		/*check if the buffer is full*/
		len_buf = pb - *buf;
		if (len_buf == *size - 1)
			pb = chlen(size, pb, buf, len_buf);
		*pb = *str;
	}
	return (--pb);
}
