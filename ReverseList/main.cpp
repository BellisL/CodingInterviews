#include "List.h"
#include <iostream>
//如果链表设计时含空头结点，则可以采用头插的方式来反转
std::shared_ptr<SListNode> reverseList(CList& vList);
void test(const char* vpTestName, CList& vList);

int main()
{
	{
		CList List;

		test("Test1", List);
	}

	{
		CList List;
		List.add2Tail(0);

		test("Test2", List);
	}

	{
		CList List;
		List.add2Tail(0);
		List.add2Tail(1);
		List.add2Tail(2);
		List.add2Tail(3);
		List.add2Tail(4);

		test("Test3", List);
	}

	return 0;
}

std::shared_ptr<SListNode> reverseList(CList & vList)
{
	if (!vList.getHeadPtr()) return nullptr;

	auto pHead = vList.getHeadPtr();
	if (!pHead->pListNode) return pHead;

	auto pCur = pHead;
	std::shared_ptr<SListNode> pPre = nullptr;
	while (pCur->pListNode)
	{
		auto pNext = pCur->pListNode;
		pCur->pListNode = pPre;
		pPre = pCur;
		pCur = pNext;
	}

	pCur->pListNode = pPre;
	vList.setHead(pCur);

	return pCur;
}

void test(const char * vpTestName, CList & vList)
{
	std::cout << vpTestName << ":\n";

	vList.printList();
	reverseList(vList);
	std::cout << "After reverse: \n";
	vList.printList();

	std::cout << "\n";
}
