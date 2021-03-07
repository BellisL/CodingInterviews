#include "BinaryTree.h"

void mirrorOfBT(SBinaryTreeNode* vpRoot);
void test(const char* vpTestName, CBinaryTree* vpTree);

int main()
{
	{
		auto pNode0 = new SBinaryTreeNode(8);
		auto pNode1 = new SBinaryTreeNode(6);
		auto pNode2 = new SBinaryTreeNode(10);
		auto pNode3 = new SBinaryTreeNode(5);
		auto pNode4 = new SBinaryTreeNode(7);
		auto pNode5 = new SBinaryTreeNode(9);
		auto pNode6 = new SBinaryTreeNode(11);

		auto pTree = new CBinaryTree(pNode0);
		pTree->connect2Tree(pNode0, pNode1, pNode2);
		pTree->connect2Tree(pNode1, pNode3, pNode4);
		pTree->connect2Tree(pNode2, pNode5, pNode6);

		test("Test1", pTree);
	}

	{
		auto pNode0 = new SBinaryTreeNode(8);
		auto pNode1 = new SBinaryTreeNode(7);
		auto pNode2 = new SBinaryTreeNode(6);
		auto pNode3 = new SBinaryTreeNode(5);
		auto pNode4 = new SBinaryTreeNode(4);

		auto pTree = new CBinaryTree(pNode0);
		pTree->connect2Tree(pNode0, pNode1, nullptr);
		pTree->connect2Tree(pNode1, pNode2, nullptr);
		pTree->connect2Tree(pNode2, pNode3, nullptr);
		pTree->connect2Tree(pNode3, pNode4, nullptr);

		test("Test2", pTree);
	}

	{
		auto pNode0 = new SBinaryTreeNode(8);
		auto pNode1 = new SBinaryTreeNode(7);
		auto pNode2 = new SBinaryTreeNode(6);
		auto pNode3 = new SBinaryTreeNode(5);
		auto pNode4 = new SBinaryTreeNode(4);

		auto pTree = new CBinaryTree(pNode0);
		pTree->connect2Tree(pNode0, nullptr, pNode1);
		pTree->connect2Tree(pNode1, nullptr, pNode2);
		pTree->connect2Tree(pNode2, nullptr, pNode3);
		pTree->connect2Tree(pNode3, nullptr, pNode4);

		test("Test3", pTree);
	}

	{
		auto pNode0 = new SBinaryTreeNode(8);

		auto pTree = new CBinaryTree(pNode0);

		test("Test4", pTree);
	}

	return 0;
}

void mirrorOfBT(SBinaryTreeNode * vpRoot)
{
	if (!vpRoot) return;

	if (vpRoot->pLeftChild || vpRoot->pRightChild)
	{
		auto pTemp = vpRoot->pLeftChild;
		vpRoot->pLeftChild = vpRoot->pRightChild;
		vpRoot->pRightChild = pTemp;
		mirrorOfBT(vpRoot->pLeftChild);
		mirrorOfBT(vpRoot->pRightChild);
	}
}

void test(const char * vpTestName, CBinaryTree* vpTree)
{
	std::cout << vpTestName << ": \n";
	vpTree->printTree();

	mirrorOfBT(vpTree->getRoot());
	std::cout << "\nAfter mirror:\n";
	vpTree->printTree();
	std::cout << std::endl;
}
