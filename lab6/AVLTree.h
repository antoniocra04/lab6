#pragma once
#include "AVLTreeNode.h"

class AVLTree
{
private:
	AVLTreeNode* _root;

	int GetBalanceFactor(AVLTreeNode* node);
	int GetHeight(AVLTreeNode* node);
	void FixHeight(AVLTreeNode* node);
	AVLTreeNode* GetMin(AVLTreeNode* root);
	AVLTreeNode* BalanceMin(AVLTreeNode* root);
	AVLTreeNode* LeftRotate(AVLTreeNode* node);
	AVLTreeNode* RightRotate(AVLTreeNode* node);
	AVLTreeNode* Insert(AVLTreeNode* root, const int& key);
	AVLTreeNode* Balance(AVLTreeNode* node);
	void PrintAVLTree(AVLTreeNode* root, int space = 0, int count = 5);
	AVLTreeNode* Remove(AVLTreeNode* root, const int& key);
	void RemoveAll(AVLTreeNode* node);

public:
	AVLTree();
	~AVLTree();

	AVLTree& AddNode(const int& key);
	bool DeleteNode(const int& key);
	AVLTreeNode* Search(const int& key);
	void VisualisateAVLTree();
};