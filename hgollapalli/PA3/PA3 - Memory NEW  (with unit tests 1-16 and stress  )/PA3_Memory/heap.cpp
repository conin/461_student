#include "heapHdr.h"
#include "freeHdr.h"
#include "mem.h"
#include "Trace.h"

heapHdr::heapHdr(void * ptr)
	: usedHead(0),
	freeHead(0),
	heapInitialize(true),
	bytePad1(0),
	bytePad2(0),
	bytePad3(0),
	pad1(0),
	pad2(0),
	pad3(0)
{
	stats.peakNumUsed = 0;			// number of peak used allocations
	stats.peakUsedMemory = 0;		// peak size of used memory

	stats.currNumUsedBlocks = 0;		// number of current used allocations
	stats.currUsedMem = 0;			// current size of the total used memory


	stats.heapTopAddr = (memVoid*)((memU8 *)ptr + sizeof(heapHdr));		// start address available heap
	stats.heapBottomAddr = (memVoid *) ((memU8 *)ptr + HEAP_SIZE);		// last address available heap

	this->freeHead = (freeHdr*)((memU8 *)ptr + sizeof(heapHdr));

	stats.currNumFreeBlocks = 1;		// number of current free blocks


	stats.currFreeMem = (memUInt)(HEAP_SIZE - sizeof(heapHdr) - sizeof(freeHdr));	// current size of the total free memory

	stats.sizeHeap = HEAP_SIZE;				// size of Heap total space, including header
	stats.sizeHeapHeader = sizeof(heapHdr);		// size of heap header

}

