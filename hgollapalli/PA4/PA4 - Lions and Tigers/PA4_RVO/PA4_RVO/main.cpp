// main.cpp : Defines the entry point for the console application.
//

void StressTest( );

#include "PA4_B.h"
#include "timer.h"
#include "output.h"

int main()
{
	// You need to run this 4 times for timing

	// RVO_ENABLE  0
	//     1) Run Debug
	//     2) Run Release
	// RVO_ENABLE  1
	//     3) Run Debug
	//     4) Run Release

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

	for (int i = 0; i < 5000000; i++)
	{
	   StressTest();
	}

	// stop timer
	t1.toc();

	// log the time for the implicit creation
#if RVO_ENABLE
	fprintf(io::getHandle(),"Run WITH RVO: %f ms\n", t1.timeInSeconds()* 1000.0f );
#else
	fprintf(io::getHandle(), "Run NO RVO: %f ms\n", t1.timeInSeconds()* 1000.0f);
#endif

	return(0);
}

