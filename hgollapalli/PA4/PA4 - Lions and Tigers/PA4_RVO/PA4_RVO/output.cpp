#include <stdio.h>
#include <assert.h>
#include "output.h"
#include "PA4_B.h"


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

#if RVO_ENABLE
	fileError = fopen_s(&fileHandle, "output_RVO_Debug.txt", "wt");
	assert( fileHandle );

	fprintf(fileHandle, "Program Assignment: 4 \n");
	fprintf(fileHandle,"Name: %s\n",name);
	fprintf(fileHandle, "With RVO\n");
#else
	fileError = fopen_s(&fileHandle, "output_NO_RVO_Debug.txt", "wt");
	assert(fileHandle);

	fprintf(fileHandle, "Program Assignment: 4 \n");
	fprintf(fileHandle, "Name: %s\n", name);
	fprintf(fileHandle, "No RVO\n");
#endif

#else

#if RVO_ENABLE
	fileError = fopen_s(&fileHandle, "output_RVO_Release.txt", "wt");
	assert(fileHandle);

	fprintf(fileHandle, "Program Assignment: 4 \n");
	fprintf(fileHandle, "Name: %s\n", name);
	fprintf(fileHandle, "With RVO\n");
#else
	fileError = fopen_s(&fileHandle, "output_NO_RVO_Release.txt", "wt");
	assert(fileHandle);

	fprintf(fileHandle, "Program Assignment: 4 \n");
	fprintf(fileHandle, "Name: %s\n", name);
	fprintf(fileHandle, "No RVO\n");
#endif

#endif
}


FILE *io::privGetHandle()
{
	assert( fileHandle );
	return fileHandle;
}


