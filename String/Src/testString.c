/*
 * testString.c
 *
 *  Created on: 12 feb. 2023
 *      Author: ipserc
 */

#include <stdio.h>
#include <stdlib.h>
#include "String.h"

/* ************************************************************************
 * MAIN PROGRAM
 ************************************************************************ */
int main(void) {
	String string1 = new_String(5);
	String string2 = new_String(10);
	String string3 = new_String(20);

	puts("* * * * * * * * * * * * * * * * * * * * * * * * ");
	puts("* *           String Test Utility           * *");
	puts("* * * * * * * * * * * * * * * * * * * * * * * * ");
	putsStringVersion();

	setString(string1, "Hola");
	setString(string2, "0123456789");
	setString(string3, "Esto es UN string");

	puts(getString(string1));
	printf("string1 - size: %lu - len: %lu\n", getStringSize(string1), getStringLen(string1));
	printf("string1 - Mem Alloc: %lu - Sizeof: %lu\n", getStringMemAlloc(string1), getStringMemSizeOf(string1));
	puts(getString(string2));
	printf("string2 - size: %lu - len: %lu\n", getStringSize(string2), getStringLen(string2));
	printf("string2 - Mem Alloc: %lu - Sizeof: %lu\n", getStringMemAlloc(string2), getStringMemSizeOf(string2));
	puts(getString(string3));
	printf("string3 - size: %lu - len: %lu\n", getStringSize(string3), getStringLen(string3));
	printf("string3 - Mem Alloc: %lu - Sizeof: %lu\n", getStringMemAlloc(string3), getStringMemSizeOf(string3));



	setString(string1, "Adios");
	setString(string2, "--0123456789-------------------------------------------------");
	setString(string3, "Esto es OTRO string");

	puts(getString(string1));
	printf("string1 - size: %lu - len: %lu\n", getStringSize(string1), getStringLen(string1));
	printf("string1 - Mem Alloc: %lu - Sizeof: %lu\n", getStringMemAlloc(string1), getStringMemSizeOf(string1));
	puts(getString(string2));
	printf("string2 - size: %lu - len: %lu\n", getStringSize(string2), getStringLen(string2));
	printf("string2 - Mem Alloc: %lu - Sizeof: %lu\n", getStringMemAlloc(string2), getStringMemSizeOf(string2));
	puts(getString(string3));
	printf("string3 - size: %lu - len: %lu\n", getStringSize(string3), getStringLen(string3));
	printf("string3 - Mem Alloc: %lu - Sizeof: %lu\n", getStringMemAlloc(string3), getStringMemSizeOf(string3));

	free_String(string1);
	free_String(string2);
	free_String(string3);
}
