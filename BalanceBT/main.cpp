#include "BinaryTree.h"
#include <algorithm>

bool isBalanceBT(const SBinaryTreeNode* vpRoot, int& vDepth);
void test(const char* vpTestName, const SBinaryTreeNode* vpRoot, bool vExpect);

int main()
{
	{
		auto pNode0 = new SBinaryTreeNode(1);
		auto pNode1 = new SBinaryTreeNode(2);
		auto pNode2 = new SBinaryTreeNode(3);
		auto pNode3 = new SBinaryTreeNode(4);
		auto pNode4 = new SBinaryTreeNode(5);
		auto pNode5 = new SBinaryTreeNode(6);
		auto pNode6 = new SBinaryTreeNode(7);

		connectTreeNode(pNode0, pNode1, pNode2);
		connectTreeNode(pNode1, pNode3, pNode4);
		connectTreeNode(pNode2, pNode5, pNode6);

		test("Test1", pNode0, true);

		destroy(pNode0);
	}

	{
		auto pNode0 = new SBinaryTreeNode(1);
		auto pNode1 = new SBinaryTreeNode(2);
		auto pNode2 = new SBinaryTreeNode(3);
		auto pNode3 = new SBinaryTreeNode(4);
		auto pNode4 = new SBinaryTreeNode(5);
		auto pNode5 = new SBinaryTreeNode(6);
		auto pNode6 = new SBinaryTreeNode(7);

		connectTreeNode(pNode0, pNode1, pNode2);
		connectTreeNode(pNode1, pNode3, pNode4);
		connectTreeNode(pNode2, nullptr, pNode5);
		connectTreeNode(pNode4, pNode6, nullptr);

		test("Test2", pNode0, true);

		destroy(pNode0);
	}

	{
		auto pNode0 = new SBinaryTreeNode(1);
		auto pNode1 = new SBinaryTreeNode(2);
		auto pNode2 = new SBinaryTreeNode(3);
		auto pNode3 = new SBinaryTreeNode(4);
		auto pNode4 = new SBinaryTreeNode(5);
		auto pNode5 = new SBinaryTreeNode(6);

		connectTreeNode(pNode0, pNode1, pNode2);
		connectTreeNode(pNode1, pNode3, pNode4);
		connectTreeNode(pNode4, pNode5, nullptr);

		test("Test3", pNode0, false);

		destroy(pNode0);
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

		test("Test4", pNode0, false);

		destroy(pNode0);
	}

	{
		auto pNode0 = new SBinaryTreeNode(1);
		auto pNode1 = new SBinaryTreeNode(2);
		auto pNode2 = new SBinaryTreeNode(3);
		auto pNode3 = new SBinaryTreeNode(4);
		auto pNode4 = new SBinaryTreeNode(5);

		connectTreeNode(pNode0, nullptr, pNode1);
		connectTreeNode(pNode1, nullptr, pNode2);
		connectTreeNode(pNode2, nullptr, pNode3);
		connectTreeNode(pNode3, nullptr, pNode4);

		test("Test5", pNode0, false);

		destroy(pNode0);
	}

	{
		auto pNode0 = new SBinaryTreeNode(1);

		test("Test4", pNode0, true);

		destroy(pNode0);
	}

	{
		test("Test5", nullptr, true);
	}

	return 0;
}

bool isBalanceBT(const SBinaryTreeNode * vpRoot, int& vDepth)
{
	if (!vpRoot)
	{
		vDepth = 0;
		return true;
	}

	int Left, Right;
	if (isBalanceBT(vpRoot->pLeftChild, Left) && isBalanceBT(vpRoot->pRightChild, Right))
	{
		if (abs(Left - Right) <= 1)
		{
			vDepth = 1 + std::max(Left, Right);
			return true;
		}
	}

	return false;
}

void test(const char* vpTestName, const SBinaryTreeNode* vpRoot, bool vExpect)
{
	std::cout << vpTestName << std::endl;

	int Depth = 0;
	bool isBBT = isBalanceBT(vpRoot, Depth);
	if (isBBT == vExpect)
		std::cout << "PASSED.\n";
	else
		std::cout << "FAILED.\n";

	std::cout << std::endl;
}