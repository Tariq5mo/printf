#ifndef MAIN_H
#define MAIN_H
#include <limits.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct format_specification - Structs for format specifier
 * @for_spec: The special character
 * @ptrf: Pointer to the function corresponds to for_spec
 *
 * Description: gather the special character with it's function
*/
typedef struct format_specification
{
	char *for_spec;
	char *(*ptrf)();
} fs;
char *store_c(char *pb, va_list *ar, int *size, char **buf, int len_buf);
char *chlen(int *sizeofbuf, char *ptrb, char **buffer, int lenbuf);
char *store_str(char *pb, va_list *ar, int *size, char **buf, int len_buf);
char *store_per(char *pb, va_list *ar, int *size, char **buf, int len_buf);
int _strlen(char *str);
void w_int(char **buff, int *ind, long n, int base, int *size);
void w_char(char **buff, int *ind, char cha, int *size);
void write_string(char **buffer, int *index, const char *str, int *size);
void store_uinto(va_list args, char **buff, int *buff_index,
		 int *buff_size);
void store_uintu(va_list args, char **buff, int *buff_index,
		 int *buff_size);
void store_uintx(va_list args, char **buff, int *buff_index,
		 int *buff_size);
void store_int(va_list args, char **buff, int *buff_index,
int *buff_size);
int _printf(const char *format, ...);
void *_realloc(void **ptr, unsigned int old_size, unsigned int new_size);
void arrofst(fs **for_sp);
int store_buf(fs **fos, char **bu, char *pb, va_list *a, int *s,
const char *f);
int resizes_buffer(char *buff, int *buff_size, int buff_index);
/*char *store_int(char *pb, va_list *ar, int *size, char **buf, int len_buf);*/
void store_dec(int n, char **pb, char **buf, int *size);
char *pre_st_int(char *pb, va_list *ar, int *size, char **buf, int len_buf);
char *pre_st_oct(char *pb, va_list *ar, int *size, char **buf, int len_buf);
char *pre_st_uni(char *pb, va_list *ar, int *size, char **buf, int len_buf);
char *pre_st_hex(char *pb, va_list *ar, int *size, char **buf, int len_buf);
char *pre_st_HEX(char *pb, va_list *ar, int *size, char **buf, int len_buf);
void store_uintX(va_list args, char **buff, int *buff_index,
		 int *buff_size);
void w_intX(char **buffer, int *index, long num, int base, int *size);
char *store_nstr(char *pb, va_list *ar, int *size, char **buf, int len_buf);
void store_uintb(va_list args, char **buff, int *buff_index,
int *buff_size);
char *pre_st_bin(char *pb, va_list *ar, int *size, char **buf, int len_buf);
#endif/*endif*/
