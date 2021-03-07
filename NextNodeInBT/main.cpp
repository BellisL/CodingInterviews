#include <iostream>
#include <string>

#define UNIT_LENGTH 5

struct SBinaryTreeNode
{
	SBinaryTreeNode(int vValue) : Value(vValue) {}

	int Value;
	SBinaryTreeNode* pLeftChild = nullptr;
	SBinaryTreeNode* pRightChild = nullptr;
	SBinaryTreeNode* pParent = nullptr;
};

class CBinaryTree
{
public:
	CBinaryTree(SBinaryTreeNode* vpNode = nullptr) : m_pRoot(vpNode) {};
	~CBinaryTree() { __destroy(m_pRoot); }

	void setRoot(SBinaryTreeNode* vpNode) { _ASSERTE(!m_pRoot && vpNode); m_pRoot = vpNode; }
	void connect2Tree(SBinaryTreeNode* vpFather, SBinaryTreeNode* vpLeft, SBinaryTreeNode* vpRight);
	void printTree() const { __printTree(m_pRoot, 0, "H", UNIT_LENGTH); std::cout << "\n"; }

	SBinaryTreeNode* getNextInInOrder(SBinaryTreeNode* vpNode) const;

private:
	SBinaryTreeNode* m_pRoot = nullptr;

	void __printTree(SBinaryTreeNode* vpNode, int vHeight, std::string vStr, int vLen) const;
	std::string __getSpace(int vLen) const;
	void __destroy(SBinaryTreeNode* vpNode);
};

void test(CBinaryTree& vTree, SBinaryTreeNode* vpNode, SBinaryTreeNode* vpExpect);

int main()
{
	//结点都没释放，应该有内存泄漏= =
	{
		std::cout << "-------------------test-------------------\n";

		auto pNode8 = new SBinaryTreeNode(8);
		auto pNode6 = new SBinaryTreeNode(6);
		auto pNode10 = new SBinaryTreeNode(10);
		auto pNode5 = new SBinaryTreeNode(5);
		auto pNode7 = new SBinaryTreeNode(7);
		auto pNode9 = new SBinaryTreeNode(9);
		auto pNode11 = new SBinaryTreeNode(11);

		CBinaryTree Tree(pNode8);
		Tree.connect2Tree(pNode8, pNode6, pNode10);
		Tree.connect2Tree(pNode6, pNode5, pNode7);
		Tree.connect2Tree(pNode10, pNode9, pNode11);

		Tree.printTree();

		test(Tree, pNode8, pNode9);
		test(Tree, pNode6, pNode7);
		test(Tree, pNode10, pNode11);
		test(Tree, pNode5, pNode6);
		test(Tree, pNode7, pNode8);
		test(Tree, pNode9, pNode10);
		test(Tree, pNode11, nullptr);
	}

	{
		std::cout << "\n-------------------test-------------------\n";

		auto pNode5 = new SBinaryTreeNode(5);
		auto pNode4 = new SBinaryTreeNode(4);
		auto pNode3 = new SBinaryTreeNode(3);
		auto pNode2 = new SBinaryTreeNode(2);

		CBinaryTree Tree(pNode5);
		Tree.connect2Tree(pNode5, pNode4, nullptr);
		Tree.connect2Tree(pNode4, pNode3, nullptr);
		Tree.connect2Tree(pNode3, pNode2, nullptr);

		Tree.printTree();

		test(Tree, pNode5, nullptr);
		test(Tree, pNode4, pNode5);
		test(Tree, pNode3, pNode4);
		test(Tree, pNode2, pNode3);
	}

	{
		std::cout << "\n-------------------test-------------------\n";

		auto pNode2 = new SBinaryTreeNode(2);
		auto pNode3 = new SBinaryTreeNode(3);
		auto pNode4 = new SBinaryTreeNode(4);
		auto pNode5 = new SBinaryTreeNode(5);

		CBinaryTree Tree(pNode2);
		Tree.connect2Tree(pNode2, nullptr, pNode3);
		Tree.connect2Tree(pNode3, nullptr, pNode4);
		Tree.connect2Tree(pNode4, nullptr, pNode5);

		Tree.printTree();

		test(Tree, pNode5, nullptr);
		test(Tree, pNode4, pNode5);
		test(Tree, pNode3, pNode4);
		test(Tree, pNode2, pNode3);
	}

	return 0;
}

void CBinaryTree::connect2Tree(SBinaryTreeNode * vpFather, SBinaryTreeNode * vpLeft, SBinaryTreeNode * vpRight)
{
	_ASSERTE(vpFather);

	vpFather->pLeftChild = vpLeft;
	vpFather->pRightChild = vpRight;

	if (vpLeft) vpLeft->pParent = vpFather;
	if (vpRight) vpRight->pParent = vpFather;
}

SBinaryTreeNode * CBinaryTree::getNextInInOrder(SBinaryTreeNode * vpNode) const
{
	if (!vpNode) return nullptr;

	SBinaryTreeNode* pNext = nullptr;
	if (vpNode->pRightChild)
	{
		SBinaryTreeNode* pRight = vpNode->pRightChild;
		while (pRight->pLeftChild) pRight = pRight->pLeftChild;
		pNext = pRight;
	}
	else if (vpNode->pParent)
	{
		SBinaryTreeNode* pParent = vpNode->pParent;
		if (pParent->pLeftChild == vpNode)
			pNext = pParent;
		else
		{
			SBinaryTreeNode* pCur = vpNode;
			while (pParent && pParent->pLeftChild != pCur)
			{
				pCur = pParent;
				pParent = pParent->pParent;
			}
			pNext = pParent;
		}
	}

	return pNext;
}

void CBinaryTree::__printTree(SBinaryTreeNode * vpNode, int vHeight, std::string vStr, int vLen) const
{
	if (!vpNode) return;
	__printTree(vpNode->pRightChild, vHeight + 1, "v", vLen);

	std::string Literal = vStr + std::to_string(vpNode->Value) + vStr;
	int LLen = (vLen - Literal.size()) / 2;
	int RLen = vLen - Literal.size() - LLen;
	std::cout << __getSpace(vHeight * vLen + LLen) << Literal << __getSpace(RLen) << std::endl;

	__printTree(vpNode->pLeftChild, vHeight + 1, "^", vLen);
}

std::string CBinaryTree::__getSpace(int vLen) const
{
	std::string Str = "";
	for (int i = 0; i < vLen; ++i)
		Str.append(" ");

	return Str;
}

void CBinaryTree::__destroy(SBinaryTreeNode* vpNode)
{
	if (vpNode)
	{
		SBinaryTreeNode* pLeftChild = vpNode->pLeftChild;
		SBinaryTreeNode* pRightChild = vpNode->pRightChild;

		delete vpNode;
		vpNode = nullptr;

		__destroy(pLeftChild);
		__destroy(pRightChild);
	}
}

void test(CBinaryTree & vTree, SBinaryTreeNode * vpNode, SBinaryTreeNode * vpExpect)
{
	if (vpNode) std::cout << "Current node is: " << vpNode->Value << std::endl;
	if (vpExpect) 
		std::cout << "Expected next node is: " << vpExpect->Value << std::endl;
	else
		std::cout << "Expected next node is nullptr!" << std::endl;

	SBinaryTreeNode* pNext = vTree.getNextInInOrder(vpNode);
	if (pNext && pNext == vpExpect)
		std::cout << "Searched next node is: " << pNext->Value << std::endl;
	else if (pNext == vpExpect)
		std::cout << "Searched next node is nullptr!" << std::endl;
	else
		std::cout << "Next node not found!" << std::endl;

	std::cout << std::endl;
}
