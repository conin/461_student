//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2016
// Optimized C++
//----------------------------------------------------------------------------- 

#include <stdio.h>
#include <assert.h>
#include <string.h>

// locals
#include "output.h"
#include "PA4_C.h"


io::io()
	:fileHandle(0)
{
};

io::~io()
{
	if (0 != fileHandle)
	{
		privDestroy();
	}
};

void io::create(const char * const name)
{
	privGetInstance()->privCreate( name );
}

void io::destroy()
{
	privGetInstance()->privDestroy();
}

FILE *io::getHandle()
{
	return privGetInstance()->privGetHandle();
}

io *io::privGetInstance()
{
	static io instance;
	return &instance;
}

void io::privDestroy()
{
	errno_t fileError;
	assert( fileHandle );

	fileError = fflush( fileHandle );
	assert( !fileError );

	fileError = fclose( fileHandle);
	fileHandle = 0;
	assert( !fileError );	
}

void io::privCreate(const char * const name)
{
	errno_t fileError;



#ifdef _DEBUG

#if PROXY_ENABLE
	fileError = fopen_s(&fileHandle, "output_Proxy_Debug.txt", "wt");
	assert(fileHandle);

	fprintf(fileHandle, "Program Assignment: 4 \n");
	fprintf(fileHandle, "Name: %s\n", name);
	fprintf(fileHandle, "With Proxy\n");
#else
	fileError = fopen_s(&fileHandle, "output_NO_Proxy_Debug.txt", "wt");
	assert(fileHandle);

	fprintf(fileHandle, "Program Assignment: 4 \n");
	fprintf(fileHandle, "Name: %s\n", name);
	fprintf(fileHandle, "No Proxy\n");
#endif

#else

#if PROXY_ENABLE
	fileError = fopen_s(&fileHandle, "output_Proxy_Release.txt", "wt");
	assert( fileHandle );

	fprintf(fileHandle, "Program Assignment: 4 \n");
	fprintf(fileHandle,"Name: %s\n",name);
	fprintf(fileHandle, "With Proxy\n");
#else
	fileError = fopen_s(&fileHandle, "output_NO_Proxy_Release.txt", "wt");
	assert(fileHandle);

	fprintf(fileHandle, "Program Assignment: 4 \n");
	fprintf(fileHandle, "Name: %s\n", name);
	fprintf(fileHandle, "No Proxy\n");
#endif

#endif
}


FILE *io::privGetHandle()
{
	assert( fileHandle );
	return fileHandle;
}


