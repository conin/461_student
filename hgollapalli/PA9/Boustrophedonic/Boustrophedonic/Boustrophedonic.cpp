#include <assert.h>
#include <stdio.h>
#include "Trace.h"
#include "Boustrophedonic.h"


void Boustrophedonic::Remove(Node *&head, int row, int col)
{
	UNUSED_VAR(head);
	UNUSED_VAR(&row);
	UNUSED_VAR(&col);
}

Node* Boustrophedonic::getHead()
{
	return pHead;
}

Boustrophedonic::Boustrophedonic()
{
	this->pHead = new Node();
	this->pHead = 0;
}

Boustrophedonic::~Boustrophedonic()
{

}

bool Boustrophedonic::Find(Node *obj)
{
	Node *pTmp = pHead;
	bool status = false;

	while (pTmp!=0)
	{
		if (pTmp == obj)
		{
			status = true;
			break;
		}
		pTmp = pTmp->pEast;
	}

	return status;
}


void Boustrophedonic::createList()
{
	Node *p1 = new Node(1);
	Node *p2 = new Node(2);
	Node *p3 = new Node(3);
	Node *p4 = new Node(4);
	Node *p5 = new Node(5);
	Node *p6 = new Node(6);
	Node *p7 = new Node(7);
	Node *p8 = new Node(8);
	Node *p9 = new Node(9);
	Node *p10 = new Node(10);
	Node *p11 = new Node(11);
	Node *p0 = new Node(0);

	pHead = p0;
	//0 -> 1
	p0->pEast = p1;
	p1->pWest = p0;
	//1 -> 2
	p1->pEast = p2;
	p2->pWest = p1;
	//2 -> 3
	p2->pEast = p3;
	p3->pWest = p2;
	//3 -> 4
	p3->pSouth = p4;
	p4->pNorth = p3;
	//4 -> 5
	p4->pWest = p5;
	p5->pEast = p4;
	//5 -> 6
	p5->pWest = p6;
	p6->pEast = p5;
	//6 -> 7
	p6->pWest = p7;
	p7->pEast = p6;
	//7 -> 8
	p7->pSouth = p8;
	p8->pNorth = p7;
	//8 -> 9
	p8->pEast = p9;
	p9->pWest = p8;
	//9 -> 10
	p9->pEast = p10;
	p10->pWest = p9;
	//10 -> 11
	p10->pEast = p11;
	p11->pWest = p10;

	//creating connections
	p5->pNorth = p2;
	p1->pSouth = p6;
	p7->pNorth = p0;

	p9->pNorth = p6;
	p5->pSouth = p10;
	p11->pNorth = p4;
}

void Boustrophedonic::print()
{
	Node *pTmp = pHead;

	while (pTmp != 0)
	{
		Trace::out("\n-----------------------");
		Trace::out("\n\tNODE - %d",pTmp);
		Trace::out("\n\tValue %d", pTmp->ind);
		Trace::out("\n\tEast  Node %d", pTmp->pEast);
		Trace::out("\n\tWest  Node %d", pTmp->pWest);
		Trace::out("\n\tNorth Node %d", pTmp->pNorth);
		Trace::out("\n\tSouth Node %d", pTmp->pSouth);

		pTmp = pTmp->pEast;
		Trace::out("\n-----------------------");
	}
}

void Boustrophedonic::insert(Node *Node)
{
	if (pHead == 0)
	{
		pHead = Node;
		Node->pEast = 0;
		Node->pWest = 0;
		Node->pNorth = 0;
		Node->pSouth = 0;
	}
	else
	{
		Node->pEast = pHead;
		Node->pEast->pWest = Node;
		pHead = Node;
		Node->pWest = 0;
		Node->pNorth = 0;
		Node->pSouth = 0;
	}
}
