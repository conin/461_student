//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2016
// Optimized C++
//----------------------------------------------------------------------------- 

#ifndef OLIST_H
#define OLIST_H

// forward declaration - always try to do this before including a header (Keenan)
class Node;

// needs to be this value, do not change in final submission
#define NUM_NODES 25000

class OList
	{
	public:
		// Big four
		OList();
		OList(Node );
		~OList();
		OList(const OList &) = delete;
		OList & operator = (const OList &);

		// methods
		bool FindKey(unsigned int key, Node &foundNode);
		void Print(int count);
		static bool Verify(const OList *const pNew, const OList * const pOld);

		// PLease implement this code (add additional methods to help)
		void InsertionSort();
		void MergeComboSort(int CutoffLength);
		void mergeInsert(Node** head);
		void MergeSort(Node** );
		void InsertIntoFile();
		void ReadFromFile();
		void InsertAfterRead(Node p);
		Node* privGetHead();

	private:
		// methods
		void privCreateLinkedList();
		Node *privGetListHead();

		// data
		Node *pHead;
	};


#endif //OList.h
