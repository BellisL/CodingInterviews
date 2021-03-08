#include "BinaryTree.h"
#include <deque>
#include <stack>

void printTreeInLines(SBinaryTreeNode* vpRoot);
void printTreeAL(SBinaryTreeNode* vpRoot);
void printTreeZigZag(SBinaryTreeNode* vpRoot);
void test(const char* vpTestName, SBinaryTreeNode* vpRoot);

int main()
{
	{
		auto pNode0 = new SBinaryTreeNode(8);
		auto pNode1 = new SBinaryTreeNode(6);
		auto pNode2 = new SBinaryTreeNode(9);
		auto pNode3 = new SBinaryTreeNode(5);
		auto pNode4 = new SBinaryTreeNode(7);
		auto pNode5 = new SBinaryTreeNode(3);
		auto pNode6 = new SBinaryTreeNode(5);

		connectTreeNode(pNode0, pNode1, pNode2);
		connectTreeNode(pNode1, pNode3, pNode4);
		connectTreeNode(pNode2, pNode5, pNode6);

		test("Test1", pNode0);

		destroy(pNode0);
	}

	{
		auto pNode0 = new SBinaryTreeNode(1);
		auto pNode1 = new SBinaryTreeNode(2);
		auto pNode2 = new SBinaryTreeNode(3);
		auto pNode3 = new SBinaryTreeNode(4);
		auto pNode4 = new SBinaryTreeNode(5);

		connectTreeNode(pNode0, pNode1, nullptr);
		connectTreeNode(pNode1, pNode2, nullptr);
		connectTreeNode(pNode2, pNode3, nullptr);
		connectTreeNode(pNode3, pNode4, nullptr);

		test("Test2", pNode0);

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

		test("Test3", pNode0);

		destroy(pNode0);
	}

	{
		auto pNode0 = new SBinaryTreeNode(0);

		test("Test4", pNode0);

		destroy(pNode0);
	}

	{
		test("Test5", nullptr);
	}

	return 0;
}

void printTreeInLines(SBinaryTreeNode * vpRoot)
{
	if (!vpRoot) return;

	std::deque<SBinaryTreeNode*> DQ;
	DQ.push_back(vpRoot);

	int ToBePrinted = 1;
	int NextLevel = 0;

	while (!DQ.empty())
	{
		auto pNode = DQ.front();
		std::cout << pNode->Value << "\t";

		if (pNode->pLeftChild)
		{
			DQ.push_back(pNode->pLeftChild);
			++NextLevel;
		}

		if (pNode->pRightChild)
		{
			DQ.push_back(pNode->pRightChild);
			++NextLevel;
		}

		DQ.pop_front();
		--ToBePrinted;
		if (!ToBePrinted)
		{
			std::cout << std::endl;
			ToBePrinted = NextLevel;
			NextLevel = 0;
		}
	}
}

void printTreeAL(SBinaryTreeNode * vpRoot)
{
	if (!vpRoot) return;

	std::deque<SBinaryTreeNode*> DQ;
	DQ.push_back(vpRoot);//这里为什么不能用底层指针呢？

	while (!DQ.empty())
	{
		auto pNode = DQ.front();
		std::cout << pNode->Value << "\t";

		if (pNode->pLeftChild)
			DQ.push_back(pNode->pLeftChild);

		if (pNode->pRightChild)
			DQ.push_back(pNode->pRightChild);

		DQ.pop_front();
	}

	std::cout << std::endl;
}

void printTreeZigZag(SBinaryTreeNode * vpRoot)
{
	if (!vpRoot) return;

	std::stack<SBinaryTreeNode*> S[2];

	int CurIndex = 0;
	int NextIndex = 1 - CurIndex;
	S[CurIndex].push(vpRoot);

	while (!S[0].empty() || !S[1].empty())
	{
		auto pNode = S[CurIndex].top();
		S[CurIndex].pop();

		std::cout << pNode->Value << "\t";

		if (CurIndex)
		{
			if (pNode->pRightChild)
				S[NextIndex].push(pNode->pRightChild);
			if (pNode->pLeftChild)
				S[NextIndex].push(pNode->pLeftChild);
		}
		else
		{
			if (pNode->pLeftChild)
				S[NextIndex].push(pNode->pLeftChild);
			if (pNode->pRightChild)
				S[NextIndex].push(pNode->pRightChild);
		}

		if (S[CurIndex].empty())
		{
			std::cout << std::endl;
			CurIndex = 1 - CurIndex;
			NextIndex = 1 - CurIndex;
		}
	}

}

void test(const char * vpTestName, SBinaryTreeNode * vpRoot)
{
	std::cout << vpTestName << ":\n";

	printTreeInLines(vpRoot);
	std::cout << std::endl;
	printTreeAL(vpRoot);
	std::cout << std::endl;
	printTreeZigZag(vpRoot);
	std::cout << std::endl;
}
