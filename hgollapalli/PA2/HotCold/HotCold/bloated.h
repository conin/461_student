//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2016
// Optimized C++
//----------------------------------------------------------------------------- 

#ifndef BLOATED_H
#define BLOATED_H

// forward declaration - always try to do this before including a header (Keenan)
class OriginalNode;

// needs to be this value, do not change in final submission
#define NUM_NODES 100000

class Bloated
	{
	public:
		// Big four
		Bloated();	
		~Bloated();
		Bloated(const Bloated &) = delete;
		Bloated & operator = (const Bloated &) = delete;

		// methods
		bool findKey(int key, OriginalNode &foundNode);
		OriginalNode *getListHead();

	private:
		// methods
		void privCreateLinkedList();

		// data
		OriginalNode *pHead;
	};


#endif //bloated.h
