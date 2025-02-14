#include "main.h"

/**
 * _flags - Make the flags of printf
 *
 * @pb: Pointer to buff
 * @ar: Arguments list
 * @size: The size of buff
 * @buf: The buffer
 * @len_buf: length if buff
 * @f: format string
 * @fos: Pointer to arrofs
 * Return: The next address
*/
char *_flags(char *pb, va_list *ar,
int *size, char **buf, int len_buf, const char **f, fs **fos)
{
	int i, n, m;
	double j;

	m = 0;
	(void)(len_buf);
	if (check_for(*f, fos) == 0)
	{
		i = count_for(*f, fos);
		if (i == -1)
		{
			i = check_c('\0', 100, *f);
			*f += i + 1;
			*pb = '$';
			return (pb);
		}
		if (check_c('#', i, *f) == 0)
		{
			(*f)++;
			while (check_for(*f, fos) == 0)/*find where formator*/
			{
				(*f)++;
				m++;
			}
			if (**f == 'x')
			{
				if (check_c('l', i, *f - 1 - m) == 0)
					j = va_arg(*ar, unsigned long int);
				else if (check_c('h', i, *f - 1 - m) == 0)
					j = (unsigned short int)va_arg(*ar, int);
				else
					j = va_arg(*ar, unsigned int);
                                if (j > 0)
				{
					*pb++ = '0';
					*pb++ = 'x';
				}
				n = pb - *buf;
				w_int(buf, &n, j, 16, size);
				pb = n + *buf;
				pb++;
				*pb = '$';
				return (pb);
			}
			else if (**f == 'X')
			{
				if (check_c('l', i, *f - 1 - m) == 0)
					j = va_arg(*ar, unsigned long int);
				else if (check_c('h', i, *f - 1 - m) == 0)
					j = (unsigned short int)va_arg(*ar, int);
				else
					j = va_arg(*ar, unsigned int);
				if (j > 0)
				{
					*pb++ = '0';
					*pb++ = 'X';
				}
				n = pb - *buf;
				w_intX(buf, &n, j, 16, size);
				pb = n  + *buf;
				pb++;
				*pb = '$';
				return (pb);
			}
			else if (**f == 'o')
			{
				if (check_c('l', i, *f - 1 - m) == 0)
                                        j = va_arg(*ar, unsigned long int);
                                else if (check_c('h', i, *f - 1 - m) == 0)
                                        j = (unsigned short int)va_arg(*ar, int);
                                else
                                        j = va_arg(*ar, unsigned int);
				if (j > 0)
					*pb++ = '0';
				n = pb - *buf;
				w_int(buf, &n, j, 8, size);
				pb = n - 1 + *buf;
				pb++;
				*pb = '$';
				return (pb);
			}
		}
		else if (check_c('+', i, *f) == 0)
		{
			while (check_for(*f, fos) == 0)
			{
				(*f)++;
				m++;
			}
			if (**f == 'd' || **f == 'i')
			{
				if (check_c('l', i, *f - 1 - m) == 0)
                                        j = va_arg(*ar, long int);
                                else if (check_c('h', i, *f - 1 - m) == 0)
                                        j = (short int)va_arg(*ar, int);
                                else
                                        j = va_arg(*ar, int);
				if (j > -1)
					*pb++ = '+';
				n = pb - *buf;
				w_int(buf, &n, j, 10, size);
				pb = n - 1 + *buf;
				pb++;
				*pb = '$';
			}
			return (pb);
		}
		else if (check_c(' ', i, *f) == 0)
		{
			while (check_for(*f, fos) == 0)
			{
                                (*f)++;
				m++;
			}
                        if (**f == 'd' || **f == 'i')
                        {
                                if (check_c('l', i, *f - 1 - m) == 0)
                                        j = va_arg(*ar, long int);
                                else if (check_c('h', i, *f - 1 - m) == 0)
                                        j = (short int)va_arg(*ar, int);
                                else
                                        j = va_arg(*ar, int);
                                if (j > -1)
                                        *pb++ = ' ';
                                n = pb - *buf;
                                w_int(buf, &n, j, 10, size);
                                pb = n - 1 + *buf;
                                pb++;
                                *pb = '$';
                        }
                        return (pb);
		}
	}
	return (pb);
}
/**
 * check_for - Checks is the currnt char is formators
 *
 * @f: the format string
 * @fos: pointer to array of structures
 * Return: 0 not formator, -1 is formator
*/
int check_for(const char *f, fs **fos)
{
	int i;

	for (i = 0; (*fos)[i].for_spec; i++)
	{
		if (*f == (*fos)[i].for_spec[0])
			return (-1);
	}
	return (0);
}
/**
 * check_c - to check if there is the (c) before formator or not
 *
 * @c: the char
 * @i: the distance from formator
 * @f: the current char
 * Return: 0 if there is, -1 if not
*/
int check_c(char c, int i, const char *f)
{
	while (i > 0)
	{
		if (*f == c)
			return (0);
		i--;
		f++;
	}
	return (-1);
}
/**
 * count_for - Count how far the formator from f
 *
 * @f: Point to current char inside the formated string
 * @fos: Point to arrofs
 * Return: j which how far from f
 */
int count_for(const char *f, fs **fos)
{
	int i, j;

	for (j = 0;; f++, j++)
	{
		for (i = 0; (*fos)[i].for_spec; i++)
		{
			if (*f == (*fos)[i].for_spec[0])
				return (j);
			if (*f == '\0')
				return (-1);
		}
	}
	return (0);
}
