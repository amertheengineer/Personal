/*

	Amer Abdelaziz
	U25449742

		This modified file contains multiple memory management functions
		that merge, free, malloc, and splits memory blocks
*/

#include <cassert>
#include <iostream>
#include "MemoryManager.h"


MemoryManager::MemoryManager(unsigned int memtotal)
{
	memsize = memtotal;
	baseptr = new unsigned char[memsize];
	blockdata originalBlock(memsize, baseptr, true);
	blocklist.insertAfter(blocklist.header, originalBlock);
	assert(!blocklist.empty());
}

void MemoryManager::showBlockList()
{
	// cout << "\n-------------BlockList start------------------\n\n";
	blocklist.print("->");
	cout << endl;
	//  cout << "\n-------------BlockList end------------------\n\n";
}
/* Splitting the block and just inserting chuncksize into p */
void MemoryManager::splitBlock(dlNode<blockdata> *p, unsigned int chunksize)
{
	// assert(chunksize < p->info.blocksize);
	/* Node to traverse the list */

	dlNode <blockdata> *jumper = new dlNode<blockdata>(p->info, p->prev, p);

	jumper->info.blocksize = chunksize;
	/* Incrementing and Decrementing the blockpointer and size repectively */
	p->info.blockptr += chunksize;
	p->info.blocksize -= chunksize;
	/* Repointing p*/
	p->prev->next = jumper;
	p->prev = jumper;


}

unsigned char * MemoryManager::malloc(unsigned int request)
{
	/* Traversal node at header's next */
	dlNode <blockdata> * p;
	p = blocklist.header->next;

	/* Condition */
	while (p != blocklist.trailer)
	{
		/* If the pointer is free and contains the blocksize, then allocate it */

		if (p->info.free == true && p->info.blocksize == request)
		{
			p->info.free = false;
			return p->info.blockptr;
		}
		/* If the block is bigger, split into two blocks and allocate */
		else if (p->info.blocksize > request && p->info.free == true)
		{
			splitBlock(p, request);
			p->prev->info.free = false;
			return p->prev->info.blockptr;
		}

		/* Keep looping through blocklist */
		p = p->next;


	}
	return nullptr;

}
/* Merging a memory block with the one next to it */
void MemoryManager::mergeForward(dlNode<blockdata> *p)
{
	/* Asserting the the list is  not empty  */
	if (p->next != blocklist.trailer)
	{
		/* Asserting the two being merged are free and increasing p's size */
		if (p->info.free == true && p->next->info.free == true) 
		{
			p->info.blocksize += p->next->info.blocksize;
			blocklist.deleteNext(p);
		}
	}


}
/* MeSimilar logic here just with p-> prev */
void MemoryManager::mergeBackward(dlNode<blockdata> *p)
{
	if (p->prev != blocklist.header)
	{
		if (p->info.free == true && p->prev->info.free == true)
		{
			p->info.blocksize += p->prev->info.blocksize;
			blocklist.deletePrevious(p);

		}

	}


}
/* Freeing a block */
void MemoryManager::free(unsigned char *ptr2block)
{
	dlNode<blockdata>* hopper;
	hopper = blocklist.header->next;

	while (hopper != blocklist.trailer)
	{
		/* Base condition */
		if (hopper->info.blockptr == ptr2block)
		{
			hopper->info.free = true;
		}
		/* Keep merging hopper and loop thorugh in to merge any free blocks */
		mergeBackward(hopper);
		mergeForward(hopper);
		hopper = hopper->next;



	}


}
