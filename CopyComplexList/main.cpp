#include <iostream>
#include <unordered_map>

struct SComplexListNode
{
	SComplexListNode() = default;
	SComplexListNode(int vValue) : Value(vValue) {}

	int Value;
	std::shared_ptr<SComplexListNode> pNext = nullptr;
	std::shared_ptr<SComplexListNode> pSibling = nullptr;
};

typedef std::shared_ptr<SComplexListNode> NodePtr;

void connectNodes(NodePtr vpA, const NodePtr vpN, const NodePtr vpS = nullptr);

NodePtr clone(const NodePtr pHead);

void cloneNodes(const NodePtr vpHead);
void connectSibling(const NodePtr vpHead);
NodePtr reconnectNodes(const NodePtr vpHead);
NodePtr clone_2(const NodePtr vpHead);

void printCList(const NodePtr vpHead);
void test(const char* vpTestName, const NodePtr vpHead);

int main()
{
	{
		auto pHead = std::make_shared<SComplexListNode>();
		auto pNode0 = std::make_shared<SComplexListNode>(1);
		auto pNode1 = std::make_shared<SComplexListNode>(2);
		auto pNode2 = std::make_shared<SComplexListNode>(3);
		auto pNode3 = std::make_shared<SComplexListNode>(4);
		auto pNode4 = std::make_shared<SComplexListNode>(5);

		connectNodes(pHead, pNode0);
		connectNodes(pNode0, pNode1, pNode2);
		connectNodes(pNode1, pNode2, pNode4);
		connectNodes(pNode2, pNode3);
		connectNodes(pNode3, pNode4, pNode1);

		test("Test1", pHead);
	}

	{
		auto pHead = std::make_shared<SComplexListNode>();
		auto pNode0 = std::make_shared<SComplexListNode>(1);
		auto pNode1 = std::make_shared<SComplexListNode>(2);
		auto pNode2 = std::make_shared<SComplexListNode>(3);
		auto pNode3 = std::make_shared<SComplexListNode>(4);
		auto pNode4 = std::make_shared<SComplexListNode>(5);

		connectNodes(pHead, pNode0);
		connectNodes(pNode0, pNode1);
		connectNodes(pNode1, pNode2, pNode4);
		connectNodes(pNode2, pNode3, pNode2);
		connectNodes(pNode3, pNode4, pNode1);

		test("Test2", pHead);
	}

	{
		auto pHead = std::make_shared<SComplexListNode>();
		auto pNode0 = std::make_shared<SComplexListNode>(1);
		auto pNode1 = std::make_shared<SComplexListNode>(2);
		auto pNode2 = std::make_shared<SComplexListNode>(3);
		auto pNode3 = std::make_shared<SComplexListNode>(4);
		auto pNode4 = std::make_shared<SComplexListNode>(5);

		connectNodes(pHead, pNode0);
		connectNodes(pNode0, pNode1);
		connectNodes(pNode1, pNode2, pNode3);
		connectNodes(pNode2, pNode3);
		connectNodes(pNode3, pNode4, pNode1);

		test("Test3", pHead);
	}

	{
		auto pHead = std::make_shared<SComplexListNode>();
		auto pNode0 = std::make_shared<SComplexListNode>(1);

		connectNodes(pHead, pNode0);

		test("Test4", pHead);
	}

	{
		auto pHead = std::make_shared<SComplexListNode>();

		test("Test5", pHead);
	}

	return 0;
}

void connectNodes(NodePtr vpA, const NodePtr vpN, const NodePtr vpS)
{
	_ASSERTE(vpA);

	vpA->pNext = vpN;
	vpA->pSibling = vpS;
}

NodePtr clone(const NodePtr pHead)
{
	if (!pHead) return nullptr;

	auto pTemp = pHead;
	auto pNewHead = std::make_shared<SComplexListNode>();
	auto pTempNew = pNewHead;

	std::unordered_map<NodePtr, NodePtr> HashSet;
	HashSet.insert({ pTemp, pTempNew });

	while (pTemp->pNext)
	{
		pTemp = pTemp->pNext;
		auto p = std::make_shared<SComplexListNode>(pTemp->Value);
		pTempNew->pNext = p;

		HashSet[pTemp] = p;
		pTempNew = p;
	}

	pTemp = pHead;
	pTempNew = pNewHead;
	while (pTemp->pNext)
	{
		pTemp = pTemp->pNext;
		pTempNew = pTempNew->pNext;
		if (pTemp->pSibling)
		{
			pTempNew->pSibling = HashSet[pTemp->pSibling];
		}
	}

	return pNewHead;
}

void cloneNodes(const NodePtr vpHead)
{
	if (!vpHead) return;
	auto pTemp = vpHead;
	pTemp = pTemp->pNext;

	while (pTemp)
	{
		auto pTempNew = std::make_shared<SComplexListNode>(pTemp->Value);
		pTempNew->pNext = pTemp->pNext;
		
		pTemp->pNext = pTempNew;
		pTemp = pTempNew->pNext;
	}

	//printCList(vpHead);
}

void connectSibling(const NodePtr vpHead)
{
	if (!vpHead) return;
	auto pTemp = vpHead;

	while (pTemp->pNext)
	{
		pTemp = pTemp->pNext;

		if (pTemp->pSibling)
			pTemp->pNext->pSibling = pTemp->pSibling->pNext;

		pTemp = pTemp->pNext;
	}
}

NodePtr reconnectNodes(const NodePtr vpHead)
{
	if (!vpHead) return nullptr;
	auto pTemp = vpHead;

	auto pNewHead = std::make_shared<SComplexListNode>();
	auto pNewTemp = pNewHead;

	while (pTemp->pNext)
	{
		pTemp = pTemp->pNext;
		pNewTemp->pNext = pTemp->pNext;
		pNewTemp = pNewTemp->pNext;

		pTemp->pNext = pNewTemp->pNext;
		pTemp = pNewTemp;
	}

	return pNewHead;
}

NodePtr clone_2(const NodePtr vpHead)
{
	cloneNodes(vpHead);
	connectSibling(vpHead);
	return reconnectNodes(vpHead);
}

void printCList(const NodePtr vpHead)
{
	if (vpHead && !vpHead->pNext) std::cout << "Empty List!";

	auto pTemp = vpHead;
	while (pTemp->pNext)
	{
		pTemp = pTemp->pNext;
		std::cout << pTemp->Value;
		if (pTemp->pSibling)
			std::cout << "(" << pTemp->pSibling->Value << ")";
		std::cout << "\t";
	}

	std::cout << std::endl;
}

void test(const char * vpTestName, const NodePtr vpHead)
{
	std::cout << vpTestName << ":\n";

	printCList(vpHead);

	auto pNewHead = clone(vpHead);

	printCList(pNewHead);

	pNewHead = clone_2(vpHead);

	printCList(vpHead);
	printCList(pNewHead);

	std::cout << std::endl;
}
