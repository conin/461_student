//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2016
// Optimized C++
//----------------------------------------------------------------------------- 

#ifndef NODE_H
#define NODE_H

struct  LoadInPlace
{
	int blockSize;
	int ptr;

	LoadInPlace()
	{
		blockSize = 0;
		ptr = 0;
	}

	LoadInPlace(int x,int y) 
	{
		blockSize = x;
		ptr = y;
	}
};

class Node
{
public:
	// big four
	Node();
	Node(const Node &) = default;
	Node(char *);
	Node & operator = (const Node &) = default;
	~Node() = default;

	bool operator ==(const Node &);

	void setNext(Node *p);
	void setPrev(Node *p);
	Node * getNext();
	Node * getPrev();

private:
	void getRandUInt(unsigned int & var);

public:
	Node	*pNext;
	Node	*pPrev;
	unsigned int x;
	unsigned int y;
	unsigned int z;
	unsigned int key;
};

#endif //NODE_H