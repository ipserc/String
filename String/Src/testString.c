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
	String Str1 = new_String(5);
	String Str2 = new_String(10);
	String Str3 = new_String(20);

	puts("* * * * * * * * * * * * * * * * * * * * * * * *");
	puts("* *           String Test Utility           * *");
	puts("* * * * * * * * * * * * * * * * * * * * * * * *");
	printf("Version: %s\n", getStringVersion());

	setString(Str1, "Hola");
	setString(Str2, "0123456789");
	setString(Str3, "Esto es UN String");

	puts(getString(Str1));
	printf("Str1 - size: %lu - len: %lu\n", getStringSize(Str1), getStringLen(Str1));
	printf("Str1 - Mem Alloc: %lu - Sizeof: %lu\n", getStringMemAlloc(Str1), getStringMemSizeOf(Str1));
	puts(getString(Str2));
	printf("Str2 - size: %lu - len: %lu\n", getStringSize(Str2), getStringLen(Str2));
	printf("Str2 - Mem Alloc: %lu - Sizeof: %lu\n", getStringMemAlloc(Str2), getStringMemSizeOf(Str2));
	puts(getString(Str3));
	printf("Str3 - size: %lu - len: %lu\n", getStringSize(Str3), getStringLen(Str3));
	printf("Str3 - Mem Alloc: %lu - Sizeof: %lu\n", getStringMemAlloc(Str3), getStringMemSizeOf(Str3));



	setString(Str1, "Adios");
	setString(Str2, "--0123456789-------------------------------------------------");
	setString(Str3, "Esto es OTRO String");

	puts(getString(Str1));
	printf("Str1 - size: %lu - len: %lu\n", getStringSize(Str1), getStringLen(Str1));
	printf("Str1 - Mem Alloc: %lu - Sizeof: %lu\n", getStringMemAlloc(Str1), getStringMemSizeOf(Str1));
	puts(getString(Str2));
	printf("Str2 - size: %lu - len: %lu\n", getStringSize(Str2), getStringLen(Str2));
	printf("Str2 - Mem Alloc: %lu - Sizeof: %lu\n", getStringMemAlloc(Str2), getStringMemSizeOf(Str2));
	puts(getString(Str3));
	printf("Str3 - size: %lu - len: %lu\n", getStringSize(Str3), getStringLen(Str3));
	printf("Str3 - Mem Alloc: %lu - Sizeof: %lu\n", getStringMemAlloc(Str3), getStringMemSizeOf(Str3));

	String Str4 = Strcat(Str1, Str2);
	Puts(Str4);
	printf("Str4 - size: %lu - len: %lu\n", getStringSize(Str4), getStringLen(Str4));
	printf("Str4 - Mem Alloc: %lu - Sizeof: %lu\n", getStringMemAlloc(Str4), getStringMemSizeOf(Str4));

	String Str5 = new_String(1);
	setString(Str5, "A");
	puts("Pre Str5");
	Puts(Str5);
	printf("Pre Str5 - size: %lu - len: %lu\n", getStringSize(Str5), getStringLen(Str5));
	printf("Pre Str5 - Mem Alloc: %lu - Sizeof: %lu\n", getStringMemAlloc(Str5), getStringMemSizeOf(Str5));
	Strcpy(Str5, Str3);
	puts("Post Str5");
	Puts(Str5);
	printf("Post Str5 - size: %lu - len: %lu\n", getStringSize(Str5), getStringLen(Str5));
	printf("Post Str5 - Mem Alloc: %lu - Sizeof: %lu\n", getStringMemAlloc(Str5), getStringMemSizeOf(Str5));

	Strcpy(Str5, Str1);
	puts("Post Str5");
	Puts(Str5);
	printf("Post Str5 - size: %lu - len: %lu\n", getStringSize(Str5), getStringLen(Str5));
	printf("Post Str5 - Mem Alloc: %lu - Sizeof: %lu\n", getStringMemAlloc(Str5), getStringMemSizeOf(Str5));

	printf("Strcmp('%s', '%s'): %d\n", getString(Str1), getString(Str2), Strcmp(Str1, Str2));
	printf("Strcmp('%s', '%s'): %d\n", getString(Str2), getString(Str1), Strcmp(Str2, Str1));
	printf("Strcmp('%s', '%s'): %d\n", getString(Str2), getString(Str2), Strcmp(Str2, Str2));

	free_String(Str1);
	free_String(Str2);
	free_String(Str3);
	free_String(Str4);
	free_String(Str5);
}
