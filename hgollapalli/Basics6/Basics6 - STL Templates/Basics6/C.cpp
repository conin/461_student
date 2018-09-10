#include "output.h"
#include "Trace.h"
#include <set>
#include <algorithm>

// Add headers as you see fit

struct ZipCode
{
	char s[4];
	int  zip;

	bool operator == (const ZipCode& p)
	{
		return (p.zip == zip && p.s == s);
	}
};


struct find_by_zipcode
{
	find_by_zipcode(const int code) : code(code) 
	{

	}

	find_by_zipcode(ZipCode p) 
	{
		code = p.zip;
		strcpy_s(this->s,4,p.s);
	}

	bool operator()(const ZipCode & car)
	{
		return car.zip == code;
	}

	int operator<(const ZipCode & car)
	{
		return strcmp(car.s,this->s);
	}
private:
	int code;
	char s[4];
};


bool operator < (const ZipCode& p, const ZipCode& q)
{
	return p.s[1] < q.s[1];
}

struct compare
{
	compare()
	{

	}
	compare(const ZipCode code) : code(code)
	{

	}

	compare(const int code,const char *s)
	{
		strcpy_s(this->code.s,4 ,s);
		this->code.zip = code;
	}

	bool operator<(ZipCode lhs)
	{
		return  strcmp(this->code.s, lhs.s)<1;
	}

private:
	ZipCode code;
};


ZipCode data[] =
{
	{ "Bug", 0xABCD },
	{ "Dog", 0x1331 },
	{ "Cat", 0x8844 },
	{ "Pig", 0xBB77 },
	{ "Bee", 0xFFEE }
};


void Problem_3()
{
	// create file
	io::create("problem3.txt");

	// Original data
	int size = 0;
	ZipCode *p = &data[0];
	fprintf(io::getHandle(), "original\n\n");
	for (int i = 0; i < 5; i++)
	{
		fprintf(io::getHandle(), "        zippy[%d]: s:%s  zip:0x%x \n", i, p->s, p->zip);
		p++;
		size++;
	}

	int i = 0;
	// a) insert the data into a stl:set in the order given
	//    use a compare function that sorts with the 2nd letter of the string 
	//    print it to the file (begin to end) order


	std::set<ZipCode> pSet (data,data+size);
	std::set<ZipCode>::iterator pSetIterator;
	p = &data[0];

	pSetIterator = pSet.begin();
	fprintf(io::getHandle(), "\n\n stl: insert into a set After sorting\n");
	for (i = 0; i < 5; i++)
	{
		fprintf(io::getHandle(), "        zippy[%d]: s:%s  zip:0x%x \n", i, pSetIterator->s, pSetIterator->zip);
		pSetIterator++;
	}


	// b)  Find node {"Bee", 0xFFEE} in the set
	//     use the complete node in the search
	//     once found print the iterator's address and it's content


	ZipCode tmp{ "Bee", 0xFFEE };

	pSetIterator = pSet.find(tmp);
	fprintf(io::getHandle(), "\n\n stl: find node using complete node {Bee, 0xFFEE}:");

	if (pSetIterator != pSet.end())
	{
		fprintf(io::getHandle(), "\n\t ZipCode - string - %s\n\t ZipCode - zip - 0x%x ", pSetIterator->s, pSetIterator->zip);
		fprintf(io::getHandle(), "\n\tAddress of ZipCode 0x%p ", &pSetIterator->s);
	}

	// c)  Find the the string name associated with this zip data '0xBB77'
	//     Do not use the complete node, only the zip data
	//     Print the node contents and iterator address
	//
	//     NOTE: you can only use STL: set  - no maps!
	//
	//     hint:  use a custom predicate

	fprintf(io::getHandle(), "\n\n stl: find string name using zip data {0xBB77}:");
	pSetIterator = std::find_if(pSet.begin(), pSet.end(), find_by_zipcode(0xBB77));
	if (pSetIterator->zip == 0xBB77)
	{
		fprintf(io::getHandle(), "\n\t ZipCode->string - %s\n\t ZipCode->zip - 0x%x", pSetIterator->s, pSetIterator->zip);
		fprintf(io::getHandle(), "\n\t Address of ZipCode element is 0x%p", &pSetIterator->s);
	}

	// bye bye
	fprintf(io::getHandle(), "\n");
	io::destroy();
}