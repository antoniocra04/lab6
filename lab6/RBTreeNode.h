#pragma once

enum class Color
{
	Red,
	Black,
};

struct RBTreeNode
{
	RBTreeNode* _left;
	RBTreeNode* _right;
	RBTreeNode* _parent;

	Color _color;
	int _key;

	RBTreeNode(const int& key, enum Color color, RBTreeNode* parent, RBTreeNode* right, RBTreeNode* left);
};