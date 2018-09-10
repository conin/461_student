#ifndef NIBBLE_H
#define NIBBLE_H

// Feel free to add extra methods in the class
// You need to explicitly define and implement the Big 4 operators
// Do not add extra data in class
// Do not add code (that goes in *.cpp)

class Nibble
{
public:
	// insert your code here
	Nibble();
	Nibble(unsigned int );
	Nibble operator=(const Nibble &);
	Nibble(const Nibble &);
	~Nibble();
	

	Nibble operator+(const Nibble &);
	Nibble operator+=(const Nibble &);
	Nibble operator+(int );
	friend Nibble operator+(int, const Nibble &);
	friend Nibble operator~(const Nibble &);
	friend Nibble operator+(const Nibble &);
	friend Nibble operator++(const Nibble &);
	friend Nibble operator<<(const Nibble &,int );

	unsigned char getData();

private:
	unsigned char data;

};

#endif