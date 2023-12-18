#include "RBTreeNode.h"

RBTreeNode::RBTreeNode(const int& key, enum Color color, RBTreeNode* parent, RBTreeNode* right, RBTreeNode* left)
{
	_key = key;
	_color = color;
	_left = left;
	_right = right;
	_parent = parent;
}