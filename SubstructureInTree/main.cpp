#include "BinaryTree.h"
#include <exception>

//形参指针都没加const= =
bool isSubTree(SBinaryTreeNode* vpFirst, SBinaryTreeNode* vpSecond);
bool isSubTreeCore(SBinaryTreeNode* vpFirst, SBinaryTreeNode* vpSecond);
void test(const char* vpTestName, SBinaryTreeNode* vpFirst, SBinaryTreeNode* vpSecond, bool vExpect);

int main()
{
	{
		auto pNode0 = new SBinaryTreeNode(8);
		auto pNode1 = new SBinaryTreeNode(8);
		auto pNode2 = new SBinaryTreeNode(7);
		auto pNode3 = new SBinaryTreeNode(9);
		auto pNode4 = new SBinaryTreeNode(3);
		auto pNode5 = new SBinaryTreeNode(4);
		auto pNode6 = new SBinaryTreeNode(7);
		connectTreeNode(pNode0, pNode1, pNode2);
		connectTreeNode(pNode1, pNode3, pNode4);
		connectTreeNode(pNode4, pNode5, pNode6);

		auto pNode7 = new SBinaryTreeNode(8);
		auto pNode8 = new SBinaryTreeNode(9);
		auto pNode9 = new SBinaryTreeNode(2);
		connectTreeNode(pNode7, pNode8, pNode9);

		test("Test1", pNode0, pNode7, false);

		destroy(pNode0);
		destroy(pNode7);
	}

	{
		auto pNode0 = new SBinaryTreeNode(8);
		auto pNode1 = new SBinaryTreeNode(8);
		auto pNode2 = new SBinaryTreeNode(9);
		auto pNode3 = new SBinaryTreeNode(2);
		auto pNode4 = new SBinaryTreeNode(5);
		connectTreeNode(pNode0, pNode1, nullptr);
		connectTreeNode(pNode1, pNode2, nullptr);
		connectTreeNode(pNode2, pNode3, nullptr);
		connectTreeNode(pNode3, pNode4, nullptr);

		auto pNode7 = new SBinaryTreeNode(8);
		auto pNode8 = new SBinaryTreeNode(9);
		auto pNode9 = new SBinaryTreeNode(2);
		connectTreeNode(pNode7, pNode8, nullptr);
		connectTreeNode(pNode8, pNode9, nullptr);

		test("Test2", pNode0, pNode7, true);

		destroy(pNode0);
		destroy(pNode7);
	}

	{
		auto pNode0 = new SBinaryTreeNode(8);
		auto pNode1 = new SBinaryTreeNode(8);
		auto pNode2 = new SBinaryTreeNode(9);
		auto pNode3 = new SBinaryTreeNode(2);
		auto pNode4 = new SBinaryTreeNode(5);
		connectTreeNode(pNode0, pNode1, nullptr);
		connectTreeNode(pNode1, pNode2, nullptr);
		connectTreeNode(pNode2, pNode3, nullptr);
		connectTreeNode(pNode3, pNode4, nullptr);

		auto pNode7 = new SBinaryTreeNode(8);
		auto pNode8 = new SBinaryTreeNode(9);
		auto pNode9 = new SBinaryTreeNode(3);
		connectTreeNode(pNode7, pNode8, nullptr);
		connectTreeNode(pNode8, pNode9, nullptr);

		test("Test2", pNode0, pNode7, false);

		destroy(pNode0);
		destroy(pNode7);
	}

	{
		auto pNode0 = new SBinaryTreeNode(8);
		auto pNode1 = new SBinaryTreeNode(8);
		auto pNode2 = new SBinaryTreeNode(9);
		auto pNode3 = new SBinaryTreeNode(2);
		auto pNode4 = new SBinaryTreeNode(5);
		connectTreeNode(pNode0, nullptr, pNode1);
		connectTreeNode(pNode1, nullptr, pNode2);
		connectTreeNode(pNode2, nullptr, pNode3);
		connectTreeNode(pNode3, nullptr, pNode4);

		auto pNode7 = new SBinaryTreeNode(8);
		auto pNode8 = new SBinaryTreeNode(9);
		auto pNode9 = new SBinaryTreeNode(2);
		connectTreeNode(pNode7, nullptr, pNode8);
		connectTreeNode(pNode8, nullptr, pNode9);

		test("Test2", pNode0, pNode7, true);

		destroy(pNode0);
		destroy(pNode7);
	}

	{
		auto pNode0 = new SBinaryTreeNode(8);
		auto pNode1 = new SBinaryTreeNode(8);
		auto pNode2 = new SBinaryTreeNode(9);
		auto pNode3 = new SBinaryTreeNode(2);
		auto pNode4 = new SBinaryTreeNode(5);
		connectTreeNode(pNode0, nullptr, pNode1);
		connectTreeNode(pNode1, nullptr, pNode2);
		connectTreeNode(pNode2, nullptr, pNode3);
		connectTreeNode(pNode3, nullptr, pNode4);

		auto pNode7 = new SBinaryTreeNode(8);
		auto pNode8 = new SBinaryTreeNode(9);
		auto pNode9 = new SBinaryTreeNode(2);
		auto pNode10 = new SBinaryTreeNode(3);
		connectTreeNode(pNode7, nullptr, pNode8);
		connectTreeNode(pNode8, pNode10, pNode9);

		test("Test2", pNode0, pNode7, false);

		destroy(pNode0);
		destroy(pNode7);
	}

	{
		auto pNode0 = new SBinaryTreeNode(8);
		auto pNode1 = new SBinaryTreeNode(8);
		auto pNode2 = new SBinaryTreeNode(9);
		auto pNode3 = new SBinaryTreeNode(2);
		auto pNode4 = new SBinaryTreeNode(5);
		connectTreeNode(pNode0, nullptr, pNode1);
		connectTreeNode(pNode1, nullptr, pNode2);
		connectTreeNode(pNode2, nullptr, pNode3);
		connectTreeNode(pNode3, nullptr, pNode4);

		test("Test2", pNode0, nullptr, false);

		destroy(pNode0);
	}

	{
		auto pNode7 = new SBinaryTreeNode(8);
		auto pNode8 = new SBinaryTreeNode(9);
		auto pNode9 = new SBinaryTreeNode(2);
		auto pNode10 = new SBinaryTreeNode(3);
		connectTreeNode(pNode7, nullptr, pNode8);
		connectTreeNode(pNode8, pNode10, pNode9);

		test("Test2", nullptr, pNode7, false);

		destroy(pNode7);
	}

	{
		test("Test2", nullptr, nullptr, false);
	}

	return 0;
}

