#include "AVLTree.h"
#include "AVLTreeNode.h"
#include <iostream>
using namespace std;

AVLTree::AVLTree()
{
	_root = nullptr;
}

int AVLTree::GetBalanceFactor(AVLTreeNode* node)
{
	return GetHeight(node->_right) - GetHeight(node->_left);
}

int AVLTree::GetHeight(AVLTreeNode* node)
{
	if (node == nullptr)
	{
		return 0;
	}
	else
	{
		return node->_height;
	}
}

void AVLTree::FixHeight(AVLTreeNode* node)
{
	if (GetHeight(node->_left) > GetHeight(node->_right))
	{
		node->_height = GetHeight(node->_left) + 1;
	}
	else
	{
		node->_height = GetHeight(node->_right) + 1;
	}
}

AVLTreeNode* AVLTree::RightRotate(AVLTreeNode* node)
{
	AVLTreeNode* current = node->_left;

	node->_left = current->_right;
	current->_right = node;

	FixHeight(node);
	FixHeight(current);
	return current;

}

AVLTreeNode* AVLTree::LeftRotate(AVLTreeNode* node)
{
	AVLTreeNode* current = node->_right;

	node->_right = current->_left;
	current->_left = node;

	FixHeight(node);
	FixHeight(current);
	return current;
}

AVLTreeNode* AVLTree::Balance(AVLTreeNode* node)
{
	FixHeight(node);
	if (GetBalanceFactor(node) == 2)
	{
		if (GetBalanceFactor(node->_right) < 0)
		{
			node->_right = RightRotate(node->_right);
		}
		return LeftRotate(node);
	}

	if (GetBalanceFactor(node) == -2)
	{
		if (GetBalanceFactor(node->_left) > 0)
		{
			node->_left = LeftRotate(node->_left);
		}
		return RightRotate(node);
	}

	return node;
}

AVLTreeNode* AVLTree::Insert(AVLTreeNode* root, const int& key)
{
	if (!root)
	{
		root = new AVLTreeNode(key, 1, nullptr, nullptr);
		return root;
	}

	if (key < root->_key)
	{
		root->_left = Insert(root->_left, key);
	}
	else
	{
		root->_right = Insert(root->_right, key);
	}

	return Balance(root);
}

AVLTree& AVLTree::AddNode(const int& key)
{
	_root = Insert(_root, key);
	return *this;
}

AVLTreeNode* AVLTree::Search(const int& key)
{
	AVLTreeNode* current = _root;

	if (current->_key == key)
	{
		return _root;
	}

	while (true)
	{
		if (current->_key == key)
		{
			return current;
		}

		if (key >= current->_key)
		{

			if (current->_right == nullptr)
			{
				return nullptr;
			}
			else
			{
				current = current->_right;
			}

		}
		else
		{
			if (current->_left == nullptr)
			{
				return nullptr;
			}
			else
			{
				current = current->_left;
			}
		}
	}
}

AVLTreeNode* AVLTree::GetMin(AVLTreeNode* root)
{
	if (root == nullptr)
	{
		return NULL;
	}

	AVLTreeNode* current = root;

	while (current->_left != nullptr)
	{
		current = current->_left;
	}

	return current;
}

AVLTreeNode* AVLTree::BalanceMin(AVLTreeNode* root)
{
	if (root->_left == nullptr)
	{
		return root->_right;
	}

	root->_left = BalanceMin(root->_left);

	return Balance(root);
}

AVLTreeNode* AVLTree::Remove(AVLTreeNode* root, const int& key)
{
	if (!root)
	{
		return nullptr;
	}

	if (key < root->_key)
	{
		root->_left = Remove(root->_left, key);
	}
	else if (key > root->_key)
	{
		root->_right = Remove(root->_right, key);
	}
	else
	{
		AVLTreeNode* left = root->_left;
		AVLTreeNode* right = root->_right;

		delete root;

		if (!right)
		{
			return left;
		}

		AVLTreeNode* minimal = GetMin(right);
		minimal->_right = BalanceMin(right);
		minimal->_left = left;

		return Balance(minimal);
	}

	return Balance(root);
}

bool AVLTree::DeleteNode(const int& key)
{
	if (Search(key))
	{
		_root = Remove(_root, key);
		return true;
	}
	else
	{
		return false;
	}

}

const AVLTreeNode* AVLTree::GetRoot()
{
	return _root;
}

void AVLTree::RemoveAll(AVLTreeNode* node)
{
	if (!node) return;

	RemoveAll(node->_left);
	RemoveAll(node->_right);

	delete node;
	node = nullptr;
}

AVLTree::~AVLTree()
{
	RemoveAll(_root);
}