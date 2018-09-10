//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2016
// Optimized C++
//----------------------------------------------------------------------------- 

#include <stdlib.h>
#include <assert.h>

// user headers
#include "bloated.h"
#include "Node.h"
#include "Trace.h"
#include <string.h>

void Bloated::privCreateLinkedList()
{
	// initialize it NULL
	this->pHead = 0;

	// Reset the seed
	// NO-ONE should ever call this function
	// it is here to insure that everyone's seed is the same.
	// Do not change or recall srand anywhere
	srand(2017);

	// create the nodes
	// this function magically initialize all the date with a set pattern
	OriginalNode *p = new  OriginalNode[NUM_NODES];

	// head
	this->pHead = p;

	// some markers...
	OriginalNode *pFirst = p;
	OriginalNode *pLast  = p + NUM_NODES - 1;
	OriginalNode *pCurr = pFirst;

	// initialize the all nodes
	for( int i = 0; i < NUM_NODES; ++i )
	{
		pCurr->setNext(pCurr + 1);
		pCurr->setPrev(pCurr - 1);
		//Trace::out(" %d ",strlen(pCurr->name));
		pCurr++;
	}

	// fix up the first and last node
	pLast->setNext(0);
	pFirst->setPrev(0);
}


OriginalNode *Bloated::getListHead()
{
	return pHead;
}

bool Bloated::findKey(int key, OriginalNode &foundNode)
{
	bool foundFlag(false);
	int inx = 0;
	OriginalNode *p = Bloated::getListHead();
	
	// Loop until you find a node
	while( p != 0 )
	{
		// is this the node?
		if( p->key == key)
		{
			// yes, then break
			foundFlag = true;
			foundNode = *p;
			//Trace::out("\n found at %d and string length %d",inx,strlen(foundNode.name));
			break;
		}
		inx++;
		// go to next
		p = p->next;
	}

	// flag
	return foundFlag;
}

Bloated::Bloated()
{
	this->privCreateLinkedList();
}

Bloated::~Bloated()
{
	// it was created with array new, so you use delete array
	delete[] this->pHead;
	this->pHead = 0;
}