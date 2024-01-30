#include "main.h"

/**
 * chlen - change the length of buffer
 *
 * @sizeofbuf: point to the last block
 * @ptrb: last address
 * @buffer: The buffer
 * @lenbuf: The length of the buffer
 * Return: The new block
*/
char *chlen(int *sizeofbuf, char *ptrb, char **buffer, int lenbuf)
{
	int n;

	n = *sizeofbuf;
	*buffer = _realloc((void **)buffer, n, *sizeofbuf += 1024);
	if (!(*buffer))
		return (NULL);
	ptrb = *buffer + lenbuf;
	return (ptrb);
}
/**
 * _realloc - reallocate the memory block
 *
 * @ptr: the previously block
 * @old_size: the old size of the previous block
 * @new_size: the new size of the new block
 * Return: the new block
*/
void *_realloc(void **ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;
	unsigned int j;

	p = malloc(new_size);
	if (!p)
		return (NULL);
	if (ptr)
	{
		if (new_size > old_size)
		{
			for (j = 0; j < old_size; j++)
				*(p + j) = *((char *)*ptr + j);
		}
		if (new_size < old_size)
		{
			for (j = 0; j < new_size; j++)
				*(p + j) = *((char *)*ptr + j);
		}
		free(*ptr);
	}
	return (p);
}
/**
 * arrofst - Create array of structures content the specifiers & functions
 *
 * @for_sp: Point to the array of structures
 * Return: void
*/
void arrofst(fs **for_sp)
{
	*for_sp = malloc(sizeof(fs) * 12);/*allocate for array of structures*/
	if (*for_sp == NULL)
		exit(-1);
	/*Initialize array of structures with format specifiers & functions*/
	(*for_sp)[0].for_spec = "s";
	(*for_sp)[0].ptrf = store_str;
	(*for_sp)[1].for_spec = "%";
	(*for_sp)[1].ptrf = store_per;
	(*for_sp)[2].for_spec = "c";
	(*for_sp)[2].ptrf = store_c;
	(*for_sp)[3].for_spec = "d";
	(*for_sp)[3].ptrf = pre_st_int;
	(*for_sp)[4].for_spec = "i";
	(*for_sp)[4].ptrf = pre_st_int;
	(*for_sp)[5].for_spec = "u";
	(*for_sp)[5].ptrf = pre_st_uni;
	(*for_sp)[6].for_spec = "o";
	(*for_sp)[6].ptrf = pre_st_oct;
	(*for_sp)[7].for_spec = "x";
	(*for_sp)[7].ptrf = pre_st_hex;
	(*for_sp)[8].for_spec = "X";
	(*for_sp)[8].ptrf = pre_st_HEX;
	(*for_sp)[9].for_spec = "S";
	(*for_sp)[9].ptrf = store_nstr;
	(*for_sp)[10].for_spec = "b";
	(*for_sp)[10].ptrf = pre_st_bin;
	(*for_sp)[11].for_spec = NULL;
	(*for_sp)[11].ptrf = NULL;
}
/**
 * store_buf - The formatted string will be stored in buffer
 *
 * @fos: Pointer to array of structure
 * @bu: The buffer
 * @pb: Pointer to buffer
 * @a: Pinter to the arguments list
 * @s: The size of buffer
 * @f: The formtted string
 * Return: 0 in Success, -1 in failure
*/
int store_buf(fs **fos, char **bu, char *pb, va_list *a, int *s, const char *f)
{
	int i, lbuf;

	for (; *f; f++, pb++)
	{
		lbuf = pb - *bu;
		if (lbuf == *s - 1)
			pb = chlen(s, pb, bu, lbuf);
		if (*f == '%')
		{
			f++;
			for (i = 0; (*fos)[i].for_spec; i++)
				if (*f == (*fos)[i].for_spec[0])
				{
					pb = (*fos)[i].ptrf(pb, a, s, bu, lbuf);
					break;
				}
			if (!(*fos)[i].for_spec && *f)
			{
				*pb = *(--f);
				*(++pb) = *(++f);
			}
			else if (*f == '\0')
				return (-1);
		}
		else
			*pb = *f;
	}
	*pb = '\0';
	return (0);
}
