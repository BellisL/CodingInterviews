#include "BinaryTree.h"
#include <sstream>

void serialize(SBinaryTreeNode* vpRoot, std::stringstream& vOut);
void deserialize(SBinaryTreeNode** vppRoot, std::stringstream& vIn);
bool read(std::stringstream& vSS, int* vNum);
bool isSameTree(const SBinaryTreeNode* vpRoot1, const SBinaryTreeNode* vpRoot2);;
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
		auto pNode0 = new SBinaryTreeNode(5);
		auto pNode1 = new SBinaryTreeNode(5);
		auto pNode2 = new SBinaryTreeNode(5);
		auto pNode3 = new SBinaryTreeNode(5);
		auto pNode4 = new SBinaryTreeNode(5);
		auto pNode5 = new SBinaryTreeNode(5);
		auto pNode6 = new SBinaryTreeNode(5);
		auto pNode7 = new SBinaryTreeNode(5);
		auto pNode8 = new SBinaryTreeNode(5);

		connectTreeNode(pNode0, nullptr, pNode1);
		connectTreeNode(pNode1, nullptr, pNode2);
		connectTreeNode(pNode2, pNode3, nullptr);
		connectTreeNode(pNode3, pNode4, nullptr);
		connectTreeNode(pNode4, pNode5, pNode6);
		connectTreeNode(pNode5, pNode7, nullptr);
		connectTreeNode(pNode6, nullptr, pNode8);

		test("Test5", pNode0);
	}

	return 0;
}

void serialize(SBinaryTreeNode * vpRoot, std::stringstream & vOut)
{
	if (!vpRoot)
	{
		vOut << "$,";
		return;
	}

	vOut << vpRoot->Value << ',';
	serialize(vpRoot->pLeftChild, vOut);
	serialize(vpRoot->pRightChild, vOut);
}

void deserialize(SBinaryTreeNode ** vppRoot, std::stringstream & vIn)
{
	int Num;
	if (read(vIn, &Num))
	{
		*vppRoot = new SBinaryTreeNode(Num);

		deserialize(&(*vppRoot)->pLeftChild, vIn);
		deserialize(&(*vppRoot)->pRightChild, vIn);
	}
}

bool read(std::stringstream & vSS, int* vNum)
{
	if (vSS.eof()) return false;

	char Buffer[32];
	Buffer[0] = '\0';

	char Ch;
	vSS >> Ch;
	int i = 0;
	while (!vSS.eof() && Ch != ',')
	{
		Buffer[i++] = Ch;
		vSS >> Ch;
	}

	bool isNumeric = false;
	if (i > 0 && Buffer[0] != '$')
	{
		*vNum = atoi(Buffer);
		isNumeric = true;
	}

	return isNumeric;
}

bool isSameTree(const SBinaryTreeNode * vpRoot1, const SBinaryTreeNode * vpRoot2)
{
	if (!vpRoot1 && !vpRoot2) return true;

	if (!vpRoot1 || !vpRoot2) return false;

	if (vpRoot1->Value != vpRoot2->Value) return false;

	return isSameTree(vpRoot1->pLeftChild, vpRoot2->pLeftChild)
		&& isSameTree(vpRoot1->pRightChild, vpRoot2->pRightChild);
}

void test(const char* vpTestName, SBinaryTreeNode* vpRoot)
{
	std::cout << vpTestName << std::endl;

	std::stringstream Ss;
	serialize(vpRoot, Ss);

	SBinaryTreeNode* pNewRoot = nullptr;
	deserialize(&pNewRoot, Ss);

	if (isSameTree(vpRoot, pNewRoot))
		std::cout << "PASSED.";
	else
		std::cout << "FAILED.";

	destroy(vpRoot);
	destroy(pNewRoot);

	std::cout << std::endl;
}