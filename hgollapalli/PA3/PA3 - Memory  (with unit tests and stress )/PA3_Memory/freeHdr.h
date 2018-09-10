#include "memTypes.h"
#include "heapHdr.h"


struct freeHdr
{
	freeHdr *freeNext;		// next free block
	freeHdr *freePrev;		// prev free block
	memU32  blockSize;		// size of block
	memU8	blockType;		// block type is used -> 0xAA  if block type is free -> 0xCC
	memBool	aboveBlockFree;	// if(block is free) -> true or if(block is used) -> false
	memU8	pad1;			// future use
	memU8	pad2;			// future use

	void setfreeHdr(memUInt bSize);

	freeHdr()
	{
		this->freeNext = 0;
		this->freePrev = 0;
		this->blockType = 0XCC;
		this->aboveBlockFree = false;
	}
};