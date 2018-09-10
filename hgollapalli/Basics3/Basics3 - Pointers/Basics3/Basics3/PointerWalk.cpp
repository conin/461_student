#include <assert.h>
#include "answerRegistry.h"



#define QuestionAnswer(x,y)  Answer::registerAnswer(0,x,y)

unsigned char data[] =
{ 
  0xEB, 0xCD, 0x22, 0x4F,
  0x73, 0xB5, 0xF3, 0x35,
  0x23, 0x24, 0x01, 0xFE,
  0xCD, 0xE3, 0x44, 0x85,
  0x66, 0x43, 0x75, 0x33,
  0x39, 0x5C, 0x22, 0x11,
  0x56, 0xA8, 0xAA, 0x13,
  0x64, 0x82, 0x68, 0x26 
};


void Students_PointerWalk()
{
	unsigned char  *p;  // char are 8-bits long
	unsigned int   *r;  // ints are 32-bits long
	unsigned short *s;  // shorts are 16-bits long

	unsigned int val;   // answer value

	// Sample Question 1
	// follow the pattern for the whole walking pointer test

	p = &data[0];
	val = p[0];
	QuestionAnswer(0, val);

	//4f
	p += 3;
	val = *p;
	QuestionAnswer(1, val);

	//b5
	p += 2;
	val = *p;
	QuestionAnswer(2, val);

	//cd
	p += 7;
	val = *p;
	QuestionAnswer(3, val);

	//44
	p += 2;
	val = *p;
	QuestionAnswer(4, val);

	//cd
	p -= 2;
	val = *p;
	QuestionAnswer(5, val);

	//75
	p += 6;
	val = *p;
	QuestionAnswer(6, val);

	//11
	p += 5;
	val = *p;
	QuestionAnswer(7, val);

	//39
	p -= 3;
	val = *p;
	QuestionAnswer(8, val);

	//11
	p += 4;
	val = *p;
	QuestionAnswer(9, val);

	//aa
	p += 2;
	val = *p;
	QuestionAnswer(10, val);
	QuestionAnswer(11, val);

	// Now repeat for the pointer test
	// 0-23 question in total for this part

	// Make sure you look at the memory window 
	// and understand the test thoroughly

	// Replace as you type in the pointer test
	//0xEB
	r = (unsigned int *)&data[0];
	val = *r;
	QuestionAnswer(12, val);

	//0x39
	r = r + 5;
	val = *r;
	QuestionAnswer(13, val);

	//0x73
	r = r - 4;
	val = *r;
	QuestionAnswer(14, val);

	//0x56
	r = r + 5;
	val = *r;
	QuestionAnswer(15, val);

	//39
	r = r - 1;
	val = *r;
	QuestionAnswer(16, val);

	
	//0x4366
	s = (unsigned short *)&data[0];
	s += 8;
	val = *s;
	QuestionAnswer(17, val);

	//0x3375
	s += 1;
	val = *s;
	QuestionAnswer(18, val);

	//0x2668
	s += 6;
	val = *s;
	QuestionAnswer(19, val);

	//0xA856
	s -= 3;
	val = *s;
	QuestionAnswer(20, val);

	//0x13
	p = &data[27];
	val = *p;
	QuestionAnswer(21, val);

	//0x39
	p -= 7;
	val = *p;
	QuestionAnswer(22, val);	

	//0x64
	p += 8;
	val = *p;
	QuestionAnswer(23, val);

}


