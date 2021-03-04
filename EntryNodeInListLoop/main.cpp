#include "List.h"
#include <iostream>
#include <exception>

int EntryNodeInLoop(std::shared_ptr<SListNode> vpHead);
void test(const char* vpTestName, std::shared_ptr<SListNode> vpHead);

int main()
{
	{
		auto p0 = std::make_shared<SListNode>(0);
		auto p1 = std::make_shared<SListNode>(1);
		auto p2 = std::make_shared<SListNode>(2);
		auto p3 = std::make_shared<SListNode>(3);
		auto p4 = std::make_shared<SListNode>(4);
		auto p5 = std::make_shared<SListNode>(5);
		auto p6 = std::make_shared<SListNode>(6);
		auto p7 = std::make_shared<SListNode>(7);
		p0->pListNode = p1;
		p1->pListNode = p2;
		p2->pListNode = p3;
		p3->pListNode = p4;
		p4->pListNode = p5;
		p5->pListNode = p6;
		p6->pListNode = p7;
		p7->pListNode = p3;

		test("Test1", p0);
	}

	{
		auto p0 = std::make_shared<SListNode>(0);
		auto p1 = std::make_shared<SListNode>(1);
		auto p2 = std::make_shared<SListNode>(2);
		auto p3 = std::make_shared<SListNode>(3);
		auto p4 = std::make_shared<SListNode>(4);
		p0->pListNode = p1;
		p1->pListNode = p2;
		p2->pListNode = p3;
		p3->pListNode = p4;
		p4->pListNode = p0;

		test("Test2", p0);
	}

	{
		auto p0 = std::make_shared<SListNode>(0);
		auto p1 = std::make_shared<SListNode>(1);
		auto p2 = std::make_shared<SListNode>(2);
		auto p3 = std::make_shared<SListNode>(3);
		auto p4 = std::make_shared<SListNode>(4);
		p0->pListNode = p1;
		p1->pListNode = p2;
		p2->pListNode = p3;
		p3->pListNode = p4;

		test("Test3", p0);
	}

	{
		auto p0 = std::make_shared<SListNode>(0);
		p0->pListNode = p0;

		test("Test4", p0);
	}

	return 0;
}

int EntryNodeInLoop(std::shared_ptr<SListNode> vpHead)
{
	if (!vpHead) throw std::runtime_error("Invalid input!");

	auto vpSlow = vpHead;
	auto vpFast = vpHead;

	do
	{
		vpSlow = vpSlow->pListNode;
		vpFast = vpFast->pListNode;

		if (!vpFast)
			throw std::runtime_error("No loop in the list!");
		else
			vpFast = vpFast->pListNode;

	} while (vpFast && vpFast != vpSlow);

	vpFast = vpHead;
	while (vpFast != vpSlow)
	{
		vpFast = vpFast->pListNode;
		vpSlow = vpSlow->pListNode;
	}

	return vpSlow->Value;
}

void test(const char * vpTestName, std::shared_ptr<SListNode> vpHead)
{
	std::cout << vpTestName << ": ";

	try
	{
		int Res = EntryNodeInLoop(vpHead);
		std::cout << Res;
	}
	catch (std::runtime_error e)
	{
		std::cout << e.what();
	}

	std::cout << "\n\n";
}
