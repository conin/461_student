
#include "UnitTest.h"
#include "answerRegistry.h"
#include"Trace.h"

TEST( simple_1, PointerWalk_Group )
{
	CHECK( Answer::getAnswer(0, 0) == 0xEB );	
	CHECK( Answer::getAnswer(0, 1) == 0x4f );
	CHECK( Answer::getAnswer(0, 2) == 0xb5 );
	CHECK( Answer::getAnswer(0, 3) == 0xcd );
	CHECK( Answer::getAnswer(0, 4) == 0x44 );
	CHECK( Answer::getAnswer(0, 5) == 0xcd );
	CHECK( Answer::getAnswer(0, 6) == 0x75 );
	CHECK( Answer::getAnswer(0, 7) == 0x11 );
	CHECK( Answer::getAnswer(0, 8) == 0x39 );
	CHECK( Answer::getAnswer(0, 9) == 0x56 );
	CHECK( Answer::getAnswer(0, 10) == 0xAA );
	CHECK( Answer::getAnswer(0, 11) == 0xAA );
}

TEST( simple_2, PointerWalk_Group )
{
	CHECK( Answer::getAnswer(0, 12) == 0x4f22cdeb );	
	CHECK( Answer::getAnswer(0, 13) == 0x11225C39 );
	CHECK( Answer::getAnswer(0, 14) == 0x35f3b573 );
	CHECK( Answer::getAnswer(0, 15) == 0x13aaa856 );
	CHECK( Answer::getAnswer(0, 16) == 0x11225C39 );
}

TEST( simple_3, PointerWalk_Group )
{
	CHECK( Answer::getAnswer(0, 17) == 0x4366 );	
	CHECK( Answer::getAnswer(0, 18) == 0x3375 );
	CHECK( Answer::getAnswer(0, 19) == 0x2668 );
	CHECK( Answer::getAnswer(0, 20) == 0xA856 );
	CHECK( Answer::getAnswer(0, 21) == 0x13 );
	CHECK( Answer::getAnswer(0, 22) == 0x39 );	
	CHECK( Answer::getAnswer(0, 23) == 0x64 );
}

TEST( simple_4, Casting_Group )
{
 CHECK( Answer::getAnswer(1, 0) == 0xCA);
 CHECK( Answer::getAnswer(1, 1) == 0xbb001111);
 CHECK( Answer::getAnswer(1, 2) == 0xbb002222);
 CHECK( Answer::getAnswer(1, 3) == 0xbb003333);
 CHECK( Answer::getAnswer(1, 4) == 0xddaa);
 CHECK( Answer::getAnswer(1, 5) == 0xddbb);
 CHECK( Answer::getAnswer(1, 6) == 0xddcc);
 CHECK( Answer::getAnswer(1, 7) == 0xC9);
 CHECK( Answer::getAnswer(1, 8) == 0xCA);
 CHECK( Answer::getAnswer(1, 9) == 0xCB);
}

TEST( simple_5, Casting_Group )
{
  CHECK( Answer::getAnswer(1, 11) == 0x4);
  CHECK( Answer::getAnswer(1, 12) == 0x1);
  CHECK( Answer::getAnswer(1, 13) == 0x14);
  CHECK( Answer::getAnswer(1, 14) == 0x4);
  CHECK( Answer::getAnswer(1, 15) == 0x1);
  CHECK( Answer::getAnswer(1, 16) == 0x8);
  CHECK( Answer::getAnswer(1, 17) == 0x1);
  CHECK( Answer::getAnswer(1, 18) == 0x0);
  CHECK( Answer::getAnswer(1, 19) == 0x3);
}
