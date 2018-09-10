//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2016
// Optimized C++
//----------------------------------------------------------------------------- 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "Trace.h"

// Users
#include "bloated.h"
#include "Node.h"
#include "hotcold.h"


#define UNUSED_VAR(x) ((void )x)

HotNode::HotNode()
{
	this->key = 0;
	this->prev = '\0';
	this->next = '\0';
}

HotNode::HotNode(HotNode &p)
{
	this->key = p.key;
	this->prev = p.prev;
	this->next = p.next;
	this->pColdObj = 0;
}

HotNode& HotNode::operator=(HotNode &p)
{
	this->key = p.key;
	this->prev = p.prev;
	this->next = p.next;
	this->pColdObj = p.pColdObj;
	return p;
}

HotNode::~HotNode()
{
	this->key = 0;
	this->next = 0;
	this->prev = 0;
	this->pColdObj = 0;
}

ColdNode::ColdNode()
{

}

ColdNode & ColdNode::operator=(ColdNode &p)
{
	this->A = p.A;
	this->B = p.B;
	this->C = p.C;
	this->MA = p.MA;
	this->MB = p.MB;
	this->MC = p.MC;
	this->x = p.x;
	this->y = p.y;
	this->z = p.z;
	memcpy(this->name, p.name, NAME_SIZE);
	return p;
}

ColdNode::ColdNode(ColdNode &p)
{
	this->A = p.A;
	this->B = p.B;
	this->C = p.C;
	this->MA = p.MA;
	this->MB = p.MB;
	this->MC = p.MC;
	this->x = p.x;
	this->y = p.y;
	this->z = p.z;
	memcpy(this->name, p.name, NAME_SIZE);
}

ColdNode::~ColdNode()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}



void HotCold::privCreateLinkedList()
{
	// initialize it NULL
	this->hotHead = 0;

	// Reset the seed
	// NO-ONE should ever call this function
	// it is here to insure that everyone's seed is the same.
	// Do not change or recall srand anywhere
	srand(2017);

	// create the nodes
	// this function magically initialize all the date with a set pattern
	HotNode *p = new  HotNode[NUM_NODES];
	ColdNode *pCold = new ColdNode[NUM_NODES];

	// head
	this->hotHead = p;

	// some markers...
	HotNode *pFirst = p;
	HotNode *pLast = p + NUM_NODES - 1;
	HotNode *pCurr = pFirst;

	// initialize the all nodes
	for (int i = 0; i < NUM_NODES; ++i)
	{
		pCurr->next = pCurr + 1 ;
		pCurr->prev = pCurr - 1;
		pCurr->pColdObj = pCold;
		pCurr++;
		pCold++;
	}

	// fix up the first and last node
	pLast->next=0;
	pFirst->prev=0;
}

HotCold::HotCold(Bloated *pBloated)
{
	this->privCreateLinkedList();

	OriginalNode *BloatedTemp = pBloated->getListHead();

	HotNode *temp = HotCold::hotHead;

	for (int i = 0; i < NUM_NODES; i++)
	{
		temp->pColdObj->A  = BloatedTemp->A;
		temp->pColdObj->B  = BloatedTemp->B;
		temp->pColdObj->C  = BloatedTemp->C;
		temp->pColdObj->MA = BloatedTemp->MA;
		temp->pColdObj->MB = BloatedTemp->MB;
		temp->pColdObj->MC = BloatedTemp->MC;
		temp->pColdObj->MD = BloatedTemp->MD;
		temp->pColdObj->x  = BloatedTemp->x;
		temp->pColdObj->y  = BloatedTemp->y;
		temp->pColdObj->z  = BloatedTemp->z;
		temp->key = BloatedTemp->key;
		memcpy(temp->pColdObj->name, BloatedTemp->name, NAME_SIZE);
		temp = temp + 1;
		BloatedTemp = BloatedTemp + 1;
	}
}


void HotCold::print()
{
	HotNode *p = this->hotHead;

	while(p!=0)
	{
		Trace::out(" %d -> ",p->key);
		p = (HotNode *)p->next;
	}
}

bool HotCold::findKey(int key, HotNode &found)
{
	HotNode *ptmp = this->hotHead;
	bool status = false;

	while(ptmp!=0)
	{
		if(ptmp->key==key)
		{
			found = *ptmp;
			found.pColdObj = ptmp->pColdObj;
			memcpy(found.pColdObj->name, ptmp->pColdObj->name, NAME_SIZE);
			status = true;
			break;
		}			
		ptmp = (HotNode *)ptmp->next;
	}
	return status;
}


bool HotCold::verify(Bloated *pBloated)
{
	HotNode *tmp = this->hotHead;
	OriginalNode *t2 = pBloated->getListHead();
	bool status = false;

	while (tmp!=0 && t2!=0)
	{
		 if((tmp->pColdObj->MD == t2->MD) &&
			(tmp->pColdObj->MA == t2->MA) &&
			(tmp->pColdObj->MB == t2->MB) &&
			(tmp->pColdObj->MC == t2->MC) &&
			(tmp->pColdObj->A == t2->A)	  &&
			(tmp->pColdObj->B == t2->B)	  &&
			(tmp->pColdObj->C == t2->C)	  &&
			(tmp->pColdObj->x == t2->x)	  &&
			(tmp->pColdObj->y == t2->y)	  &&
			(tmp->pColdObj->z == t2->z)	  &&
			(tmp->key == t2->key)		  &&
			(strcmp((tmp->pColdObj->name), (t2->name)) == 0))
		{
			status = true;
		}
		tmp = (HotNode *)tmp->next;
		t2 = t2->getNext();
	}
	return status;
}
