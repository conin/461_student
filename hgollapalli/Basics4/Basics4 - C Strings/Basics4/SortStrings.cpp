#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#include "SortStrings.h"
#define STUBBED_VAR(x) (void *)x


int StringCompare(const void * s1, const void * s2)
{
	const char * a = *(const char **)s1;
	const char * b = *(const char **)s2;

	return strcmp(a, b);
}

void ReorderAlphabetical(const char * const inString, char * const outString )
{
	// 1) reorder the words in the string, words are separated with spaces
	// 2) sort words on alphabetical order, (a begin, z end)
	// 3) you don't know how many words 
	// 4) if dynamically create any buffers inside this routine, clean them up
	// 5) use strtok and strcat in your answer
	// 6) hint: qsort() - might be a good function to know

	strcpy(outString, "\0");
	char *dest[1024];
	unsigned int index = 0;
	char *buff = new char[strlen(inString)];
	strcpy(buff, inString);
	

	char *s = strtok(buff, " ");	
	while (s != NULL)
	{
		dest[index] = s;
		s = strtok(NULL, " ");
		index++;
	}

	qsort(dest, index, sizeof(index), StringCompare);

	for (unsigned int i = 0; i < index; i++)
	{
		strcat(outString, dest[i]);
		if (i + 1 != index)
			strcat(outString, " ");
	}
}


int StringCompareLength(const void * s1, const void * s2)
{
	int ret = 0;
	const char * first = *(const char **)s1;
	const char * second = *(const char **)s2;
	unsigned int delta = strlen(first) - strlen(second);	

	if (delta != 0)
		ret=(int)delta;
	else if (second != 0 && first != 0)
		ret=StringCompare(s1, s2);

	return ret;
}


void ReorderWordLength(const char * const inString, char * const outString )
{
	// 1) reorder the words in the string, words are separated with spaces
	// 2) sort words on their word length order, (short, longest)
	// 3) you don't know how many words 
	// 4) if dynamically create any buffers inside this routine, clean them up
	// 5) use strtok and strcat in your answer
	// 6) hint: qsort() - might be a good function to know

	strcpy(outString, "\0");
	char *dest[1024];
	unsigned int index = 0;
	char *buff = new char[strlen(inString)];
	strcpy(buff, inString);


	char *s = strtok(buff, " ");
	while (s != NULL)
	{
		dest[index] = s;
		s = strtok(NULL, " ");
		index++;
	}

	qsort(dest, index, sizeof(index), StringCompareLength);

	for (unsigned int i = 0; i < index; i++)
	{
		strcat(outString, dest[i]);
		if (i + 1 != index)
			strcat(outString, " ");
	}
}