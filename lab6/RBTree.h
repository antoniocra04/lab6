#pragma once
#include "RBTreeNode.h"

class RBTree
{
private:
	RBTreeNode* _root;
	RBTreeNode* _nil;

	void LeftRotate(RBTreeNode* node);
	void RightRotate(RBTreeNode* node);
	RBTreeNode* FindInsertionPoint(const int& value);
	void TreeAddFix(RBTreeNode* node);
	void TreeDeleteFix(RBTreeNode* node);
	void PrintRBTree(RBTreeNode* root, int space = 0, int count = 5);
	void ChangeNodeInParent(RBTreeNode* node, RBTreeNode* changeNode);
	RBTreeNode* GetSmallestRightNode(RBTreeNode* startNode);
	void RemoveAll(RBTreeNode* node);
	RBTreeNode* GetMin(RBTreeNode* root);
	RBTreeNode* Insert(RBTreeNode* root, RBTreeNode* node);
	RBTreeNode* Remove(RBTreeNode* root, const int& key);
	void DeleteCase1(RBTreeNode* node);
	void DeleteCase2(RBTreeNode* node);
	bool DeleteCase3(RBTreeNode* sibling, RBTreeNode* parent, RBTreeNode* pointer);
	bool DeleteCase4(RBTreeNode* sibling, RBTreeNode* parent, RBTreeNode* pointer);

public:
	RBTree();
	~RBTree();

	RBTree& AddNode(const int& key);
	bool DeleteNode(const int& key);
	RBTreeNode* Search(const int& key);
	void VisualisateRBTree();
};