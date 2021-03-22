#include <iostream>
#include <list>
#include "TreeNode.h"

typedef std::list<NodePtr> NodeList;

NodePtr getCommonParent(NodePtr vpRoot, NodePtr vpNode1, NodePtr vpNode2);
NodePtr getCommonNode(const NodeList& vList1, const NodeList& vList2);
void getNodePath(NodePtr vpRoot, NodePtr vpNode, NodeList& vList, bool& vFound);
void test(const char* vpTestName, NodePtr vpRoot, NodePtr vpNode1, NodePtr vpNode2, NodePtr vpExpect);

int main()
{
	{
		auto pNode1 = std::make_shared<STreeNode>(1);
		auto pNode2 = std::make_shared<STreeNode>(2);
		auto pNode3 = std::make_shared<STreeNode>(3);
		auto pNode4 = std::make_shared<STreeNode>(4);
		auto pNode5 = std::make_shared<STreeNode>(5);
		auto pNode6 = std::make_shared<STreeNode>(6);
		auto pNode7 = std::make_shared<STreeNode>(7);
		auto pNode8 = std::make_shared<STreeNode>(8);
		auto pNode9 = std::make_shared<STreeNode>(9);
		auto pNode10 = std::make_shared<STreeNode>(10);

		connectTreeNode(pNode1, pNode2);
		connectTreeNode(pNode1, pNode3);

		connectTreeNode(pNode2, pNode4);
		connectTreeNode(pNode2, pNode5);

		connectTreeNode(pNode4, pNode6);
		connectTreeNode(pNode4, pNode7);

		connectTreeNode(pNode5, pNode8);
		connectTreeNode(pNode5, pNode9);
		connectTreeNode(pNode5, pNode10);

		// 形状普通的树
		//              1
		//            /   \
		//           2     3
		//       /       \
		//      4         5
		//     / \      / |  \
		//    6   7    8  9  10

		test("Test1", pNode1, pNode6, pNode8, pNode2);
	}

	{
		auto pNode1 = std::make_shared<STreeNode>(1);
		auto pNode2 = std::make_shared<STreeNode>(2);
		auto pNode3 = std::make_shared<STreeNode>(3);
		auto pNode4 = std::make_shared<STreeNode>(4);
		auto pNode5 = std::make_shared<STreeNode>(5);

		connectTreeNode(pNode1, pNode2);
		connectTreeNode(pNode2, pNode3);
		connectTreeNode(pNode3, pNode4);
		connectTreeNode(pNode4, pNode5);

		// 树退化成一个链表
		//               1
		//              /
		//             2
		//            /
		//           3
		//          /
		//         4
		//        /
		//       5

		test("Test2", pNode1, pNode5, pNode4, pNode3);
	}

	{
		auto pNode1 = std::make_shared<STreeNode>(1);
		auto pNode2 = std::make_shared<STreeNode>(2);
		auto pNode3 = std::make_shared<STreeNode>(3);
		auto pNode4 = std::make_shared<STreeNode>(4);
		auto pNode5 = std::make_shared<STreeNode>(5);
		auto pNode6 = std::make_shared<STreeNode>(6);

		connectTreeNode(pNode1, pNode2);
		connectTreeNode(pNode2, pNode3);
		connectTreeNode(pNode3, pNode4);
		connectTreeNode(pNode4, pNode5);

		// 树退化成一个链表，一个结点不在树中
		//               1
		//              /
		//             2
		//            /
		//           3
		//          /
		//         4
		//        /
		//       5

		test("Test3", pNode1, pNode5, pNode6, nullptr);
	}

	test("Test4", nullptr, nullptr, nullptr, nullptr);

	return 0;
}

NodePtr getCommonParent(NodePtr vpRoot, NodePtr vpNode1, NodePtr vpNode2)
{
	if (!vpRoot || !vpNode1 || !vpNode2) return nullptr;

	NodeList NodePath1;
	bool FoundPath1 = false;
	getNodePath(vpRoot, vpNode1, NodePath1, FoundPath1);

	NodeList NodePath2;
	bool FoundPath2 = false;
	getNodePath(vpRoot, vpNode2, NodePath2, FoundPath2);

	return getCommonNode(NodePath1, NodePath2);
}

NodePtr getCommonNode(const NodeList & vList1, const NodeList & vList2)
{
	auto Iter1 = vList1.cbegin();
	auto Iter2 = vList2.cbegin();

	NodePtr CommonNode = nullptr;

	while (Iter1 != vList1.cend() && Iter2 != vList2.cend())
	{
		if (*Iter1 == *Iter2)
			CommonNode = *Iter1;

		++Iter1;
		++Iter2;
	}

	return CommonNode;
}

void getNodePath(NodePtr vpRoot, NodePtr vpNode, NodeList & vList, bool & vFound)
{
	if (vpRoot == vpNode)
	{
		vFound = true;
		return;
	}
	else
	{
		for (const auto pChild : vpRoot->pChild)
		{
			if (!vFound)
			{
				vList.push_back(vpRoot);
				getNodePath(pChild, vpNode, vList, vFound);
				if (!vFound)
					vList.pop_back();
			}
		}
	}
}

void test(const char * vpTestName, NodePtr vpRoot, NodePtr vpNode1, NodePtr vpNode2, NodePtr vpExpect)
{
	std::cout << vpTestName << std::endl;

	auto pCommon = getCommonParent(vpRoot, vpNode1, vpNode2);
	if (pCommon == vpExpect)
		std::cout << "PASSED.\n";
	else
		std::cout << "FAILED.\n";

	std::cout << std::endl;
}
