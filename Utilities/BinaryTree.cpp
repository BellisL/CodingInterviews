#include "BinaryTree.h"

void CBinaryTree::connect2Tree(SBinaryTreeNode * vpFather, SBinaryTreeNode * vpLeft, SBinaryTreeNode * vpRight)
{
	_ASSERTE(vpFather);
	_ASSERTE(vpLeft || vpRight);

	vpFather->pLeftChild = vpLeft;
	vpFather->pRightChild = vpRight;
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

void connectTreeNode(SBinaryTreeNode * vpFather, SBinaryTreeNode * vpLeft, SBinaryTreeNode * vpRight)
{
	_ASSERTE(vpFather);

	vpFather->pLeftChild = vpLeft;
	vpFather->pRightChild = vpRight;
}
