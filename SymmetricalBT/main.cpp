#include "BinaryTree.h"

bool isSymmetricalBT(const SBinaryTreeNode* vpRoot);
bool isSymmetrical(const SBinaryTreeNode* vpLeft, const SBinaryTreeNode* vpRight);
void test(const char* vpTestName, const SBinaryTreeNode* vpRoot, bool vExpect);

int main()
{
	{
		auto pNode0 = new SBinaryTreeNode(8);
		auto pNode1 = new SBinaryTreeNode(6);
		auto pNode2 = new SBinaryTreeNode(6);
		auto pNode3 = new SBinaryTreeNode(5);
		auto pNode4 = new SBinaryTreeNode(7);
		auto pNode5 = new SBinaryTreeNode(7);
		auto pNode6 = new SBinaryTreeNode(5);

		connectTreeNode(pNode0, pNode1, pNode2);
		connectTreeNode(pNode1, pNode3, pNode4);
		connectTreeNode(pNode2, pNode5, pNode6);

		test("Test1", pNode0, true);

		destroy(pNode0);
	}

	{
		auto pNode0 = new SBinaryTreeNode(8);
		auto pNode1 = new SBinaryTreeNode(6);
		auto pNode2 = new SBinaryTreeNode(9);
		auto pNode3 = new SBinaryTreeNode(5);
		auto pNode4 = new SBinaryTreeNode(7);
		auto pNode5 = new SBinaryTreeNode(7);
		auto pNode6 = new SBinaryTreeNode(5);

		connectTreeNode(pNode0, pNode1, pNode2);
		connectTreeNode(pNode1, pNode3, pNode4);
		connectTreeNode(pNode2, pNode5, pNode6);

		test("Test2", pNode0, false);

		destroy(pNode0);
	}

	{
		auto pNode0 = new SBinaryTreeNode(8);
		auto pNode1 = new SBinaryTreeNode(6);
		auto pNode2 = new SBinaryTreeNode(6);
		auto pNode3 = new SBinaryTreeNode(5);
		auto pNode4 = new SBinaryTreeNode(7);
		auto pNode5 = new SBinaryTreeNode(7);

		connectTreeNode(pNode0, pNode1, pNode2);
		connectTreeNode(pNode1, pNode3, pNode4);
		connectTreeNode(pNode2, pNode5, nullptr);

		test("Test3", pNode0, false);

		destroy(pNode0);
	}

	{
		auto pNode0 = new SBinaryTreeNode(5);
		auto pNode1 = new SBinaryTreeNode(3);
		auto pNode2 = new SBinaryTreeNode(3);
		auto pNode3 = new SBinaryTreeNode(4);
		auto pNode4 = new SBinaryTreeNode(4);
		auto pNode5 = new SBinaryTreeNode(2);
		auto pNode6 = new SBinaryTreeNode(2);
		auto pNode7 = new SBinaryTreeNode(1);
		auto pNode8 = new SBinaryTreeNode(1);

		connectTreeNode(pNode0, pNode1, pNode2);
		connectTreeNode(pNode1, pNode3, nullptr);
		connectTreeNode(pNode3, pNode5, nullptr);
		connectTreeNode(pNode5, pNode7, nullptr);
		connectTreeNode(pNode2, nullptr, pNode4);
		connectTreeNode(pNode4, nullptr, pNode6);
		connectTreeNode(pNode6, nullptr, pNode8);

		test("Test4", pNode0, true);

		destroy(pNode0);
	}

	{
		auto pNode0 = new SBinaryTreeNode(5);
		auto pNode1 = new SBinaryTreeNode(3);
		auto pNode2 = new SBinaryTreeNode(3);
		auto pNode3 = new SBinaryTreeNode(4);
		auto pNode4 = new SBinaryTreeNode(4);
		auto pNode5 = new SBinaryTreeNode(6);
		auto pNode6 = new SBinaryTreeNode(2);
		auto pNode7 = new SBinaryTreeNode(1);
		auto pNode8 = new SBinaryTreeNode(1);

		connectTreeNode(pNode0, pNode1, pNode2);
		connectTreeNode(pNode1, pNode3, nullptr);
		connectTreeNode(pNode3, pNode5, nullptr);
		connectTreeNode(pNode5, pNode7, nullptr);
		connectTreeNode(pNode2, nullptr, pNode4);
		connectTreeNode(pNode4, nullptr, pNode6);
		connectTreeNode(pNode6, nullptr, pNode8);

		test("Test5", pNode0, false);

		destroy(pNode0);
	}

	{
		auto pNode0 = new SBinaryTreeNode(5);
		auto pNode1 = new SBinaryTreeNode(3);
		auto pNode2 = new SBinaryTreeNode(3);
		auto pNode3 = new SBinaryTreeNode(4);
		auto pNode4 = new SBinaryTreeNode(4);
		auto pNode5 = new SBinaryTreeNode(2);
		auto pNode6 = new SBinaryTreeNode(2);
		auto pNode8 = new SBinaryTreeNode(1);

		connectTreeNode(pNode0, pNode1, pNode2);
		connectTreeNode(pNode1, pNode3, nullptr);
		connectTreeNode(pNode3, pNode5, nullptr);
		connectTreeNode(pNode2, nullptr, pNode4);
		connectTreeNode(pNode4, nullptr, pNode6);
		connectTreeNode(pNode6, nullptr, pNode8);

		test("Test6", pNode0, false);

		destroy(pNode0);
	}

	{
		auto pNode0 = new SBinaryTreeNode(0);

		test("Test7", pNode0, true);

		destroy(pNode0);
	}

	{
		test("Test8", nullptr, true);
	}

	return 0;
}

bool isSymmetricalBT(const SBinaryTreeNode * vpRoot)
{
	return isSymmetrical(vpRoot, vpRoot);
}

bool isSymmetrical(const SBinaryTreeNode * vpLeft, const SBinaryTreeNode * vpRight)
{
	if (!vpLeft && !vpRight) return true;

	if (!vpLeft || !vpRight) return false;

	if (vpLeft->Value != vpRight->Value) return false;

	return isSymmetrical(vpLeft->pLeftChild, vpRight->pRightChild)
		&& isSymmetrical(vpLeft->pRightChild, vpRight->pLeftChild);
}

void test(const char * vpTestName, const SBinaryTreeNode * vpRoot, bool vExpect)
{
	std::cout << vpTestName << std::endl;

	if (vExpect == isSymmetricalBT(vpRoot))
		std::cout << "PASSED." << std::endl;
	else
		std::cout << "FAILED." << std::endl;

	std::cout << "\n";
}
