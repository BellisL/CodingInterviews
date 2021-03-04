#include "List.h"
#include <iostream>
#include <exception>

int KthNodeFromEnd(const CList& vList, int vK);
void test(const char* vpTestName, const CList& vList, int vK, int vExpect);

int main()
{
	{
		CList List;
		List.add2Tail(10);
		List.add2Tail(9);
		List.add2Tail(8);
		List.add2Tail(7);
		List.add2Tail(6);
		List.add2Tail(5);
		List.add2Tail(4);
		List.add2Tail(3);
		List.add2Tail(2);
		List.add2Tail(1);

		test("Test1", List, 3, 3);
		test("Test2", List, 10, 10);
		test("Test3", List, 11, -1);
	}

	{
		CList List;
		test("Test4", List, 0, -1);
		test("Test5", List, 1, -1);
	}

	{
		CList List;
		List.add2Tail(1);
		test("Test6", List, 0, -1);
		test("Test7", List, 1, 1);
	}

	return 0;
}

int KthNodeFromEnd(const CList & vList, int vK)
{
	if (vK <= 0 || !vList.getHeadPtr()) throw std::runtime_error("Invalid input!");

	auto pHead = vList.getHeadPtr();
	auto pFast = pHead;

	while (--vK)
	{
		pFast = pFast->pListNode;
		if (!pFast) throw std::runtime_error("K is greater than the size of list!");
	}

	while (pFast->pListNode)
	{
		pHead = pHead->pListNode;
		pFast = pFast->pListNode;
	}

	return pHead->Value;
}

void test(const char* vpTestName, const CList & vList, int vK, int vExpect)
{
	std::cout << vpTestName << ":\n";
	vList.printList();
	std::cout << "Search " << vK << "th node from the end." << std::endl;
	try
	{
		int Res = KthNodeFromEnd(vList, vK);
		if (Res == vExpect)
			std::cout << "PASSED.";
		else
			std::cout << "FAILED.";
	}
	catch (std::runtime_error e)
	{
		std::cout << e.what();
	}

	std::cout <<"\n\n";
}
