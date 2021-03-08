#include "BinaryTree.h"
#include <deque>

void pathInTree(const SBinaryTreeNode* vpRoot, int vSum);
void pathInTreeCore(const SBinaryTreeNode* vpRoot, std::deque<int>& vDeque, int vSum);
void printSet(std::deque<int>& vDeque);
void test(const char* vpTestName, const SBinaryTreeNode* vpRoot, int vSum);

int main()
{
	{
		auto pNode0 = new SBinaryTreeNode(10);
		auto pNode1 = new SBinaryTreeNode(5);
		auto pNode2 = new SBinaryTreeNode(12);
		auto pNode3 = new SBinaryTreeNode(4);
		auto pNode4 = new SBinaryTreeNode(7);

		connectTreeNode(pNode0, pNode1, pNode2);
		connectTreeNode(pNode1, pNode3, pNode4);

		test("Test1", pNode0, 22);

		destroy(pNode0);
	}

	{
		auto pNode0 = new SBinaryTreeNode(10);
		auto pNode1 = new SBinaryTreeNode(5);
		auto pNode2 = new SBinaryTreeNode(12);
		auto pNode3 = new SBinaryTreeNode(4);
		auto pNode4 = new SBinaryTreeNode(7);

		connectTreeNode(pNode0, pNode1, pNode2);
		connectTreeNode(pNode1, pNode3, pNode4);

		test("Test2", pNode0, 15);

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

		test("Test3", pNode0, 15);

		destroy(pNode0);
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

		test("Test4", pNode0, 16);

		destroy(pNode0);
	}

	{
		auto pNode0 = new SBinaryTreeNode(5);

		connectTreeNode(pNode0, nullptr, nullptr);

		test("Test5", pNode0, 5);

		destroy(pNode0);
	}

	{
		test("Test6", nullptr, 0);
	}

	return 0;
}

void pathInTree(const SBinaryTreeNode * vpRoot, int vSum)
{
	if (!vpRoot) return;

	if (vpRoot->Value > vSum) return;

	std::deque<int> D;
	pathInTreeCore(vpRoot, D, vSum);
}

void pathInTreeCore(const SBinaryTreeNode * vpRoot, std::deque<int>& vDeque, int vSum)
{
	vDeque.push_back(vpRoot->Value);
	vSum -= vpRoot->Value;

	if (!vpRoot->pLeftChild && !vpRoot->pRightChild)
	{
		if(!vSum)
			printSet(vDeque);
		else
			return;
	}

	if (vpRoot->pLeftChild)
	{
		pathInTreeCore(vpRoot->pLeftChild, vDeque, vSum);
		if (!vDeque.empty())
			vDeque.pop_back();
	}

	if (vpRoot->pRightChild)
	{
		pathInTreeCore(vpRoot->pRightChild, vDeque, vSum);
		if (!vDeque.empty())
			vDeque.pop_back();
	}
}

void printSet(std::deque<int>& vDeque)
{
	for(const auto& Num : vDeque)
		std::cout << Num << "\t";
	std::cout << std::endl;
}

void test(const char* vpTestName, const SBinaryTreeNode * vpRoot, int vSum)
{
	std::cout << vpTestName << ":\n";
	pathInTree(vpRoot, vSum);
	std::cout << std::endl;
}
