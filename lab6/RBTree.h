#pragma once
#include "RBTreeNode.h"

class RBTree
{
private:
	RBTreeNode* _root;
	RBTreeNode* _nil;

	void LeftRotate(RBTreeNode* node);
	void RightRotate(RBTreeNode* node);
	void TreeAddFix(RBTreeNode* node);
	void TreeDeleteFix(RBTreeNode* node);
	void PrintRBTree(RBTreeNode* root, int space = 0, int count = 5);

	/// <summary>
	/// Изменить дочерний узел в родителе node на changeNode
	/// </summary>
	/// <param name="node">Узел в родителя которого нужно изменить</param>
	/// <param name="changeNode">Узел на который нужно изменить</param>
	void ChangeNodeInParent(RBTreeNode* node, RBTreeNode* changeNode);

	RBTreeNode* GetSmallestRightNode(RBTreeNode* startNode);
	void RemoveAll(RBTreeNode* node);
	RBTreeNode* GetMin(RBTreeNode* root);

public:
	RBTree();
	~RBTree();

	RBTree& AddNode(const int& key);
	bool DeleteNode(const int& key);
	RBTreeNode* Search(const int& key);
	void VisualisateRBTree();
};