#include <iostream>
#include "QMax.h"

void test(const char* vpTestName, CQMax& vQ, int vExpect);

int main()
{
	CQMax Queue;

	//2
	Queue.push_back(2);
	test("Test1", Queue, 2);

	//2,3
	Queue.push_back(3);
	test("Test2", Queue, 3);

	//2,3,4
	Queue.push_back(4);
	test("Test3", Queue, 4);

	//2,3,4,2
	Queue.push_back(2);
	test("Test4", Queue, 4);

	//3,4,2
	Queue.pop_front();
	test("Test5", Queue, 4);

	//4,2
	Queue.pop_front();
	test("Test6", Queue, 4);

	//2
	Queue.pop_front();
	test("Test7", Queue, 2);

	//2,6
	Queue.push_back(6);
	test("Test8", Queue, 6);

	//2,6,2
	Queue.push_back(2);
	test("Test9", Queue, 6);

	//2,6,2,5
	Queue.push_back(5);
	test("Test10", Queue, 6);

	//6,2,5
	Queue.pop_front();
	test("Test11", Queue, 6);

	//2,5
	Queue.pop_front();
	test("Test12", Queue, 5);

	//5
	Queue.pop_front();
	test("Test13", Queue, 5);

	//5,1
	Queue.push_back(2);
	test("Test14", Queue, 5);

	return 0;
}

void test(const char * vpTestName, CQMax & vQ, int vExpect)
{
	std::cout << vpTestName << std::endl;

	if(vQ.max() == vExpect)
		std::cout << "PASSED.\n";
	else
		std::cout << "FAILED.\n";

	std::cout << "\n";
}
