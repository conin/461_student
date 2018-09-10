#ifndef FREEHDR_H
#define FREEHDR_H

#include "memTypes.h"

struct freeHdr
{
	freeHdr *freeNext;		// next free block
	freeHdr *freePrev;		// prev free blockk
	memU32  blockSize;		// size of block
	memU8	blockType;		// block type is used -> 0xAA  if block type is free -> 0xCC
	memBool	aboveBlockFree;	// if(block is free) -> true or if(block is used) -> false
	memU8	pad1;			// future use
	memU8	pad2;			// future use

	void setfreeHdr(memUInt bSize)
	{
		this->freeNext = 0;
		this->freePrev = 0;
		this->blockSize = (memU32)(bSize - sizeof(heapHdr) - sizeof(freeHdr));
		this->blockType = 0xCC;
		this->aboveBlockFree = false;
		this->pad1 = 0;
		this->pad2 = 0;
	}
	
	freeHdr()
	{
		this->freeNext = 0;
		this->freePrev = 0;
		this->blockType = 0XCC;
		this->aboveBlockFree = false;
	}
};

#endif //FREEHDR_H