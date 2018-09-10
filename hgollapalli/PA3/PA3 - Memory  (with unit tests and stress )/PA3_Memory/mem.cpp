#include <new>
#include <assert.h>
#include "mem.h"
#include "Trace.h"
#include "heapHdr.h"
#include "freeHdr.h"
#include "usedHdr.h"
#include "output.h"

#define ALIGNMENT_PAD (16)

#define UNUSED_VAR(v)  ((void *)v)

memSystem::~memSystem()
{
	delete [] this->rawMem;
}


heapHdr *memSystem::getHeap()
{
	return this->pHeap;
}

memSystem::memSystem()
{
	// now initialize it.
	this->pHeap = 0;
	this->rawMem = 0;

	// create the memorry block for the heap
	char *p_raw = new char[HEAP_SIZE+ALIGNMENT_PAD];

	// update the pointer
	this->rawMem = p_raw;

	// Correct pointer to make sure it's 16 byte aligned
	char *p_corrected = (char *) ( ((memU32)p_raw + (16-1) ) & ~(16-1) );   

	// instantiate the heap header on the raw memory
	heapHdr *p = new(p_corrected) heapHdr(p_corrected);

	// update it, now code warrior
	this->pHeap = p;
}

void memSystem::initialiseStats()
{
	this->pHeap->stats.peakNumUsed = 0;
	this->pHeap->stats.peakUsedMemory = 0;

	this->pHeap->stats.currNumUsedBlocks = 0;
	this->pHeap->stats.currUsedMem = 0;

	this->pHeap->stats.currNumFreeBlocks = 1;
	this->pHeap->stats.currFreeMem = 0;

	this->pHeap->stats.sizeHeap = HEAP_SIZE;
	this->pHeap->stats.sizeHeapHeader = 0;

	this->pHeap->stats.heapTopAddr = 0;
	this->pHeap->stats.heapBottomAddr = 0;
}

memVoid memSystem::InitializeSystem( )
{
	//initialiseStats();
	if(this->pHeap->usedHead)
	{
		this->pHeap->usedHead->setUsedHdr(HEAP_SIZE);
	}
	else
	{
		this->pHeap->freeHead->setfreeHdr(HEAP_SIZE );
	}
}


memVoid memSystem::insertUsedToFree(freeHdr *p)
{
	p->blockType = 0xCC;
	freeHdr *last=0,*tmp = this->pHeap->freeHead ;
	int set = 0;

	//if it doesnt have node 
	if (pHeap->freeHead == 0)
	{
		p->freeNext = 0;
		p->freePrev = 0;
		pHeap->freeHead = p;
	}
	else
	{
		/*p->freeNext = pHeap->freeHead ;
		p->freeNext->freePrev = p;
		pHeap->freeHead = p;*/
		while (tmp != 0)
		{
			if (tmp>p)
			{
				set = 1;
				break;
			}
			else
			{
				last = tmp;
				tmp = tmp->freeNext;
			}
		}

		if (set == 1)
		{
			p->freePrev = tmp->freePrev;
			p->freeNext = tmp;
			if (tmp->freePrev != 0)
				tmp->freePrev->freeNext = p;
			else
				this->pHeap->freeHead = p;
			tmp->freePrev = p;
		}
		else
		{
			last->freeNext = p;
			p->freePrev = last;
		}
	}
}

memVoid memSystem::mergeBlocks(freeHdr * ptmp, memU32 s1)
{
	//if there are two free blocks then we need to test whether they are next to 
	//eachother if they are same then 
	UNUSED_VAR(s1);
	freeHdr *down = (freeHdr*)((memU32)ptmp + sizeof(freeHdr) + ptmp->blockSize);	
	memU32 *s = (memU32*)((memU32)ptmp - sizeof(memU32));
	freeHdr *up = (freeHdr*)*s;

	//if (ptmp + sizeof(freeHdr) + ptmp->blockSize <= this->pHeap->stats.heapBottomAddr)
		down->aboveBlockFree = true;

	if (down != 0 && down->blockType == 0xCC && down<=this->pHeap->stats.heapBottomAddr)
	{
			//compute total size 
			ptmp->blockSize = ptmp->blockSize + sizeof(freeHdr)+ down->blockSize ;
			this->pHeap->stats.currFreeMem = this->pHeap->stats.currFreeMem +16;
			removeFreeHdr(down);
			down = 0;
			this->pHeap->stats.currNumFreeBlocks--;
			memU32 *secret1 = (memU32*)(((memU32)ptmp + sizeof(freeHdr) + ptmp->blockSize) - sizeof(memU32));
			*secret1 = (memU32)ptmp;
	}	


	if (up != 0 && ptmp->aboveBlockFree)
	{
		up->blockSize = up->blockSize + sizeof(freeHdr) + ptmp->blockSize;
		this->pHeap->stats.currFreeMem = this->pHeap->stats.currFreeMem + 16;
		up->aboveBlockFree = false;
		removeFreeHdr(ptmp);
		ptmp = 0;
		this->pHeap->stats.currNumFreeBlocks--;
		memU32 *secret2 = (memU32*)(((memU32)up + sizeof(freeHdr) + up->blockSize) - sizeof(memU32));
		*secret2 = (memU32)up;
	}
}

