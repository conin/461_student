#include<stdio.h>

namespace {
	//Assumer Important Data will have two float numbers
	struct  ImportantData
	{
		float x;
		float y;

		ImportantData(float a, float b)
		{
			x = a;
			y = b;
		}
	};

	typedef struct LinkList
	{
		LinkList *next;
		LinkList *prev;
		ImportantData *data;
	} LinkList_t;

	LinkList_t *headList;


	bool print()
	{
		LinkList *pNew = headList;
		printf("Elements are \n");
		while (pNew != 0)
		{
			printf(" \t %f %f \n", pNew->data->x, pNew->data->y);
			pNew = pNew->next;
		}
		return false;
	}

	bool Find(LinkList &pNode)
	{
		LinkList *pNew = headList;

		while (pNew != 0)
		{
			if (pNew->data == pNode.data)
				return true;

			pNew = pNew->next;
		}
		return false;
	}

	void Remove(LinkList &pNode)
	{
		if (Find(pNode))
		{
			//only one node
			if (pNode.next == 0 && pNode.prev == 0)
			{
				headList = 0;
			}
			//last node
			else if (pNode.next == 0 && pNode.prev != 0)
			{
				pNode.prev->next = 0;
				pNode.prev = 0;
				pNode.data = 0;
			}
			//first node
			else if (pNode.next != 0 && pNode.prev == 0)
			{
				pNode.next->prev = 0;
				headList = pNode.next;
				pNode.next = 0;
				pNode.prev = 0;
				pNode.data = 0;
			}
			//middle node
			else if (pNode.next != 0 && pNode.next != 0)
			{
				pNode.next->prev = pNode.prev;
				pNode.prev->next = pNode.next;
				pNode.next = 0;
				pNode.prev = 0;
				pNode.data = 0;
			}
		}
		else
		{
			printf("Element not found");
		}
		delete &pNode;
	}
}

//int main()
//{
//	ImportantData *imp = new ImportantData(1, 2);
//	ImportantData *imp1 = new ImportantData(2, 3);
//	ImportantData *imp2 = new ImportantData(3, 4);
//
//	LinkList *l = new LinkList();
//	l->data = imp;
//	l->next = 0;
//	l->prev = 0;
//	headList = l;
//
//	LinkList *l1 = new LinkList();
//	l1->data = imp;
//	l1->next = 0;
//	l1->prev = l;
//	l1->prev->next = l1;
//
//	LinkList *l2 = new LinkList();
//	l2->data = imp1;
//	l2->next = 0;
//	l2->prev = l1;
//	l2->prev->next = l2;
//
//	LinkList *l3 = new LinkList();
//	l3->data = imp2;
//	l3->next = 0;
//	l3->prev = l2;
//	l3->prev->next = l3;
//
//	LinkList *l4 = new LinkList();
//
//	Remove(*l);
//	Remove(*l1);
//	Remove(*l2);
//	Remove(*l3);
//	Remove(*l4);
//	print();
//	return 0;
//}