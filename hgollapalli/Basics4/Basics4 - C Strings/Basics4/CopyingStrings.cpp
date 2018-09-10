#include <stdio.h>
#include <string.h>

#include "CopyingStrings.h"
#define STUBBED_VAR(x) (void *)x
 

char *StringCopy_1( char * const dest, const char * const input)
{
	// using strcpy()
	strcpy(dest, input);
	return dest;
}

char *StringCopy_2( char  * const dest, const char * const input)
{
	// using memcpy() and strlen()
	memcpy(dest, input, strlen(dest));
	return dest;
}

char *StringCopy_3( char  * const dest, const char * const input)
{
	// using char by char copies
	for (unsigned int index = 0; index < strlen(dest); index++)
		dest[index] = input[index];

	return dest;
}