bool isSubTree(SBinaryTreeNode * vpFirst, SBinaryTreeNode * vpSecond)
{
	//if (!vpFirst || !vpSecond) throw std::runtime_error("Invalid input!");
	if (!vpFirst || !vpSecond) return false;

	bool IsSub = false;
	/*if (vpFirst->Value == vpSecond->Value)
		IsSub = isSubTreeCore(vpFirst, vpSecond);
	else
		IsSub = isSubTree(vpFirst->pLeftChild, vpSecond) || isSubTree(vpFirst->pRightChild, vpSecond);*/

	if (vpFirst->Value == vpSecond->Value)
		IsSub = isSubTreeCore(vpFirst, vpSecond);
	if (!IsSub)
		IsSub = isSubTree(vpFirst->pLeftChild, vpSecond);
	if (!IsSub)
		IsSub = isSubTree(vpFirst->pRightChild, vpSecond);

	return IsSub;
}

bool isSubTreeCore(SBinaryTreeNode * vpFirst, SBinaryTreeNode * vpSecond)
{
	if (!vpSecond)
		return true;

	if (!vpFirst)
		return false;

	if (vpFirst->Value != vpSecond->Value)
		return false;

	return  isSubTreeCore(vpFirst->pLeftChild, vpSecond->pLeftChild)
		&& isSubTreeCore(vpFirst->pRightChild, vpSecond->pRightChild);
}

void test(const char * vpTestName, SBinaryTreeNode * vpFirst, SBinaryTreeNode * vpSecond, bool vExpect)
{
	std::cout << vpTestName << std::endl;

	if (vExpect == isSubTree(vpFirst, vpSecond))
		std::cout << "PASSED." << std::endl;
	else
		std::cout << "FAILED." << std::endl;

	std::cout << "\n";
}
