/*
 * String.h
 *
 *  Created on: 12 feb. 2023
 *      Author: ipserc
 */

#ifndef SSTRING_H_
#define SSTRING_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>
#include <errno.h>

#define String _String *

/**
 * String struct with the effective size of the string allocated
 * @Field ptr A char pointer to the memory that allocates the string
 * @Field size The effective size of the string allocated at ptr
 */
typedef struct {
	char * ptr;		//Pointer to the string allocated
	size_t size;	//Effective size of the string allocated
} _String;

extern int errno;
int errnum;

/* PROTOTYPES */
/* String.c */
char *getStringVersion(void);
void putsStringVersion(void);
_String *new_String(int len);
void free_String(_String *newString);
char *setString(_String *string, char *cadena);
char *getString(_String *string);
size_t getStringSize(_String *string);
size_t getStringLen(_String *string);
size_t getStringMemAlloc(_String *string);
size_t getStringMemSizeOf(_String *string);


#endif /* SSTRING_H_ */
