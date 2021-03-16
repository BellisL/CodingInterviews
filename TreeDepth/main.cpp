#include "BinaryTree.h"
#include <algorithm>

int treeDepth(const SBinaryTreeNode* vpRoot);
void test(const char* vpTestName, const SBinaryTreeNode* vpRoot, int vExpect);

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
		connectTreeNode(pNode2, nullptr, pNode5);
		connectTreeNode(pNode4, pNode6, nullptr);

		test("Test1", pNode0, 4);

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

		test("Test2", pNode0, 5);

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

		test("Test3", pNode0, 5);

		destroy(pNode0);
	}

	{
		auto pNode0 = new SBinaryTreeNode(1);

		test("Test4", pNode0, 1);

		destroy(pNode0);
	}

	{
		test("Test5", nullptr, 0);
	}

	return 0;
}

int treeDepth(const SBinaryTreeNode * vpRoot)
{
	if (!vpRoot) return 0;

	return 1 + std::max(treeDepth(vpRoot->pLeftChild), treeDepth(vpRoot->pRightChild));;
}

void test(const char* vpTestName, const SBinaryTreeNode* vpRoot, int vExpect)
{
	std::cout << vpTestName << std::endl;

	auto Depth = treeDepth(vpRoot);
	if (Depth == vExpect)
		std::cout << "PASSED.\n";
	else
		std::cout << "FAILED.\n";

	std::cout << std::endl;
}