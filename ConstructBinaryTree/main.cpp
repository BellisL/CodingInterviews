#include <iostream>
#include <exception>

struct SBinaryTreeNode
{
	SBinaryTreeNode(int vValue) : Value(vValue) {}

	int Value;
	SBinaryTreeNode* pLeftChild = nullptr;
	SBinaryTreeNode* pRightChild = nullptr;
};

class CTree
{
public:
	CTree() = default;
	//CTree(SBinaryTreeNode* vpNode) { _ASSERTE(!m_pRoot && vpNode); m_pRoot = vpNode; }
	~CTree() { __destroy(m_pRoot); }

	SBinaryTreeNode* getRoot() const { return m_pRoot; }
	void setRoot(SBinaryTreeNode* vpNode) { _ASSERTE(!m_pRoot && vpNode); m_pRoot = vpNode; }

	void append2Tree(SBinaryTreeNode* vpFather, SBinaryTreeNode* vpLeft, SBinaryTreeNode* vpRight);
	void printTree(const SBinaryTreeNode* vpNode) const;

private:
	SBinaryTreeNode* m_pRoot = nullptr;

	void __printTreeNode(const SBinaryTreeNode* vpNode) const;
	void __destroy(SBinaryTreeNode* vpNode);
};

void constructBinaryTree(CTree& vTree, int* vpPreOrder, int* vpInOrder, int vLength);
SBinaryTreeNode* constructBinaryTree(int* vpLeftPre, int* vpRightPre, int* vpLeftIn, int* vpRightIn);
void test(int* vpPre, int* vpIn, int vLength);

int main()
{
	{
		const int Length1 = 8;
		int PreOrder1[Length1] = { 1, 2, 4, 7, 3, 5, 6, 8 };
		int InOrder1[Length1] = { 4, 7, 2, 1, 5, 3, 8, 6 };
		test(PreOrder1, InOrder1, Length1);
	}

	{
		const int Length2 = 5;
		int PreOrder2[Length2] = { 1, 2, 3, 4, 5 };
		int InOrder2[Length2] = { 5, 4, 3, 2, 1 };
		test(PreOrder2, InOrder2, Length2);
	}

	{
		const int Length3 = 1;
		int PreOrder3[Length3] = { 1 };
		int InOrder3[Length3] = { 1 };
		test(PreOrder3, InOrder3, Length3);
	}

	{
		const int Length4 = 7;
		int PreOrder4[Length4] = { 1, 2, 4, 5, 3, 6, 7 };
		int InOrder4[Length4] = { 4, 2, 5, 1, 6, 3, 7 };
		test(PreOrder4, InOrder4, Length4);
	}

	{
		test(nullptr, nullptr, 0);
	}

	{
		const int Length4 = 7;
		int PreOrder4[Length4] = { 1, 2, 4, 5, 3, 6, 7 };
		int InOrder4[Length4] = { 4, 2, 8, 1, 6, 3, 7 };
		test(PreOrder4, InOrder4, Length4);
	}

	return 0;
}

void CTree::append2Tree(SBinaryTreeNode * vpFather, SBinaryTreeNode * vpLeft, SBinaryTreeNode * vpRight)
{
	_ASSERTE(vpFather);
	_ASSERTE(vpLeft || vpRight);

	vpFather->pLeftChild = vpLeft;
	vpFather->pRightChild = vpRight;
}

void CTree::printTree(const SBinaryTreeNode* vpNode) const
{
	if (vpNode) __printTreeNode(vpNode);

	if (vpNode->pLeftChild) printTree(vpNode->pLeftChild);
	if (vpNode->pRightChild) printTree(vpNode->pRightChild);
}

void CTree::__printTreeNode(const SBinaryTreeNode * vpNode) const
{
	if (vpNode)
	{
		std::cout << "Current Node is: " << vpNode->Value << std::endl;

		if(vpNode->pLeftChild) std::cout << "Its Left Node is: " << vpNode->pLeftChild->Value << std::endl;
		else std::cout << "Its Left Node is nullptr!" << std::endl;

		if(vpNode->pRightChild) std::cout << "Its Right Node is: " << vpNode->pRightChild->Value << std::endl;
		else std::cout << "Its Right Node is nullptr!" << std::endl;
	}
	else 
		std::cout << "Current Node is nullptr!" << std::endl;
}

void CTree::__destroy(SBinaryTreeNode* vpNode)
{
	if (!vpNode)
	{
		return;
	}
	else
	{
		SBinaryTreeNode* pLeftChild = vpNode->pLeftChild;
		SBinaryTreeNode* pRightChild = vpNode->pRightChild;

		delete vpNode;
		vpNode = nullptr;

		__destroy(pLeftChild);
		__destroy(pRightChild);
	}
}

void constructBinaryTree(CTree & vTree, int * vpPreOrder, int * vpInOrder, int vLength)
{
	auto pRoot = vTree.getRoot();
	if (pRoot)
	{
		std::cout << "The tree is not empty!" << std::endl;
		return;
	}

	if (!vpPreOrder || !vpInOrder || vLength <= 0)
	{
		std::cout << "Conditions are unable to construct a tree!" << std::endl;
		return;
	}

	pRoot = constructBinaryTree(vpPreOrder, vpPreOrder + vLength - 1, vpInOrder, vpInOrder + vLength - 1);
	vTree.setRoot(pRoot);
}

SBinaryTreeNode * constructBinaryTree(int * vpLeftPre, int * vpRightPre, int * vpLeftIn, int * vpRightIn)
{
	SBinaryTreeNode* pNode = new SBinaryTreeNode(vpLeftPre[0]);

	if (vpLeftPre == vpRightPre)
	{
		if (vpLeftIn == vpRightIn && *vpLeftPre == *vpLeftIn)
			return pNode;
		else
			std::runtime_error("Invalid input!");
	}

	int* RootInOrder = vpLeftIn;
	while (RootInOrder != vpRightIn && *RootInOrder != vpLeftPre[0])
		++RootInOrder;
	
	int Left = RootInOrder - vpLeftIn;
	int* pLeftPreEnd = vpLeftPre + Left;

	if (Left > 0)
	{
		pNode->pLeftChild = constructBinaryTree(vpLeftPre + 1, pLeftPreEnd, vpLeftIn, RootInOrder - 1);
	}

	if (Left < vpRightPre - vpLeftPre)
	{
		pNode->pRightChild = constructBinaryTree(pLeftPreEnd + 1, vpRightPre, RootInOrder + 1, vpRightIn);
	}

	return pNode;
}

void test(int * vpPre, int * vpIn, int vLength)
{
	CTree Tree;
	try
	{
		constructBinaryTree(Tree, vpPre, vpIn, vLength);
		Tree.printTree(Tree.getRoot());
	}
	catch (std::runtime_error& Error)
	{
		std::cout << Error.what() << std::endl;
	}

	std::cout << std::endl;
}
