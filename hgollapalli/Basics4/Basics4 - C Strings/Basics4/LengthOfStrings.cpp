
#include <stdio.h>
#include <string.h>

#include"LengthOfStrings.h"

#define STUBBED_VAR(x) (void *)x


size_t LengthOfString_1( const char  * const input)
{
	// using strlen()
	return strlen(input);
}

size_t LengthOfString_2( const char  * const input)
{
	// using char by char
	unsigned int len = 0;
	for (unsigned int index = 0; input[index] != NULL; index++)
		len += 1;

	return len;
}
