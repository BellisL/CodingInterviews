#include "BinaryTree.h"
#include <stack>

int kthMinInBST(const SBinaryTreeNode* vpRoot, int vK);
void test(const char* vpTestName, const SBinaryTreeNode* vpRoot, int vK, int vExpect);

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

		connectTreeNode(pNode0, pNode1, pNode2);
		connectTreeNode(pNode1, pNode3, pNode4);
		connectTreeNode(pNode2, pNode5, pNode6);

		test("Test1A", pNode0, 0, -1);
		test("Test1B", pNode0, 1, 5);
		test("Test1C", pNode0, 2, 6);
		test("Test1D", pNode0, 3, 7);
		test("Test1E", pNode0, 4, 8);
		test("Test1F", pNode0, 5, 9);
		test("Test1G", pNode0, 6, 10);
		test("Test1H", pNode0, 7, 11);
		test("Test1I", pNode0, 8, -1);

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

		test("Test2A", pNode0, 0, -1);
		test("Test2B", pNode0, 1, 1);
		test("Test2C", pNode0, 2, 2);
		test("Test2D", pNode0, 3, 3);
		test("Test2E", pNode0, 4, 4);
		test("Test2F", pNode0, 5, 5);
		test("Test2G", pNode0, 6, -1);

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

		test("Test3A", pNode0, 0, -1);
		test("Test3B", pNode0, 1, 1);
		test("Test3C", pNode0, 2, 2);
		test("Test3D", pNode0, 3, 3);
		test("Test3E", pNode0, 4, 4);
		test("Test3F", pNode0, 5, 5);
		test("Test3G", pNode0, 6, -1);

		destroy(pNode0);
	}

	{
		auto pNode0 = new SBinaryTreeNode(1);

		test("Test4A", pNode0, 0, -1);
		test("Test4B", pNode0, 1, 1);
		test("Test4C", pNode0, 2, -1);

		destroy(pNode0);
	}

	{
		test("Test5A", nullptr, 0, -1);
		test("Test5B", nullptr, 1, -1);
	}

	return 0;
}

int kthMinInBST(const SBinaryTreeNode * vpRoot, int vK)
{
	if (!vpRoot) throw std::runtime_error("Empty Tree!");

	int KthNum = -1;
	if (vK <= 0) return KthNum;

	auto p = vpRoot;
	std::stack<const SBinaryTreeNode*> NodeS;
	while (p || !NodeS.empty())
	{
		while (p)
		{
			NodeS.push(p);
			p = p->pLeftChild;
		}

		p = NodeS.top();
		NodeS.pop();
		if (--vK == 0)
		{
			KthNum = p->Value;
			break;
		}
		p = p->pRightChild;
	}

	return KthNum;
}

void test(const char * vpTestName, const SBinaryTreeNode * vpRoot, int vK, int vExpect)
{
	std::cout << vpTestName << std::endl;

	try
	{
		auto KthNum = kthMinInBST(vpRoot, vK);
		if (KthNum == vExpect)
			std::cout << "PASSED.\n";
		else
			std::cout << "FAILED.\n";
	}
	catch (std::runtime_error e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl;
}
