#include "AVLTreeNode.h"

AVLTreeNode::AVLTreeNode(const int& key, const int& height, AVLTreeNode* left, AVLTreeNode* right)
{
	_key = key;
	_height = height;
	_left = left;
	_right = right;
}