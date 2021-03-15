#include "List.h"
#include <iostream>

typedef std::shared_ptr<SListNode> NodePtr;

NodePtr getFirstCommonNode(const NodePtr vpHead1, const NodePtr vpHead2);
void test(const char* vpTestName, const NodePtr vpHead1, const NodePtr vpHead2, bool vExpect);

int main()
{
	{
		auto pNode01 = std::make_shared<SListNode>();
		auto pNode1 = std::make_shared<SListNode>(1);
		auto pNode2 = std::make_shared<SListNode>(2);
		auto pNode3 = std::make_shared<SListNode>(3);
		pNode01->pListNode = pNode1;
		pNode1->pListNode = pNode2;
		pNode2->pListNode = pNode3;

		auto pNode02 = std::make_shared<SListNode>();
		auto pNode4 = std::make_shared<SListNode>(4);
		auto pNode5 = std::make_shared<SListNode>(5);
		pNode02->pListNode = pNode4;
		pNode4->pListNode = pNode5;

		auto pNode6 = std::make_shared<SListNode>(6);
		auto pNode7 = std::make_shared<SListNode>(7);
		pNode6->pListNode = pNode7;

		pNode3->pListNode = pNode6;
		pNode5->pListNode = pNode6;

		test("Test1", pNode01, pNode02, true);
	}

	{
		auto pNode01 = std::make_shared<SListNode>();
		auto pNode1 = std::make_shared<SListNode>(1);
		auto pNode2 = std::make_shared<SListNode>(2);
		auto pNode3 = std::make_shared<SListNode>(3);
		auto pNode4 = std::make_shared<SListNode>(4);
		pNode01->pListNode = pNode1;
		pNode1->pListNode = pNode2;
		pNode2->pListNode = pNode3;
		pNode3->pListNode = pNode4;

		auto pNode02 = std::make_shared<SListNode>();
		auto pNode5 = std::make_shared<SListNode>(5);
		auto pNode6 = std::make_shared<SListNode>(6);
		auto pNode7 = std::make_shared<SListNode>(7);
		pNode02->pListNode = pNode5;
		pNode5->pListNode = pNode6;
		pNode6->pListNode = pNode7;

		test("Test2", pNode01, pNode02, false);
	}

	{
		auto pNode01 = std::make_shared<SListNode>();
		auto pNode1 = std::make_shared<SListNode>(1);
		auto pNode2 = std::make_shared<SListNode>(2);
		auto pNode3 = std::make_shared<SListNode>(3);
		auto pNode4 = std::make_shared<SListNode>(4);
		pNode01->pListNode = pNode1;
		pNode1->pListNode = pNode2;
		pNode2->pListNode = pNode3;
		pNode3->pListNode = pNode4;

		auto pNode02 = std::make_shared<SListNode>();
		auto pNode5 = std::make_shared<SListNode>(5);
		auto pNode6 = std::make_shared<SListNode>(6);
		pNode02->pListNode = pNode5;
		pNode5->pListNode = pNode6;

		auto pNode7 = std::make_shared<SListNode>(7);

		pNode4->pListNode = pNode7;
		pNode6->pListNode = pNode7;

		test("Test3", pNode01, pNode02, true);
	}

	{
		auto pNode01 = std::make_shared<SListNode>();
		auto pNode1 = std::make_shared<SListNode>(1);
		auto pNode2 = std::make_shared<SListNode>(2);
		auto pNode3 = std::make_shared<SListNode>(3);
		auto pNode4 = std::make_shared<SListNode>(4);
		pNode01->pListNode = pNode1;
		pNode1->pListNode = pNode2;
		pNode2->pListNode = pNode3;
		pNode3->pListNode = pNode4;

		auto pNode02 = std::make_shared<SListNode>();
		pNode02->pListNode = pNode1;

		test("Test4", pNode01, pNode02, true);
	}

	return 0;
}

NodePtr getFirstCommonNode(const NodePtr vpHead1, const NodePtr vpHead2)
{
	if (!vpHead1 || !vpHead2) return nullptr;

	int Cntp1 = 0;
	auto pTemp1 = vpHead1->pListNode;
	while (pTemp1)
	{
		++Cntp1;
		pTemp1 = pTemp1->pListNode;
	}

	int Cntp2 = 0;
	auto pTemp2 = vpHead2->pListNode;
	while (pTemp2)
	{
		++Cntp2;
		pTemp2 = pTemp2->pListNode;
	}

	int Minus = 0;
	if (Cntp1 >= Cntp2)
	{
		Minus = Cntp1 - Cntp2;
		pTemp1 = vpHead1->pListNode;
		pTemp2 = vpHead2->pListNode;
	}
	else
	{
		Minus = Cntp2 - Cntp1;
		pTemp1 = vpHead2->pListNode;
		pTemp2 = vpHead1->pListNode;
	}

	NodePtr pRes = nullptr;
	while (Minus--)
	{
		pTemp1 = pTemp1->pListNode;
	}

	while (pTemp1 && pTemp2)
	{
		if (pTemp1 == pTemp2)
		{
			pRes = pTemp1;
			break;
		}
		pTemp1 = pTemp1->pListNode;
		pTemp2 = pTemp2->pListNode;
	}

	return pRes;
}

void test(const char * vpTestName, const NodePtr vpHead1, const NodePtr vpHead2, bool vExpect)
{
	std::cout << vpTestName << std::endl;

	auto pRes = getFirstCommonNode(vpHead1, vpHead2);
	if (pRes && vExpect)
		std::cout << "PASSED: " << pRes->Value << std::endl;
	else if(!pRes && !vExpect)
		std::cout << "PASSED.\n";
	else
		std::cout << "FAILED.\n";

	std::cout << std::endl;
}
