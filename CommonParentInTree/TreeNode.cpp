#include "TreeNode.h"

void connectTreeNode(NodePtr vpRoot, NodePtr vpNode)
{
	if (vpRoot && vpNode)
		vpRoot->pChild.push_back(vpNode);
}
