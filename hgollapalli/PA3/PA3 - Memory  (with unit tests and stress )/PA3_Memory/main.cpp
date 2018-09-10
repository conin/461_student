#include "UnitTest.h"
#include "Trace.h"

// Prototypes
void MemStressTest();

int main()
{

	// ---- Grading: ------------------------------------------------------

	// TOTAL of 15 unit tests in total, plus 1 stress test
	//        the stress tests counts for 10 more points
	// So you can get a total of 25/25 points

	//----------------------------------------------------------------
	// Leave the following functions allow
	// DO NOT reorder them
	//----------------------------------------------------------------

	TestRegistry::RunTests();

	//----------------------------------------------------------------
	// Leave the following functions allow
	// DO NOT reorder them
	//----------------------------------------------------------------

		// Stress test
	Trace::out("Stress test: started");
		MemStressTest();
	Trace::out("Stress test: done");
	// ---------------------------------------------------------------
	// remember to do many prints and stat updates.
	// enjoy and have fun
	// ---------------------------------------------------------------

}

