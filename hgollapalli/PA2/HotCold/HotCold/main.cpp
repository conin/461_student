//-----------------------------------------------------------------------------
// Programming Assignment 2:
// Copyright Ed Keenan 2016
// Optimized C++
//----------------------------------------------------------------------------- 

#include <stdio.h>
#include <assert.h>

// User headers
#include "bloated.h"
#include "Node.h"
#include "output.h"
#include "Timer.h"

// Add your files here
#include "hotcold.h"

int main()
{
	//-----------------------------------------------------------------------------
	// 1) Create the output file and timers
	//-----------------------------------------------------------------------------

		// Create the IO for this program, that's your name BTW, please change it.
		io::create("Hanumanth G");

		// Initialize timer
		timer::initTimer();

		// Create a timer objects
		timer t1,t2,t3,t4,t5;

	//-----------------------------------------------------------------------------
	// 2) Create the Bloated Link List
	//-----------------------------------------------------------------------------
		
		// start timer
		t1.tic();

			// Do not modify this function, you need to leave this routine alone.
			// It initializes the data if a very bloated way do not modify it!
			Bloated *pBloated = new Bloated();

		// stop timer
		t1.toc();

		// log the time for the bloat creation
		fprintf(io::getHandle(),"Creation of Bloated List: %f s\n", t1.timeInSeconds() );
	
	//-----------------------------------------------------------------------------
	// 3) Find Specific Key: 0x78512b55
	//-----------------------------------------------------------------------------

		// find a specific key
		OriginalNode foundNode;

		// start timer
		t2.tic();

			// find a specific key
			bool foundFlag = pBloated->findKey(0x7ED551F2, foundNode);

		// stop timer
		t2.toc();

		float findingKeyOld = t2.timeInSeconds()*1000.0f;

		// log the time conversion and proof
		fprintf(io::getHandle(), "\n");
		fprintf(io::getHandle(), "Original linked list---------------------------\n");
		fprintf(io::getHandle(), "   Finding Key: %f ms\n", findingKeyOld);
		fprintf(io::getHandle(), " (Proof)   key: 0x%X\n", foundNode.key);
		fprintf(io::getHandle(), "       name[0]: %x\n", 0xff & foundNode.name[0]);
		fprintf(io::getHandle(), "      name[55]: %x\n", 0xff & foundNode.name[66]);
		fprintf(io::getHandle(), "     name[111]: %x\n", 0xff & foundNode.name[109]);
		fprintf(io::getHandle(), "     name[113]: %x\n", 0xff & foundNode.name[114]);
		fprintf(io::getHandle(), "             Y: %f\n", foundNode.y);
		fprintf(io::getHandle(), "         MB[4]: %f\n", foundNode.MB.m03);
		fprintf(io::getHandle(), "           A.z: %f\n", foundNode.A.z);

	//-----------------------------------------------------------------------------
	// 4) Convert to HotCold data structures
	//-----------------------------------------------------------------------------

		// start timer
		t3.tic();

			// -----------------------------------------------------------------------
			// --->>>>  Add your magic here
			//          Convert the bloated list to hot/cold
			// -----------------------------------------------------------------------

			HotCold *pHotCold = new HotCold( pBloated );

		// stop timer
		t3.toc();

		// log the time conversion
		fprintf(io::getHandle(),"\n");
		fprintf(io::getHandle(),"Conversion to Hot/Cold: %f ms\n", t3.timeInSeconds() * 1000.0f);

	//-----------------------------------------------------------------------------
	// 5) Find Key using the new Hot/Cold data structures
	//-----------------------------------------------------------------------------
		
		HotNode pNode;

		// start timer
		t4.tic();

			// -----------------------------------------------------------------------
			// --->>>>  Add your magic here, 
			//          Find key: 0x7ED551F2, add code here:
			// -----------------------------------------------------------------------
		foundFlag = pHotCold->findKey(0x7ED551F2, pNode);
		ColdNode coldTmp= *pNode.pColdObj;

		// stop timer
		t4.toc();

		// log the time conversion and proof
		float findingKeyNew = t4.timeInSeconds()*1000.0f;

		fprintf(io::getHandle(),"\n");
		fprintf(io::getHandle(),"Hot/Cold linked list---------------------------\n");
		fprintf(io::getHandle(), "   Finding Key: %f ms\n", findingKeyNew);

		// <----- Uncomment the following 8 lines for submission

		fprintf(io::getHandle(), " (Proof)   key: 0x%X\n", pNode.key);
		fprintf(io::getHandle(), "       name[0]: %x\n", 0xff & coldTmp.name[0]);
		fprintf(io::getHandle(), "      name[55]: %x\n", 0xff & coldTmp.name[66]);
		fprintf(io::getHandle(), "     name[111]: %x\n", 0xff & coldTmp.name[109]);
		fprintf(io::getHandle(), "     name[113]: %x\n", 0xff & coldTmp.name[114]);
		fprintf(io::getHandle(), "             Y: %f\n", coldTmp.y);
		fprintf(io::getHandle(), "         MB[4]: %f\n", coldTmp.MB.m03);
		fprintf(io::getHandle(), "           A.z: %f\n", coldTmp.A.z);

	//-----------------------------------------------------------------------------
	// 6) Verify new Hot/Cold data structures vs Original bloated
	//-----------------------------------------------------------------------------

		// start timer
		t5.tic();

			// --------------------------------------------------------------------------------------
			// --->>>>  Add your magic here, 
			//          Verify all data nodes between Original and New Hot/Cold
			// ---------------------------------------------------------------------------------------
			pHotCold->verify( pBloated );

		// stop timer
		t5.toc();

		// log the time conversion
		fprintf(io::getHandle(),"\n");
		fprintf(io::getHandle(),"Verify Nodes: Original and New Hot/Cold : %f ms\n", t5.timeInSeconds()*1000.0f );

		fprintf(io::getHandle(),"\n");
		fprintf(io::getHandle(),"------ Summary ------------------------------------- \n\n");
		fprintf(io::getHandle(),"                 orig: %f ms \n", findingKeyOld );
		fprintf(io::getHandle(),"                  new: %f ms \n", findingKeyNew );
		fprintf(io::getHandle(),"                ratio: %f \n", findingKeyOld/findingKeyNew );

	// Clean up dynamic memory
		delete pBloated;
	delete pHotCold;

	io::destroy();
}

