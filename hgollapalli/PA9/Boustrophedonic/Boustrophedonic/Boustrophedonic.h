#ifndef BOUSTROPHEDIC_H
#define BOUSTROPHEDIC_H

#define UNUSED_VAR(v) ((void *)v)

enum direction
{
	North,
	East,
	West,
	South
};

struct Node
{
	Node *pNorth;
	Node *pSouth;
	int		ind;
	Node *pEast;
	Node *pWest;
	
	Node()
	{
		pNorth = 0;
		pSouth = 0;
		pEast = 0;
		pWest = 0;
	}

	Node(int i)
	{
		ind = i;
		pNorth = 0;
		pSouth = 0;
		pEast = 0;
		pWest = 0;
	}
};


class Boustrophedonic
{
public:
	Boustrophedonic();
	~Boustrophedonic();
	void Remove(Node *&head, int row, int col);
	void insert(Node *Node);
	void createList();
	void print();
	bool Find(Node *Node);
	Node* getHead();

private:
	Node *pHead;
};
#endif
