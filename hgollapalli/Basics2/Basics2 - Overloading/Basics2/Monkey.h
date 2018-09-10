#ifndef MONKEY_H
#define MONKEY_H

// Feel free to add extra methods in the class
// You need to explicitly define and implement the Big 4 operators
// Do not add extra data in class
// Do not add code (that goes in *.cpp)

class Monkey
{
public:

	// insert your code here
	Monkey();
	~Monkey();
	Monkey(int);
	//Monkey(Monkey &);
	Monkey operator=(Monkey &);
	Monkey(int , int);
	// accessors
	int getX();
	int getY();
	char *getStatus();
	void printStatus();

	// global variables (incremented each creation or destruction)
	static int numStringsCreated;
	static int numStringsDestroyed;

private:
	int x;
	int y;
	char *pStatus;
};


#endif