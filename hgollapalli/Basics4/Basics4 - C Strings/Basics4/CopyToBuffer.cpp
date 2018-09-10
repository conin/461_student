#include <stdio.h>
#include <string.h>

#include "CopyToBuffer.h"
#define STUBBED_VAR(x) (void *)x

// retrieve the message
char * dog::getMessage()
{
	return this->buff;
}
	
// user sets the message
void dog::setMessage( const char * const inMessage )
{
	// Do the copy to internal variable buff
	// make sure it's safe
	// ----> do work here
	if (inMessage == NULL)
		this->buff[0] = '\0';
	else
	{
		memcpy(this->buff, inMessage, BUFF_SIZE-1);
		this->buff[BUFF_SIZE-1] = '\0';
	}
	STUBBED_VAR(inMessage);
}

// prints the mesage
void dog::print()
{
	printf("message: %s\n",this->buff);
}


dog::dog()
{
	memset( this->buff, 0xaa, BUFF_SIZE );
}

dog::~dog()
{
	memset( this->buff, 0xaa, BUFF_SIZE );
}