memVoid memSystem::Free( memVoid * const data )
{
	if (this->pHeap->usedHead)
	{
		usedHdr *pUsedAddr = (usedHdr *)((memU32)data - sizeof(usedHdr));
		usedHdr tmp = *pUsedAddr;

		// remove the used from the list
		removeFromUsed(&tmp);

		freeHdr *pNewFree = new(pUsedAddr) freeHdr();
		pNewFree->blockSize = tmp.blockSize;
		pNewFree->aboveBlockFree = tmp.aboveBlockFree;

		//freeHdr *tmp = (freeHdr*)data;
		//usedHdr *p = (usedHdr*)tmp;
		insertUsedToFree(pNewFree);
		
		/// secret pointer arrangement
		memU32 *secret1 = (memU32*)(((memU32)pNewFree + sizeof(freeHdr) + pNewFree->blockSize) - sizeof(memU32));
		// secret pointer should point to the curren block
		*secret1 = (memU32)pNewFree;

		//this->pHeap->usedHead = 0;
		this->pHeap->stats.currNumFreeBlocks = this->pHeap->stats.currNumFreeBlocks + 1;
		
		this->pHeap->stats.currFreeMem = this->pHeap->stats.currFreeMem + pNewFree->blockSize;

		///need to subtract when removed
		this->pHeap->stats.currUsedMem -= pNewFree->blockSize;
		if (pNewFree->blockSize > this->pHeap->stats.peakUsedMemory)
			this->pHeap->stats.peakUsedMemory += (pNewFree->blockSize-this->pHeap->stats.peakUsedMemory);

		this->pHeap->stats.currNumUsedBlocks--;
		if (this->pHeap->stats.currNumUsedBlocks > this->pHeap->stats.peakNumUsed)
			this->pHeap->stats.peakNumUsed += (this->pHeap->stats.currNumUsedBlocks - this->pHeap->stats.peakNumUsed);

		mergeBlocks(pNewFree, (memU32)secret1);
	}
	else
	{
	
	}
	UNUSED_VAR(data);
}

usedHdr* memSystem::FindFreeUsed(memU32 bSize)
{
	usedHdr *pfree = pHeap->usedHead;

	while (pfree != 0)
	{
		if (pfree->blockSize == bSize)
			break;
		pfree = pfree->usedNext;
	}
	return pfree;
}

void memSystem:: SortFreeList()
{
	//freeHdr *p1,*p = this->pHeap->freeHead;
}

void memSystem::removeFromUsed(usedHdr *pObj)
{
	usedHdr *p1 = pObj;// FindFreeUsed(pObj->blockSize);

	if (p1->usedNext == 0 && p1->usedPrev == 0)
	{
		pHeap->usedHead = 0;
	}
	else if (p1->usedNext != 0 && p1->usedPrev == 0)
	{
		pHeap->usedHead = p1->usedNext;
		pHeap->usedHead->usedPrev = 0;
		p1->usedNext = 0;
		p1->usedPrev = 0;
	}
	else if (p1->usedNext == 0 && p1->usedPrev != 0)
	{
		p1->usedPrev->usedNext = 0;
		p1->usedPrev = 0;
	}
	else if (p1->usedNext != 0 && p1->usedPrev != 0)
	{
		p1->usedNext->usedPrev = p1->usedPrev;
		p1->usedPrev->usedNext = p1->usedNext;
	}
}

void memSystem::removeFreeHdr(freeHdr *pObj)
{
	if (pObj->freeNext == 0 && pObj->freePrev == 0)
	{
		pHeap->freeHead = 0;
	}
	else if (pObj->freeNext != 0 && pObj->freePrev == 0)
	{
		pHeap->freeHead = pObj->freeNext;
		pHeap->freeHead->freePrev = 0;
		pObj->freeNext = 0;
		pObj->freePrev = 0;
	}
	else if (pObj->freeNext == 0 && pObj->freePrev != 0)
	{
		pObj->freePrev->freeNext = 0;
		pObj->freePrev = 0;
	}
	else if (pObj->freeNext != 0 && pObj->freePrev != 0)
	{
		pObj->freeNext->freePrev = pObj->freePrev;
		pObj->freePrev->freeNext = pObj->freeNext;
	}
}

freeHdr* memSystem::FindFreeHdr(memU32 bSize)
{
	freeHdr *pfree = pHeap->freeHead;

	while (pfree != 0)
	{
		if (pfree->blockSize >= bSize)
			break;
		pfree = pfree->freeNext;
	}
	return pfree;
}

