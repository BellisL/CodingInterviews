#pragma once
#include <iostream>
#include <string>
#include "UtilitiesExport.h"

#define UNIT_LENGTH 5

struct SBinaryTreeNode
{
	SBinaryTreeNode(int vValue) : Value(vValue) {}

	int Value;
	SBinaryTreeNode* pLeftChild = nullptr;
	SBinaryTreeNode* pRightChild = nullptr;
};

void UTILITIES_DECLSPEC connectTreeNode(SBinaryTreeNode* vpFather, SBinaryTreeNode* vpLeft, SBinaryTreeNode* vpRight);

class UTILITIES_DECLSPEC CBinaryTree
{
public:
	CBinaryTree(SBinaryTreeNode* vpRoot = nullptr) : m_pRoot(vpRoot) {}
	~CBinaryTree() { __destroy(m_pRoot); }

	void setRoot(SBinaryTreeNode* vpNode) { _ASSERTE(!m_pRoot && vpNode); m_pRoot = vpNode; }
	void connect2Tree(SBinaryTreeNode* vpFather, SBinaryTreeNode* vpLeft, SBinaryTreeNode* vpRight);
	void printTree() const { __printTree(m_pRoot, 0, "H", UNIT_LENGTH); }

private:
	SBinaryTreeNode* m_pRoot = nullptr;

	void __printTree(SBinaryTreeNode* vpNode, int vHeight, std::string vStr, int vLen) const;
	std::string __getSpace(int vLen) const;
	void __destroy(SBinaryTreeNode* vpNode);
};

