#include <stdio.h>
#include <assert.h>

#include "PA4_C.h"
#include "timer.h"
#include "output.h"

void StressTest();

int main()
{
	// You need to run this 4 times for timing

	// PROXY_ENABLE  0
	//     1) Run Debug
	//     2) Run Release
	// PROXY_ENABLE  1
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

	for (int i = 0; i < 50000000; i++)
	{
	   StressTest();
	}

	// stop timer
	t1.toc();

	double timeInMs = t1.timeInSeconds()*1000.0f;

#if PROXY_ENABLE
		fprintf(io::getHandle(),"Run WITH proxy objects: %f ms\n", timeInMs);
#else
		fprintf(io::getHandle(),"Run NO proxy objects: %f ms\n", timeInMs);
#endif

	return(0);
}

