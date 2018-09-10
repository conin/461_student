#include <stdio.h>
#include <string.h>

#include "ComparingStrings.h"
#define STUBBED_VAR(x) (void *)x

int StringCompare_1( const char  * const s1, const char * const s2)
{
	return strcmp(s1, s2);
}

int StringCompare_2( const char  * const s1, const char * const s2)
{
	// using memcmp() & strlen()
	return memcmp(s1, s2, strlen(s1));;
}

int StringCompare_3( const char  * const s1, const char * const s2)
{
	// using char by char comparisions
	int key = 0;
	unsigned int length = strlen(s1);

	for (unsigned int index = 0; index < length; index++)
	{
		if (s1[index] == s2[index])
		{
			
		}
		else
		{
			if (s1[index] > s2[index])
			{
				key = 1;
				break;
			}
			else
			{
				key = -1;
				break;
			}
		}
	}
	return key;
}

