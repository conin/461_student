//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2016
// Optimized C++
//----------------------------------------------------------------------------- 

#include <stdlib.h>
#include <assert.h>
#include <list>

// user headers
#include "OList.h"
#include "Node.h"
#include "Trace.h"
#include <stdio.h>

#define UNUSED_VAR(v) ((void *)v)
LoadInPlace *p1 = 0;

int small =0 , large=0, length=0;


void OList::privCreateLinkedList()
{
	// initialize it NULL
	this->pHead = 0;

	// Reset the seed
	// NO-ONE should ever call this function
	// it is here to insure that everyone's seed is the same.
	// Do not change or recall srand anywhere
	srand(2017);

	// create the nodes
	Node *pCurr = new Node();
	pCurr->setPrev(0);
	this->pHead = pCurr;
	Node *pPrev = pCurr;

	// initialize the all nodes
	for( int i = 0; i < NUM_NODES-1; ++i )
	{
		pCurr = new Node();

		// Update links
		pCurr->setPrev(pPrev);

		if (pPrev != 0)
		{
			pPrev->setNext(pCurr);
		}

		pPrev = pCurr;
	}

	// last node
	pCurr->setNext(0);

}


void  OList::ReadFromFile()
{
	int lSize  ;
	size_t result;
	char* buffer;
	FILE *f;
	errno_t err;

	err = fopen_s(&f, "InPlaceHdr", "rb");
	if (err == 0)
	{
		result = fread(p1, 1 , (size_t)sizeof(LoadInPlace), f);
		fclose(f);
		
		lSize = p1->ptr;
		// read/write in binary mode
		err = fopen_s(&f, "List", "rb");
		if (err == 0)
		{
			buffer = (char*)malloc((size_t)p1->blockSize);

			if (buffer == NULL)
			{
				Trace::out("Memory error", stderr);
				exit(2);
			}

			result = fread(buffer, (size_t) sizeof(Node), (size_t)p1->ptr, f);

			if (result == 0)
			{
				ferror(f);
			}
			Node *last = 0;

			//Node *currentList;
			while (lSize > 0)
			{
				Node *pNode = new(buffer)Node(buffer);

				if (lSize == p1->ptr)
				{
					pHead = pNode;
					last = pHead;
				}
				else
				{
					pNode->setNext(pHead);
					pNode->getNext()->setPrev(pNode);
					pHead = pNode;
				}

				buffer += sizeof(Node);
				lSize--;
			}

			pHead = last;
		}
	}
	else
	{

	}
}

void OList::InsertIntoFile()
{
	FILE *f;
	errno_t err;
	char *buffer,*bkp;

	err = fopen_s(&f,"InPlaceHdr", "wb+");
	if(err==0)
	{
		p1 = new LoadInPlace();
		Node *pTmp = this->pHead;

		while (pTmp != 0)
		{
			p1->ptr++;
			pTmp = pTmp->getNext();
		}
		p1->blockSize = (int)(p1->ptr * sizeof(Node));
		fwrite(p1, 1, (size_t)sizeof(p1), f);
		fclose(f);

		err = fopen_s(&f, "List", "wb+");
		if (err == 0)
		{
			buffer = (char*)malloc((size_t)p1->blockSize);

			pTmp = this->pHead;
			buffer = (char*)pTmp;
			bkp = buffer;

			while (pTmp != 0)
			{
				buffer = (char*)pTmp;
				buffer += sizeof(Node);
				fwrite(pTmp, 1, (size_t)sizeof(Node), f);

				pTmp = pTmp->pNext;
			}
			size_t ele = fwrite(bkp, 1, (size_t)p1->ptr, f);
			Trace::out("\n Elemets %d", ele);
		}
		else
		{
			Trace::out("\n ----Error in creating and opening file List.txt----");
		}
	}
	

	fclose(f);
}

void OList::Print(int count)
{
	Node *pTmp = this->pHead;

		while (pTmp != 0)
	{
		Trace::out("\n");
		/*Trace::out("addr:%p \n", pTmp);
		Trace::out("next:%p \n", pTmp->pNext);
		Trace::out("prev:%p \n", pTmp->pPrev);*/
		Trace::out("%u \t", pTmp->key);
		/*Trace::out("\t  x:%u", pTmp->x);
		Trace::out("\t  y:%u", pTmp->y);
		Trace::out("\t  z:%u", pTmp->z);*/
		pTmp = pTmp->pNext;

		if (--count <= 0)
		{
			break;
		}
	}
}


Node* SortedMerge(Node* a, Node* b)
{
	Node* result = NULL;

	/* Base cases */
	if (a == NULL)
		return(b);
	else if (b == NULL)
		return(a);

	/* Pick either a or b, and recur */
	if (a->key <= b->key)
	{
		result = a;
		result->pNext = SortedMerge(a->pNext, b);
	}
	else
	{
		result = b;
		result->pNext = SortedMerge(a, b->pNext);
	}
	return(result);
}

void sortedInsert(Node** head_ref, Node* new_node)
{
	Node* current;
	/* Special case for the head end */
	if (*head_ref == NULL || (*head_ref)->key >= new_node->key)
	{
		new_node->pNext = *head_ref;
		*head_ref = new_node;
	}
	else
	{
		/* Locate the node before the point of insertion */
		current = *head_ref;
		while (current->pNext != NULL &&
			current->pNext->key < new_node->key)
		{
			current = current->pNext;
		}
		new_node->pNext = current->pNext;
		current->pNext = new_node;
	}
}

