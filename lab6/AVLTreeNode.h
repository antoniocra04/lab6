#pragma once

struct AVLTreeNode
{
	int _key;
	int _height;
	
	AVLTreeNode* _left;
	AVLTreeNode* _right;

	AVLTreeNode(const int& key, const int& height, AVLTreeNode* left, AVLTreeNode* right);
};