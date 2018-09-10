// main.cpp : Defines the entry point for the console application.
//

void StressTest( );

#include "PA4_A.h"
#include "timer.h"
#include "output.h"

int main()
{
	// You need to run this 4 times for timing

	// IMPLICIT_CONVERSIONS  0
	//     1) Run Debug
	//     2) Run Release
	// IMPLICIT_CONVERSIONS  1
	//     3) Run Debug
	//     4) Run Release

	// Modify the code to create implicit compiler error
	//     Compile and record the errors

	// Cut and Paste all the above to stuff to mimic the sample output file
	//      Keenan_Summary_Output.txt


	// Create the IO for this program, that's WHERE YOU PUT YOUR NAME, please change it.
	io::create("Hanumanth");

	// Initialize timer
	timer::initTimer();

	// Create a timer objects
	timer t1;

	// start timer
	t1.tic();

	for (int i = 0; i < 1000000; i++)
	{
		// take a look inside this function
		StressTest();
	}

	// stop timer
	t1.toc();

	// log the time for the implicit creation
#if IMPLICIT_CONVERSIONS
	fprintf(io::getHandle(),"Run with Implict conversions: %f ms\n", t1.timeInSeconds()* 1000.0f );
#else
	fprintf(io::getHandle(), "Run with NO Implict conversions: %f ms\n", t1.timeInSeconds()* 1000.0f);
#endif
	return(0);
}

