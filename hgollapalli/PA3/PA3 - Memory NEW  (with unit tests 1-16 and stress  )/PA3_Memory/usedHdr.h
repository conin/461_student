#ifndef USEDHDR_H
#define USEDHDR_H

#include "memTypes.h"



struct usedHdr
{
	usedHdr *usedNext;		// next used block
	usedHdr *usedPrev;		// prev used block
	memU32  blockSize;		// size of block
	memU8	blockType;		// block type is used -> 0xAA  if block type is free -> 0xCC
	memBool	aboveBlockFree;	// if(block is free) -> true or if(block is used) -> false
	memU8	pad0;           // future use
	memU8	pad1;			// future use

	void setUsedHdr(memUInt bSize)
	{
		this->usedNext = 0;
		this->usedPrev = 0;
		this->blockSize = bSize;
		this->blockType = 0xCC;
		this->aboveBlockFree = false;
		this->pad0 = 0;
		this->pad1 = 0;
	}

	usedHdr()
	{
		this->usedNext = 0;
		this->usedPrev = 0;
		this->blockType = 0XAA;
		this->aboveBlockFree = false;
	}
};

#endif //USEDHDR_H