//-----------------------------------------------------------------------------
// Programming Assignment 6:
// Copyright Ed Keenan 2016
// Optimized C++
//----------------------------------------------------------------------------- 

#include <stdio.h>
#include <assert.h>

// User headers
#include "OList.h"
#include "Node.h"
#include "output.h"
#include "Timer.h"
#include "Trace.h"

// Add your files here


int main()
{
	//-----------------------------------------------------------------------------
	// 1) Create the output file and timers
	//-----------------------------------------------------------------------------

		// Create the IO for this program, that's your name BTW, please change it.
		io::create("Hanumanth");

		// Initialize timer
		timer::initTimer();

		// Create a timer objects
		timer t1, t2, t3, t4, t5, t6, t7, t8;

		// Original List
		OList *pOList = 0;

	//-----------------------------------------------------------------------------
	// 2) Create the original Link List timing
	//-----------------------------------------------------------------------------

		// start timer
		t1.tic();
			// Do not modify or data this function, you need to leave this routine alone.
			pOList = new OList();
		t1.toc();

		// find a specific key
		Node foundNode;
		t2.tic();
			bool foundFlag = pOList->FindKey(0x7f9e1b10, foundNode);
		t2.toc();

		// log the time conversion and proof
		fprintf(io::getHandle(), "Creation of original List: %f ms\n", t1.timeInSeconds() * 1000.0f);
		fprintf(io::getHandle(), "\n");
		fprintf(io::getHandle(), "Original linked list---------------------------\n");
		fprintf(io::getHandle(), "   Finding Key: %f ms\n", t2.timeInSeconds()*1000.0f);
		fprintf(io::getHandle(), " (Proof)   key: 0x%X  x:%d y:%d z:%d flag:%d\n", foundNode.key, foundNode.x, foundNode.y, foundNode.z, foundFlag);
		delete pOList;

	//-----------------------------------------------------------------------------
	// 3) Insertion Sort Timing
	//-----------------------------------------------------------------------------

		pOList = new OList();
		t3.tic();
			// ---------------------------------------------------------
			// ---->  Create this function, use insertion sort  <-------
			// ---------------------------------------------------------
			pOList->InsertionSort();
		t3.toc();

		fprintf(io::getHandle(), "\n     Insertion Time: %f ms\n", t3.timeInSeconds() * 1000.0f);
		delete pOList;

	//-----------------------------------------------------------------------------
	// 4) Merge Sort Timing
	//-----------------------------------------------------------------------------

		pOList = new OList();
		t4.tic();
			// -----------------------------------------------------
			// ---->  Create this function, use Merge sort  <-------
			// -----------------------------------------------------
			//Trace::out("\n Started here ");
			Node *pHead = pOList->privGetHead();
			//Trace::out("\n %x ",pHead);
			pOList->MergeSort(&pHead);
			//Trace::out("\n End here ");

		t4.toc();

		fprintf(io::getHandle(), "         Merge Time: %f ms\n", t4.timeInSeconds() * 1000.0f);
		delete pOList;

	//-----------------------------------------------------------------------------
	// 5) (Merge/Insert)Combo Timing
	//-----------------------------------------------------------------------------

		int CutoffLength = 13;  // <----experiment with this number for best results
		pOList = new OList();
		t5.tic();
			// -----------------------------------------------------------------------
			// ---->  Create this function, Merge Sort with Insertion Sort <---------- 
			// -----------------------------------------------------------------------
			// -----  CutoffLength is length that determines when to used   ----------
			// -----  Insertion Sort instead of Merge Sort for sublist of   ----------
			// -----  of smaller lengths                                    ---------- 
			// -----------------------------------------------------------------------
			pOList->MergeComboSort(CutoffLength);
		t5.toc();

		fprintf(io::getHandle(), "  Merge/Insert Time: %f ms   Cutoff length: %d\n", t5.timeInSeconds() * 1000.0f, CutoffLength);
		fprintf(io::getHandle(), "\n  Merge vs Merge/Insert: %f faster\n", t4.timeInSeconds() / t5.timeInSeconds());
		delete pOList;
		
	//-----------------------------------------------------------------------------
	// 6) Write data (OList) to File
	//-----------------------------------------------------------------------------

		OList *pOriginalOList = new OList();

		t6.tic();

			// Do your magic here:
			//		Add methods and functions as you see fit
			//		Needs to be in Binary, use fopen,fread,fwrite,etc... 
			//		Needs to use these functions for consistent timing across class
			//		No Streams/boost/STL/modern C++
			// ------------------------------------------------------------------------
			// Using pOriginalOList... walk the list, create and place into a binary file 
			//                   make sure you close the file after you fill it with data
			// GRAD Students:
			//     This file needs to be LOAD in PLACE file
			//     Watch lecture, read the notes
			// UNDERGRADS students:
			//     You aren't required to do LOAD in PLACE file
			//     It might be fun to try....
		
			pOriginalOList->InsertIntoFile();
			
		t6.toc();

		fprintf(io::getHandle(), "\n    Time to create File: %f ms  \n", t6.timeInSeconds() * 1000.0f);


	//-----------------------------------------------------------------------------
	// 7) Read data from File to OList
	//-----------------------------------------------------------------------------

		OList *pNewOList=new OList(0);

		t7.tic();

			// Do your magic here:
			//		Add methods and functions as you see fit
			//		Needs to be in Binary, use fopen,fread,fwrite,etc... 
			//		Needs to use these functions for consistent timing across class
			//		No Streams/boost/STL/modern C++
			// ------------------------------------------------------------------------
			// Using your file systemp, read and reconstruct a new OList into pNewOlist
			//                 Make sure you close the file after you the creation 
			// GRAD Students:
			//     This file needs to be "LOAD in PLACE" flie
			//	   Recreation of List should not be more than 2 or 3 new() calls in total
			//     Watch lecture, read the notes
			// UNDERGRADS students:
			//     You aren't required to do LOAD in PLACE file
			//     It might be fun to try....

		pNewOList->ReadFromFile();

		t7.toc();

		fprintf(io::getHandle(), "  Time to recreate list: %f ms  \n", t7.timeInSeconds() * 1000.0f);

	//-----------------------------------------------------------------------------
	// 8) Verify data
	//-----------------------------------------------------------------------------

		t8.tic();
			bool VerifyResult = OList::Verify(pNewOList, pOriginalOList);
		t8.toc();

		fprintf(io::getHandle(), "\n  Verify Time: %f ms  Result: %d\n", t8.timeInSeconds() * 1000.0f, VerifyResult);
		delete pOriginalOList;
		delete pNewOList;

		io::destroy();
}