/* Split the nodes of the given list into front and back halves,
and return the two lists using the reference parameters.
If the length is odd, the extra node should go in the front list.
Uses the fast/slow pointer strategy.  */
void FrontBackSplit(Node* source,
					Node** frontRef,
					Node** backRef)
{
	Node* fast;
	Node* slow;
	if (source == NULL || source->pNext == NULL)
	{
		/* length < 2 cases */
		*frontRef = source;
		*backRef = NULL;
	}
	else
	{
		slow = source;
		fast = source->pNext;

		/* Advance 'fast' two nodes, and advance 'slow' one node */
		while (fast != NULL)
		{
			fast = fast->pNext;
			if (fast != NULL)
			{
				slow = slow->pNext;
				small += 1;
				fast = fast->pNext;
				large += 2;
			}
		}

		/* 'slow' is before the midpoint in the list, so split it in two
		at that point. */
		*frontRef = source;
		*backRef = slow->pNext;
		slow->pNext = NULL;
	}
}


void OList::mergeInsert(Node** head)
{
	Node* a;
	Node* b;


	FrontBackSplit(*head, &a, &b);

	/* Recursively sort the sublists */
	//Trace::out(" \n Small %d - %d",small,large);
	if(small>length)
	{
		large = small = 0;
		mergeInsert(&a);
		mergeInsert(&b);
		SortedMerge(a, b);
	}
	else
	{
		Node *sorted = NULL;

		// Traverse the given linked list and insert every
		// node to sorted
		Node *current = a;
		while (current != NULL)
		{
			// Store next for next iteration
			Node *next = current->pNext;

			// insert current in sorted linked list
			sortedInsert(&sorted, current);

			// Update current
			current = next;
		}

		current = b;
		while (current != NULL)
		{
			// Store next for next iteration
			Node *next = current->pNext;

			// insert current in sorted linked list
			sortedInsert(&sorted, current);

			// Update current
			current = next;
		}
	}

	/* answer = merge the two sorted lists together */
	//SortedMerge(a,b);
}

void OList::MergeComboSort(int CutoffLength)
{
	length = CutoffLength;

	/* Base case -- length 0 or 1 */
	//Trace::out("\n %d ", (head == NULL) || (head->pNext == NULL));
	if ((this->pHead == NULL) || (this->pHead->pNext == NULL))
	{
		return;
	}

	/* Split head into 'a' and 'b' sublists */
	mergeInsert(&pHead);
}



Node* OList::privGetHead()
{
	if (pHead == 0)
		pHead = new Node();
	return pHead;
}

/* sorts the linked list by changing next pointers (not data) */
void OList::MergeSort(Node** headRef)
{
	Node* head = *headRef;
	Node* a;
	Node* b;

	/* Base case -- length 0 or 1 */
	//Trace::out("\n %d ", (head == NULL) || (head->pNext == NULL));
	if ((head == NULL) || (head->pNext == NULL))
	{
		return;
	}

	/* Split head into 'a' and 'b' sublists */
	FrontBackSplit(head, &a, &b);

	/* Recursively sort the sublists */
	MergeSort(&a);
	MergeSort(&b);

	/* answer = merge the two sorted lists together */
	*headRef = SortedMerge(a, b);
}


void OList::InsertionSort()
{
	// DO cool code here
	// Initialize sorted linked list
	Node *sorted = NULL;

	// Traverse the given linked list and insert every
	// node to sorted
	Node *current = this->pHead;
	while (current != NULL)
	{
		// Store next for next iteration
		Node *next = current->pNext;

		// insert current in sorted linked list
		sortedInsert(&sorted, current);

		// Update current
		current = next;
	}

	// Update head_ref to point to sorted linked list
	this->pHead = sorted;
}


bool OList::Verify(const OList *pNew, const OList * const pOld)
{
	bool Result = true;

	// Don't crash 
	if (pNew == 0 || pOld == 0)
	{
		return false;
	}

	Node *pTmp = pOld->pHead;
	Node *pTmp2 = pNew->pHead;

	// Loop until you find a node
	while (pTmp != 0 && pTmp2 != 0)
	{
		// is this the node?
		if (*pTmp == *pTmp2)
		{
			// continue
		}
		else
		{
			// yes error, then break
			Result = false;
			break;
		}

		// go to next
		pTmp = pTmp->pNext;
		pTmp2 = pTmp2->pNext;
	}

	return Result;
}

Node *OList::privGetListHead()
{
	return pHead;
}

bool OList::FindKey(unsigned int key, Node &foundNode)
{
	bool foundFlag(false);

	Node *p = OList::privGetListHead();
	
	// Loop until you find a node
	while( p != 0 )
	{
		// is this the node?
		if( p->key == key)
		{
			// yes, then break
			foundFlag = true;
			break;
		}

		// go to next
		p = p->pNext;
	}

	// return the node reference that contains the key
	if (foundFlag)
	{
		foundNode = *p;
	}

	// flag
	return foundFlag;
}

OList::OList(Node p)
{
	this->pHead = &p;
}

OList & OList::operator = (const OList &t)
{
	this->pHead = t.pHead;
	return *this;
}

OList::OList()
{
	this->privCreateLinkedList();
}

OList::~OList()
{
	// it was created with array new, so you use delete array
	Node *pTmp = this->pHead;
	Node *pNode = 0;
	while (pTmp != 0)
	{
		pNode = pTmp;
		pTmp = pTmp->getNext();
		delete pNode;
	}

	this->pHead = 0;
}