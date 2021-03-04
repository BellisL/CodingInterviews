#include "List.h"
#include <iostream>

std::shared_ptr<SListNode> mergeSortedList(std::shared_ptr<SListNode> vp1, std::shared_ptr<SListNode> vp2);
void test(const char* vpTestName, std::shared_ptr<SListNode> vp1, std::shared_ptr<SListNode> vp2);

int main()
{
	auto p0 = std::make_shared<SListNode>(0);
	auto p2 = std::make_shared<SListNode>(2);
	auto p4 = std::make_shared<SListNode>(4);
	auto p6 = std::make_shared<SListNode>(6);
	p0->pListNode = p2;
	p2->pListNode = p4;
	p4->pListNode = p6;

	auto p1 = std::make_shared<SListNode>(1);
	auto p3 = std::make_shared<SListNode>(3);
	auto p5 = std::make_shared<SListNode>(5);
	auto p7 = std::make_shared<SListNode>(7);
	p1->pListNode = p3;
	p3->pListNode = p5;
	p5->pListNode = p7;

	test("Test1", p0, p1);

	std::shared_ptr<SListNode> pnull1 = nullptr;
	std::shared_ptr<SListNode> pnull2 = nullptr;

	test("Test2", p0, pnull2);
	test("Test3", pnull1, p1);
	test("Test4", pnull1, pnull2);

	return 0;
}

std::shared_ptr<SListNode> mergeSortedList(std::shared_ptr<SListNode> vp1, std::shared_ptr<SListNode> vp2)
{
	if (!vp1 && !vp2) return nullptr;
	if (!vp1) return vp2;
	if (!vp2) return vp1;

	std::shared_ptr<SListNode> pHead = nullptr;
	std::shared_ptr<SListNode> p = nullptr;

	if (vp1->Value <= vp2->Value)
	{
		pHead = vp1;
		vp1 = vp1->pListNode;
	}
	else
	{
		pHead = vp2;
		vp2 = vp2->pListNode;
	}

	p = pHead;

	while (vp1 && vp2)
	{
		if (vp1->Value <= vp2->Value)
		{
			p->pListNode = vp1;
			p = vp1;
			vp1 = vp1->pListNode;
		}
		else
		{
			p->pListNode = vp2;
			p = vp2;
			vp2 = vp2->pListNode;
		}
	}

	if (vp1)
		p->pListNode = vp1;

	if (vp2)
		p->pListNode = vp2;


	return pHead;
}

void test(const char * vpTestName, std::shared_ptr<SListNode> vp1, std::shared_ptr<SListNode> vp2)
{
	std::cout << vpTestName << std::endl;
	std::cout << "List1:\n";
	printList(vp1);
	std::cout << "List2:\n";
	printList(vp2);
	std::cout << "Merged List:\n";
	printList(mergeSortedList(vp1, vp2));

	std::cout << "\n";
}
