#include "BinaryTree.h"

SBinaryTreeNode* convertBST2List(SBinaryTreeNode* vpRoot);
void convertNode(SBinaryTreeNode* vpRoot, SBinaryTreeNode** vppLastNode);
void test(const char* vpTestName, SBinaryTreeNode* vpRoot);

int main()
{
	{
		auto pNode0 = new SBinaryTreeNode(10);
		auto pNode1 = new SBinaryTreeNode(6);
		auto pNode2 = new SBinaryTreeNode(14);
		auto pNode3 = new SBinaryTreeNode(4);
		auto pNode4 = new SBinaryTreeNode(8);
		auto pNode5 = new SBinaryTreeNode(12);
		auto pNode6 = new SBinaryTreeNode(16);

		connectTreeNode(pNode0, pNode1, pNode2);
		connectTreeNode(pNode1, pNode3, pNode4);
		connectTreeNode(pNode2, pNode5, pNode6);

		test("Test1", pNode0);
	}

	{
		auto pNode0 = new SBinaryTreeNode(5);
		auto pNode1 = new SBinaryTreeNode(4);
		auto pNode2 = new SBinaryTreeNode(3);
		auto pNode3 = new SBinaryTreeNode(2);
		auto pNode4 = new SBinaryTreeNode(1);

		connectTreeNode(pNode0, pNode1, nullptr);
		connectTreeNode(pNode1, pNode2, nullptr);
		connectTreeNode(pNode2, pNode3, nullptr);
		connectTreeNode(pNode3, pNode4, nullptr);

		test("Test2", pNode0);
	}

	{
		auto pNode0 = new SBinaryTreeNode(5);
		auto pNode1 = new SBinaryTreeNode(4);
		auto pNode2 = new SBinaryTreeNode(3);
		auto pNode3 = new SBinaryTreeNode(2);
		auto pNode4 = new SBinaryTreeNode(1);

		connectTreeNode(pNode0, nullptr, pNode1);
		connectTreeNode(pNode1, nullptr, pNode2);
		connectTreeNode(pNode2, nullptr, pNode3);
		connectTreeNode(pNode3, nullptr, pNode4);

		test("Test3", pNode0);
	}

	{
		auto pNode0 = new SBinaryTreeNode(5);

		test("Test4", pNode0);
	}

	{
		test("Test5", nullptr);
	}

	return 0;
}

SBinaryTreeNode * convertBST2List(SBinaryTreeNode * vpRoot)
{
	SBinaryTreeNode* pLastNode = nullptr;
	convertNode(vpRoot, &pLastNode);

	while (pLastNode && pLastNode->pLeftChild)
		pLastNode = pLastNode->pLeftChild;

	return pLastNode;
}

void convertNode(SBinaryTreeNode * vpRoot, SBinaryTreeNode ** vppLastNode)
{
	if (!vpRoot) return;

	auto pCurNode = vpRoot;

	if (pCurNode->pLeftChild)
		convertNode(pCurNode->pLeftChild, vppLastNode);

	pCurNode->pLeftChild = *vppLastNode;
	if (*vppLastNode)
		(*vppLastNode)->pRightChild = pCurNode;

	*vppLastNode = pCurNode;
	if (pCurNode->pRightChild)
		convertNode(pCurNode->pRightChild, vppLastNode);
}

void test(const char* vpTestName, SBinaryTreeNode* vpRoot)
{
	std::cout << vpTestName << std::endl;
	auto pHead = convertBST2List(vpRoot);
	auto pNode = pHead;

	while (pHead)
	{
		std::cout << pHead->Value << "\t";
		if (pHead->pRightChild)
			pHead = pHead->pRightChild;
		else
			break;
	}
	std::cout << std::endl;

	//pHead = pHead->pLeftChild;
	while (pHead)
	{
		std::cout << pHead->Value << "\t";
		pHead = pHead->pLeftChild;
	}

	std::cout << std::endl;

	while (pNode)
	{
		auto pTemp = pNode;
		pNode = pNode->pRightChild;

		delete pTemp;
		pTemp = nullptr;
	}
}
