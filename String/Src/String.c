/*
 ============================================================================
 Name        : Strinc.c
 Author      : Ipserc
 Version     : see VERSION
 Created     : 12 feb. 2023
 Copyright   : GNU General Public License v3.0
 Description : Full management and safe string allocation
 ============================================================================
 */

#include "String.h"

#define VERSION "1.0.0 (2023_0212_1200)"

/* ************************************************************************
 * VERSION SECTION
 ************************************************************************ */
/**
 * Gets the String Version
 * @return The string Version
 */
char * getStringVersion(void)
{
	return VERSION;
}

/**
 * Prints the String Version
 */
void putsStringVersion(void)
{
	puts(getStringVersion());
}

/* ************************************************************************
 * STRING SECTION
 ************************************************************************ */
/**
 * String constructor
 * @param len The size, the number of bytes to be set to the value ptr.
 * @return A pointer to the new String variable
 */
String new_String(int len)
{
	String newString;

	if(!(newString = (String) malloc(sizeof(_String))))
	{
		errnum = errno;
		fprintf(stderr, "Error Allocating memory for new String: (%i) - %s\n", errnum, strerror(errnum));
		exit(errnum);
	}

	newString->size = len;
	if(!(newString->ptr = (char *) malloc(newString->size+1)))
	{
		errnum = errno;
		fprintf(stderr, "Error Allocating memory for new String->ptr: (%i) - %s\n", errnum, strerror(errnum));
		exit(errnum);
	}

	if (!memset(newString->ptr, 0, newString->size+1))
	{
		errnum = errno;
		fprintf(stderr, "Error Setting memory for new String: (%i) - %s\n", errnum, strerror(errnum));
		exit(errnum);
	}
	return newString;
}

/**
 *
 */
String new_StringFromChar(const char * str)
{
	String newString = new_String(strlen(str));
	strcpy(newString->ptr, str);
	return newString;
}

/**
 * Destructor of a String pointer
 * @param String The String pointer to free
 */
void free_String(String newString)
{
	free(newString->ptr);
	free(newString);
}

/**
 * Stores a string into the _String stucture, according its definition in a safe mode
 * Stores a maximum of the size of the memory reserved to the string, avoiding memory overflow
 * Copies up to String's size characters from cadena. In a case where the length of cadena is less than that of the String's size, the remainder of String will be padded with null bytes.
 * @param string The String variable
 * @param cadena The value to store in the String
 * @return returns the pointer to the String.
 */
String setString(String Str, char * cadena)
{
	char * ret;
	if (!memset(Str->ptr, 0, Str->size+1))
	{
		errnum = errno;
		fprintf(stderr, "Error Setting memory for String: (%i) - %s\n", errnum, strerror(errnum));
		exit(errnum);
	}
	if (!(ret = strncpy(Str->ptr, cadena, Str->size)))
	{
		errnum = errno;
		fprintf(stderr, "Error Setting content for String: (%i) - %s\n", errnum, strerror(errnum));
		exit(errnum);
	}
	return Str;
}

/**
 * Returns the char * to the string stored in a String variable
 * @param string The String variable to get its string
 * @return The string stored in the String Variable
 */
char * getString(String string)
{
	return string->ptr;
}

/**
 * Returns the amount of bytes of the string stored in a String variable. The maximimu size of the string that can be stores
 * @param string The String variable to get its string
 * @return The amount of bytes of the string stored in a String variable
 */
size_t getStringSize(String string)
{
	return string->size;
}

/**
 * Returns the length of the string stored
 * @param string The String variable to get its length
 * @return The length of the string stored
 */
size_t getStringLen(String string)
{
	return strlen(string->ptr);
}

/**
 * Returns the amount of memory allocated of the string created
 * @param string The String variable to get its amount of memory allocated
 * @return The amount of memory of the string created
 */
size_t getStringMemAlloc(String string)
{
	return string->size+1;
}

/**
 * Returns the size of memory of the String created
 * @param string The String variable to get its size of memory allocated
 * @return The size of memory of the String created
 */
size_t getStringMemSizeOf(String string)
{
	size_t stringSize = getStringMemAlloc(string);
	size_t StringSizeOf = sizeof(string);
	return stringSize + StringSizeOf;
}

/* ************************************************************************
 * C REMAKE
 ************************************************************************ */

/**
 * Replacement for puts
 */
int Puts(String s)
{
	return puts(s->ptr);
}

/**
 * Replacement for strcat
 * Unlike strcat, Strcat creates a completely new String with the concatenation
 * You should free_String() the new String
 * @param Str1 The first String
 * @param Str The first String
 * @return Returns a new String with the concatenation of Strin1 and String2
 */
String Strcat(String Str1, String Str2)
{
	String Strcat = new_String(getStringLen(Str1)+getStringLen(Str2));
	strcat(Strcat->ptr, Str1->ptr);
	strcat(Strcat->ptr, Str2->ptr);
	return Strcat;
}

/**
 * Replacement for strcpy
 * Unlike strcpy, Strcpy creates a completely new String with the concatenation
 * You should free_String() the new String
 * @param Str1 The String with the copy of Str2
 * @param Str2 The String to copy in Str1
 * @return Returns a new String with the copy of Str2 in Str1
 */
String Strcpy(String Str1, String Str2)
{
	if(getStringLen(Str2) > getStringLen(Str1))
	{
		free_String(Str1);
		String Str1 = new_String(getStringLen(Str2));
	}
	strcpy(Str1->ptr, Str2->ptr);
	return Str1;
}

/**
 * replacement for strcmp
 * @param Str1 The 1st String to compare
 * @param Str2 The 2nd String to compare
 * @return Returns 0 if the two Strings have the same string, otherwise a value that is not 0
 */
int Strcmp(String Str1, String Str2)
{
	return strcmp(Str1->ptr, Str2->ptr);
}


