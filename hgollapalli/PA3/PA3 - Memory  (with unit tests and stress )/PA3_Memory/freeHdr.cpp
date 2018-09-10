#include "freeHdr.h"

void freeHdr::setfreeHdr(memUInt bSize)
{
	this->freeNext = 0;
	this->freePrev = 0;
	this->blockSize = (memU32)(bSize - sizeof(heapHdr) - sizeof(freeHdr));
	this->blockType = 0xCC;
	this->aboveBlockFree = false;
	this->pad1 = 0;
	this->pad2 = 0;
}

