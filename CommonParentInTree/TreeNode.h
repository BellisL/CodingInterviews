#pragma once
#include <vector>
#include <memory>

struct STreeNode
{
	STreeNode(int vVal) : Val(vVal) {}

	int Val;
	std::vector<std::shared_ptr<STreeNode>> pChild;
};

typedef std::shared_ptr<STreeNode> NodePtr;

void connectTreeNode(NodePtr vpRoot, NodePtr vpNode);