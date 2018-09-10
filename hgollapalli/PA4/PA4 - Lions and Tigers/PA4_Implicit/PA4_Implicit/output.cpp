#include <stdio.h>
#include <assert.h>
#include "output.h"
#include "PA4_A.h"

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

	#if IMPLICIT_CONVERSIONS
		fileError = fopen_s(&fileHandle,"output_Implicit_Debug.txt","wt");
		assert(fileHandle);

		fprintf(fileHandle,"Program Assignment: 4 \n");
		fprintf(fileHandle,"Name: %s\n",name);
		fprintf(fileHandle, "Implicit Conversions\n");
	#else
		fileError = fopen_s(&fileHandle, "output_NO_Implicit_Debug.txt", "wt");
		assert(fileHandle);

		fprintf(fileHandle, "Program Assignment: 4 \n");
		fprintf(fileHandle, "Name: %s\n", name);
		fprintf(fileHandle, "No Implicit Conversions\n");
	#endif

#else

	#if IMPLICIT_CONVERSIONS
		fileError = fopen_s(&fileHandle, "output_Implicit_Releast.txt", "wt");
	assert( fileHandle );

		fprintf(fileHandle, "Program Assignment: 4 \n");
	fprintf(fileHandle,"Name: %s\n",name);
		fprintf(fileHandle, "Implicit Conversions\n");
	#else
		fileError = fopen_s(&fileHandle, "output_NO_Implicit_Release.txt", "wt");
		assert(fileHandle);

		fprintf(fileHandle, "Program Assignment: 4 \n");
		fprintf(fileHandle, "Name: %s\n", name);
		fprintf(fileHandle, "No Implicit Conversions\n");
	#endif

#endif
	
}


FILE *io::privGetHandle()
{
	assert( fileHandle );
	return fileHandle;
}


