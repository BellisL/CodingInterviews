#include "BinaryTree.h"
#include <stack>

void preOrderTraverse(const SBinaryTreeNode* vpRoot);
void inOrderTraverse(const SBinaryTreeNode* vpRoot);
void postOrderTraverse(const SBinaryTreeNode* vpRoot);
void visit(const SBinaryTreeNode* vpRoot);
void test(const char* vpTestName, const SBinaryTreeNode* vpRoot);

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

		test("Test1", pNode0);

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

		test("Test2", pNode0);

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

		test("Test3", pNode0);

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

		test("Test4", pNode0);

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

		test("Test5", pNode0);

		destroy(pNode0);
	}

	{
		auto pNode0 = new SBinaryTreeNode(1);

		test("Test4", pNode0);

		destroy(pNode0);
	}

	{
		test("Test5", nullptr);
	}

	return 0;
}

void preOrderTraverse(const SBinaryTreeNode * vpRoot)
{
	if (!vpRoot) return;

	auto pNode = vpRoot;
	std::stack<const SBinaryTreeNode*> NodeStack;
	NodeStack.push(vpRoot);

	while (!NodeStack.empty())
	{
		auto pVis = NodeStack.top();
		NodeStack.pop();
		if (pVis) visit(pVis);

		if (pVis->pRightChild)
			NodeStack.push(pVis->pRightChild);

		if (pVis->pLeftChild)
			NodeStack.push(pVis->pLeftChild);
	}
}

void inOrderTraverse(const SBinaryTreeNode * vpRoot)
{
	if (!vpRoot) return;

	auto pNode = vpRoot;
	std::stack<const SBinaryTreeNode*> NodeStack;

	while (true)
	{
		if (pNode)
		{
			NodeStack.push(pNode);
			pNode = pNode->pLeftChild;
		}
		else if (!NodeStack.empty())
		{
			auto pVis = NodeStack.top();
			NodeStack.pop();
			if (pVis) visit(pVis);
			pNode = pVis->pRightChild;
		}
		else
			break;
	}
}

//一种较为简单的非递归后序遍历是使用两个栈，其中一个栈作为过渡栈，辅助调整节点顺序
void postOrderTraverse(const SBinaryTreeNode * vpRoot)
{
	if (!vpRoot) return;

	auto pNode = vpRoot;
	std::stack<const SBinaryTreeNode*> NodeStack;
	const SBinaryTreeNode* pPreVis = nullptr;

	while (pNode || !NodeStack.empty())
	{
		if (pNode)
		{
			NodeStack.push(pNode);
			pNode = pNode->pLeftChild;
		}
		else
		{
			pNode = NodeStack.top();
			if (pNode->pRightChild && pNode->pRightChild != pPreVis)
				pNode = pNode->pRightChild;
			else
			{
				NodeStack.pop();
				visit(pNode);
				pPreVis = pNode;
				pNode = nullptr;
			}
		}
	}
}

void visit(const SBinaryTreeNode * vpRoot)
{
	if (vpRoot) std::cout << vpRoot->Value << " ";
}

void test(const char* vpTestName, const SBinaryTreeNode* vpRoot)
{
	std::cout << vpTestName;

	std::cout << "\npre order traverse: ";
	preOrderTraverse(vpRoot);

	std::cout << "\nin order traverse: ";
	inOrderTraverse(vpRoot);

	std::cout << "\npost order traverse: ";
	postOrderTraverse(vpRoot);

	std::cout << "\n\n";
}