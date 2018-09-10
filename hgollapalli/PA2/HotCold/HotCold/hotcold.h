//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2016
// Optimized C++
//----------------------------------------------------------------------------- 

#ifndef HOTCOLD_H
#define HOTCOLD_H
#include"hotcold.h"

// forward declaration - always try to do this before including a header, in a header
class Bloated;
class HotNode;
class ColdNode;

class HotNode
{
public:
	HotNode			*next;
	HotNode			*prev;
	int				key;
	ColdNode		*pColdObj;

	HotNode();
	HotNode(HotNode &);
	HotNode& operator=(HotNode &);
	~HotNode();
};

class ColdNode
{
public:
	ColdNode();
	ColdNode(ColdNode &);
	ColdNode& operator=(ColdNode &);
	~ColdNode();

	friend class ColdNode;
public:
	float			x;
	float			y;
	float			z;
	Vect_t			A;
	Vect_t			B;
	Vect_t			C;
	Matrix_t		MA;
	Matrix_t		MB;
	Matrix_t		MC;
	Matrix_t		MD;
	char			name[NAME_SIZE];
	HotNode			*pHotObj;

};

class HotCold
{
public:
	void privCreateLinkedList();
	HotCold( Bloated *pBloated );
	bool findKey(int key, HotNode &foundNode);
	bool verify(Bloated *pBloated);
	void print();

private:
	HotCold();
	HotNode *hotHead;
};



#endif //bloated.h
