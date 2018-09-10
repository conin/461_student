#include <vector>
#include <list>
#include <set>

#include "ZipCode.h"
#include "UnitTest.h"
#include "Vect.h"

extern std::vector<int> A_Vector_orig;
extern std::vector<int> A_Vector_insert;
extern std::vector<int> A_Vector_sort;

extern std::list<int> B_List_orig;
extern std::list<int> B_List_insert;
extern std::list<int> B_List_sort;

extern std::vector< Vect > v_Vect_orig;
extern std::vector< Vect > v_Vect_sort;


TEST(Vector, STL_Tests)
{
	CHECK(A_Vector_orig.size() == 8);
	CHECK(A_Vector_orig[0] == 6);
	CHECK(A_Vector_orig[1] == 7);
	CHECK(A_Vector_orig[2] == 3);
	CHECK(A_Vector_orig[3] == 2);
	CHECK(A_Vector_orig[4] == 8);
	CHECK(A_Vector_orig[5] == 1);
	CHECK(A_Vector_orig[6] == 9);
	CHECK(A_Vector_orig[7] == 4);

	CHECK(A_Vector_insert.size() == 9);
	CHECK(A_Vector_insert[0] == 6);
	CHECK(A_Vector_insert[1] == 7);
	CHECK(A_Vector_insert[2] == 3);
	CHECK(A_Vector_insert[3] == 2);
	CHECK(A_Vector_insert[4] == 5);
	CHECK(A_Vector_insert[5] == 8);
	CHECK(A_Vector_insert[6] == 1);
	CHECK(A_Vector_insert[7] == 9);
	CHECK(A_Vector_insert[8] == 4);

	CHECK(A_Vector_sort.size() == 9);
	CHECK(A_Vector_sort[0] == 1);
	CHECK(A_Vector_sort[1] == 2);
	CHECK(A_Vector_sort[2] == 3);
	CHECK(A_Vector_sort[3] == 4);
	CHECK(A_Vector_sort[4] == 5);
	CHECK(A_Vector_sort[5] == 6);
	CHECK(A_Vector_sort[6] == 7);
	CHECK(A_Vector_sort[7] == 8);
	CHECK(A_Vector_sort[8] == 9);
}

TEST(List, STL_Tests)
{
	CHECK(B_List_orig.size() == 8);
	std::list<int>::iterator itB = B_List_orig.begin();
	CHECK(*itB++ == 66);
	CHECK(*itB++ == 77);
	CHECK(*itB++ == 33);
	CHECK(*itB++ == 22);
	CHECK(*itB++ == 88);
	CHECK(*itB++ == 11);
	CHECK(*itB++ == 99);
	CHECK(*itB++ == 44);

	CHECK(B_List_insert.size() == 9);
	itB = B_List_insert.begin();
	CHECK(*itB++ == 66);
	CHECK(*itB++ == 77);
	CHECK(*itB++ == 33);
	CHECK(*itB++ == 22);
	CHECK(*itB++ == 55);
	CHECK(*itB++ == 88);
	CHECK(*itB++ == 11);
	CHECK(*itB++ == 99);
	CHECK(*itB++ == 44);

	CHECK(B_List_sort.size() == 9);
	itB = B_List_sort.begin();
	CHECK(*itB++ == 99);
	CHECK(*itB++ == 88);
	CHECK(*itB++ == 77);
	CHECK(*itB++ == 66);
	CHECK(*itB++ == 55);
	CHECK(*itB++ == 44);
	CHECK(*itB++ == 33);
	CHECK(*itB++ == 22);
	CHECK(*itB++ == 11);
}


TEST(Vector_3D, STL_Tests)
{
	CHECK(v_Vect_orig.size() == 11);
	CHECK(v_Vect_orig[0].a == 3 && v_Vect_orig[0].b == 5 && v_Vect_orig[0].c == 6);
	CHECK(v_Vect_orig[1].a == 6 && v_Vect_orig[1].b == 5 && v_Vect_orig[1].c == 3);
	CHECK(v_Vect_orig[2].a == 3 && v_Vect_orig[2].b == 4 && v_Vect_orig[2].c == 7);
	CHECK(v_Vect_orig[3].a == 7 && v_Vect_orig[3].b == 2 && v_Vect_orig[3].c == 5);
	CHECK(v_Vect_orig[4].a == 1 && v_Vect_orig[4].b == 3 && v_Vect_orig[4].c == 5);
	CHECK(v_Vect_orig[5].a == 3 && v_Vect_orig[5].b == 2 && v_Vect_orig[5].c == 5);
	CHECK(v_Vect_orig[6].a == 2 && v_Vect_orig[6].b == 3 && v_Vect_orig[6].c == 4);
	CHECK(v_Vect_orig[7].a == 3 && v_Vect_orig[7].b == 5 && v_Vect_orig[7].c == 5);
	CHECK(v_Vect_orig[8].a == 7 && v_Vect_orig[8].b == 3 && v_Vect_orig[8].c == 2);
	CHECK(v_Vect_orig[9].a == 4 && v_Vect_orig[9].b == 3 && v_Vect_orig[9].c == 2);
	CHECK(v_Vect_orig[10].a == 1 && v_Vect_orig[10].b == 7 && v_Vect_orig[10].c == 1);


	CHECK(v_Vect_sort.size() == 11);
	CHECK(v_Vect_sort[0].a == 1 && v_Vect_sort[0].b == 3 && v_Vect_sort[0].c == 5);
	CHECK(v_Vect_sort[1].a == 1 && v_Vect_sort[1].b == 7 && v_Vect_sort[1].c == 1);
	CHECK(v_Vect_sort[2].a == 2 && v_Vect_sort[2].b == 3 && v_Vect_sort[2].c == 4);
	CHECK(v_Vect_sort[3].a == 3 && v_Vect_sort[3].b == 2 && v_Vect_sort[3].c == 5);
	CHECK(v_Vect_sort[4].a == 3 && v_Vect_sort[4].b == 4 && v_Vect_sort[4].c == 7);
	CHECK(v_Vect_sort[5].a == 3 && v_Vect_sort[5].b == 5 && v_Vect_sort[5].c == 5);
	CHECK(v_Vect_sort[6].a == 3 && v_Vect_sort[6].b == 5 && v_Vect_sort[6].c == 6);
	CHECK(v_Vect_sort[7].a == 4 && v_Vect_sort[7].b == 3 && v_Vect_sort[7].c == 2);
	CHECK(v_Vect_sort[8].a == 6 && v_Vect_sort[8].b == 5 && v_Vect_sort[8].c == 3);
	CHECK(v_Vect_sort[9].a == 7 && v_Vect_sort[9].b == 2 && v_Vect_sort[9].c == 5);
	CHECK(v_Vect_sort[10].a == 7 && v_Vect_sort[10].b == 3 && v_Vect_sort[10].c == 2);

}