memVoid * memSystem::Malloc( const memU32 size )
{

	memU32 AlignedSize= (((memU32)size + (16 - 1)) & ~(16 - 1));
	freeHdr *pTmp = this->FindFreeHdr(size);
	
	memU32 size1 = pTmp->blockSize;

	if(pTmp->blockSize==size)
	{
		removeFreeHdr(pTmp);
		insertFreeToUsed(pTmp);
		
		

		this->pHeap->stats.currNumFreeBlocks = this->pHeap->stats.currNumFreeBlocks-1;
		this->pHeap->stats.currFreeMem = this->pHeap->stats.currFreeMem - AlignedSize;

		///need to subtract when removed
		this->pHeap->stats.currUsedMem += AlignedSize;
		if(this->pHeap->stats.currUsedMem  >  this->pHeap->stats.peakUsedMemory)
			this->pHeap->stats.peakUsedMemory += (this->pHeap->stats.currUsedMem -this->pHeap->stats.peakUsedMemory);

		this->pHeap->stats.currNumUsedBlocks++;
		if (this->pHeap->stats.currNumUsedBlocks > this->pHeap->stats.peakNumUsed)
			this->pHeap->stats.peakNumUsed += (this->pHeap->stats.currNumUsedBlocks-this->pHeap->stats.peakNumUsed);
		
	}
	else
	{
		freeHdr *pCopy = pTmp;
		removeFreeHdr(pTmp);
		
		// instantiate the heap header on the raw memory
		usedHdr *p = new(pTmp) usedHdr();
		p->blockSize = AlignedSize;
		insertFreeToUsed((freeHdr*)p);

		//pTmp
		freeHdr *fr = (freeHdr *)((memU32) pCopy + AlignedSize + sizeof(usedHdr));
		fr->blockSize = size1 - sizeof(freeHdr)- AlignedSize;
		fr->aboveBlockFree = false;
		fr->freeNext = 0;
		fr->freePrev = 0;
		insertUsedToFree(fr);

		this->pHeap->stats.currFreeMem = this->pHeap->stats.currFreeMem - AlignedSize -sizeof(freeHdr);

		///need to subtract when removed
		this->pHeap->stats.currUsedMem += AlignedSize;
		if (this->pHeap->stats.currUsedMem > this->pHeap->stats.peakUsedMemory)
			this->pHeap->stats.peakUsedMemory += this->pHeap->stats.currUsedMem- this->pHeap->stats.peakUsedMemory;

		this->pHeap->stats.currNumUsedBlocks++;
		if (this->pHeap->stats.currNumUsedBlocks > this->pHeap->stats.peakNumUsed)
			this->pHeap->stats.peakNumUsed += (this->pHeap->stats.currNumUsedBlocks - this->pHeap->stats.peakNumUsed);
	}

	usedHdr *fr = (usedHdr *)((memU32)pTmp + AlignedSize + sizeof(usedHdr));
	if ((memU32*)fr < (memU32*)pHeap->stats.heapBottomAddr)
		fr->aboveBlockFree = false;

	return pTmp + 1;
}

void memSystem::insertFreeToUsed(freeHdr *pObj)
{
	usedHdr *n = (usedHdr *)pObj;
	n->blockType = 0xAA;

	if(pHeap->usedHead==0)
	{
		n->usedNext = 0;
		n->usedPrev = 0;
		pHeap->usedHead = n;
	}
	else
	{
		n->usedNext = pHeap->usedHead;
		n->usedPrev = 0;
		n->usedNext->usedPrev = n;
		pHeap->usedHead = n;
	}
}

memVoid memSystem::dump()
{

	fprintf(io::getHandle(),"\n------- DUMP -------------\n\n");

	fprintf(io::getHandle(),"heapStart: 0x%p     \nheapEnd:   0x%p \n\n",this->pHeap, this->pHeap->stats.heapBottomAddr);
	fprintf(io::getHandle(),"usedHead:  0x%p     \nfreeHead:  0x%p \n\n", this->pHeap->usedHead, this->pHeap->freeHead );

	fprintf(io::getHandle(),"Heap Hdr   s: %p  e: %p                            size: 0x%x \n",(void *)((memU32)this->pHeap->stats.heapTopAddr-sizeof(heapHdr)), this->pHeap->stats.heapTopAddr, this->pHeap->stats.sizeHeapHeader);

	memU32 p = (memU32)pHeap->stats.heapTopAddr;

	char *type;
	char *typeHdr;

	while( p < (memU32)pHeap->stats.heapBottomAddr )
	{
		usedHdr *used = (usedHdr *)p;
		if( used->blockType == 0xAA )
		{
			typeHdr = "USED HDR ";
			type    = "USED     ";
		}
		else
		{
			typeHdr = "FREE HDR ";
			type    = "FREE     ";
		}

		memU32 hdrStart = (memU32)used;
		memU32 hdrEnd   = (memU32)used + sizeof(usedHdr);
		fprintf(io::getHandle(),"%s  s: %p  e: %p  p: %p  n: %p  size: 0x%x    AF: %d \n",typeHdr, (void *)hdrStart, (void *)hdrEnd, used->usedPrev, used->usedNext, sizeof(usedHdr), used->aboveBlockFree );
		memU32 blkStart = hdrEnd;
		memU32 blkEnd   = blkStart + used->blockSize; 
		fprintf(io::getHandle(),"%s  s: %p  e: %p                            size: 0x%x \n",type, (void *)blkStart, (void *)blkEnd, used->blockSize );

		p = blkEnd;
	
	}
}