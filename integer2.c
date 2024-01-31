#include "main.h"

/**
 * pre_st_int - Prepare arguments for store_int function
 *
 * @pb: The buffer's pointer
 * @ar: Variable of list arguments
 * @size: pointer to the size of buffer
 * @buf: Pointer to the buffer
 * @len_buf: Variable to check if buffer is full or not
 * Return: the next address
 */
char *pre_st_int(char *pb, va_list *ar, int *size, char **buf, int len_buf)
{
	int buff_index;

	(void)(len_buf);
	buff_index = pb - *buf;
	store_int(*ar, buf, &buff_index, size);
	return ((buff_index - 1) + *buf);
}
/**
 * pre_st_oct - Prepare arguments for store_uinto function
 *
 * @pb: The buffer's pointer
 * @ar: Variable of list arguments
 * @size: pointer to the size of buffer
 * @buf: Pointer to the buffer
 * @len_buf: Variable to check if buffer is full or not
 * Return: the next address
 */
char *pre_st_oct(char *pb, va_list *ar, int *size, char **buf, int len_buf)
{
	int buff_index;

	(void)(len_buf);
	buff_index = pb - *buf;
	store_uinto(*ar, buf, &buff_index, size);
	return ((buff_index - 1) + *buf);
}
/**
 * pre_st_uni - Prepare arguments for store_uintu function
 *
 * @pb: The buffer's pointer
 * @ar: Variable of list arguments
 * @size: pointer to the size of buffer
 * @buf: Pointer to the buffer
 * @len_buf: Variable to check if buffer is full or not
 * Return: the next address
 */
char *pre_st_uni(char *pb, va_list *ar, int *size, char **buf, int len_buf)
{
	int buff_index;

	buff_index = pb - *buf;
	(void)(len_buf);
	store_uintu(*ar, buf, &buff_index, size);
	return ((buff_index - 1) + *buf);
}
/**
 * pre_st_hex - Prepare arguments for store_uintx function
 *
 * @pb: The buffer's pointer
 * @ar: Variable of list arguments
 * @size: pointer to the size of buffer
 * @buf: Pointer to the buffer
 * @len_buf: Variable to check if buffer is full or not
 * Return: the next address
 */
char *pre_st_hex(char *pb, va_list *ar, int *size, char **buf, int len_buf)
{
	int buff_index;

	(void)(len_buf);
	buff_index = pb - *buf;
	store_uintx(*ar, buf, &buff_index, size);
	return ((buff_index - 1) + *buf);
}
/**
 * pre_st_HEX - Prepare arguments for store_uintX function
 *
 * @pb: The buffer's pointer
 * @ar: Variable of list arguments
 * @size: pointer to the size of buffer
 * @buf: Pointer to the buffer
 * @len_buf: Variable to check if buffer is full or not
 * Return: the next address
 */
char *pre_st_HEX(char *pb, va_list *ar, int *size, char **buf, int len_buf)
{
	int buff_index;

	(void)(len_buf);
	buff_index = pb - *buf;
	store_uintX(*ar, buf, &buff_index, size);
	return ((buff_index - 1) + *buf);
}
