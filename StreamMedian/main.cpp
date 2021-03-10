#include "DoubleHeap.h"
#include "DoubleVec.h"
#include <iostream>

template<typename T>
void test(const char* vpTestName, const T& vD, float vExpect);

int main()
{
	CDoubleHeap DHeap;
	DHeap.insert(5);
	test("Heap Test1", DHeap, 5);

	DHeap.insert(2);
	test("Heap Test2", DHeap, 3.5);

	DHeap.insert(3);
	test("Heap Test3", DHeap, 3);

	DHeap.insert(4);
	test("Heap Test4", DHeap, 3.5);

	DHeap.insert(1);
	test("Heap Test5", DHeap, 3);

	DHeap.insert(6);
	test("Heap Test6", DHeap, 3.5);

	DHeap.insert(7);
	test("Heap Test7", DHeap, 4);

	DHeap.insert(0);
	test("Heap Test8", DHeap, 3.5);

	DHeap.insert(8);
	test("Heap Test9", DHeap, 4);

	CDoubleVec DVec;
	DVec.insert(5);
	test("Vec Test1", DVec, 5);

	DVec.insert(2);
	test("Vec Test1", DVec, 3.5);

	DVec.insert(3);
	test("Vec Test1", DVec, 3);

	DVec.insert(4);
	test("Vec Test1", DVec, 3.5);

	DVec.insert(1);
	test("Vec Test1", DVec, 3);

	DVec.insert(6);
	test("Vec Test1", DVec, 3.5);

	DVec.insert(7);
	test("Vec Test1", DVec, 4);

	DVec.insert(0);
	test("Vec Test1", DVec, 3.5);

	DVec.insert(8);
	test("Vec Test1", DVec, 4);
	
	return 0;
}

template<typename T>
void test(const char * vpTestName, const T & vD, float vExpect)
{
	std::cout << vpTestName << ": ";

	try
	{
		if (vExpect - vD.getMedian() < FLT_EPSILON && vD.getMedian() - vExpect < FLT_EPSILON)
			std::cout << "PASSED." << std::endl;
		else
			std::cout << "FAILED." << std::endl;
	}
	catch (std::runtime_error e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n";
}
