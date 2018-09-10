#ifndef MEM_H
#define MEM_H

// forward declare
struct headHdr;

#include "heapHdr.h"

#define HEAP_SIZE ( (50 * 1024) )  //50K


class memSystem
{
public:
	memSystem();
	~memSystem();
	heapHdr *getHeap();
	memVoid dump();

	// implement these functions
	memVoid Free(memVoid * const data);
	memVoid *Malloc(const memU32 size);
	memVoid InitializeSystem();
	void initialiseStats();

	void insertFreeToUsed(freeHdr *);
	void insertUsedToFree(freeHdr *);
	void removeFreeHdr(freeHdr *pObj);
	freeHdr* FindFreeHdr(memU32	p1);
	usedHdr* FindFreeUsed(memU32 p);
	void removeFromUsed(usedHdr *pObj);
	void mergeBlocks(freeHdr*, memU32);
	void SortFreeList();

private:
	heapHdr	*pHeap;
	char	*rawMem;
};

#endif // mem.h