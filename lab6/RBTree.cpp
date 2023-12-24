#include <iostream>
#include "RBTree.h"
#include "RBTreeNode.h"
using namespace std;

void RBTree::ChangeNodeInParent(RBTreeNode* node, RBTreeNode* changeNode)
{
	RBTreeNode* parent = node->_parent;

	if (node->_parent == _nil)
	{
		_root = changeNode;
	}
	else
	{
		if (node == node->_parent->_left)
		{
			node->_parent->_left = changeNode;
		}
		else
		{
			node->_parent->_right = changeNode;
		}
	}
	changeNode->_parent = node->_parent;
}

RBTreeNode* RBTree::GetSmallestRightNode(RBTreeNode* startNode)
{
	if (startNode->_right == _nil)
	{
		return _root;
	}

	RBTreeNode* current = startNode->_right;

	while (true)
	{
		if (current->_left == _nil)
		{
			return current;
		}

		current = current->_left;
	}
}

RBTree::RBTree()
{
	_root = nullptr;
	_nil = new RBTreeNode(NULL, Color::Black, nullptr, nullptr, nullptr);
}

void RBTree::LeftRotate(RBTreeNode* node)
{
	RBTreeNode* rightChild = node->_right;
	node->_right = rightChild->_left;

	if (node->_right != _nil)
	{
		node->_right->_parent = node;
	}

	rightChild->_parent = node->_parent;

	if (node->_parent == _nil)
	{
		_root = rightChild;
	}
	else if (node == node->_parent->_left)
	{
		node->_parent->_left = rightChild;
	}
	else
	{
		node->_parent->_right = rightChild;
	}

	rightChild->_left = node;
	node->_parent = rightChild;
}

void RBTree::RightRotate(RBTreeNode* node)
{
	RBTreeNode* leftChild = node->_left;
	node->_left = leftChild->_right;

	if (node->_left != _nil)
	{
		node->_left->_parent = node;
	}

	leftChild->_parent = node->_parent;

	if (node->_parent == _nil)
	{
		_root = leftChild;
	}
	else if (node == node->_parent->_left)
	{
		node->_parent->_left = leftChild;
	}
	else
	{
		node->_parent->_right = leftChild;
	}

	leftChild->_right = node;
	node->_parent = leftChild;
}

void RBTree::TreeAddFix(RBTreeNode* newNode)
{
	if (newNode == _root)
	{
		newNode->_color = Color::Black;
		return;
	}

	while (newNode->_parent->_color == Color::Red)
	{
		RBTreeNode* parent = newNode->_parent;
		RBTreeNode* grandparent = parent->_parent;
		if (grandparent != _nil)
		{
			if (newNode->_parent == grandparent->_left)
			{
				RBTreeNode* uncle = grandparent->_right;
				if (uncle != _nil && uncle->_color == Color::Red)
				{
					parent->_color = Color::Black;
					uncle->_color = Color::Black;
					grandparent->_color = Color::Red;
					newNode = grandparent;
				}
				else
				{
					if (newNode == parent->_right)
					{
						newNode = parent;
						LeftRotate(newNode);
						parent = newNode->_parent;
						grandparent = parent->_parent;
					}
					parent->_color = Color::Black;
					grandparent->_color = Color::Red;
					RightRotate(grandparent);
				}
			}
			else
			{
				RBTreeNode* uncle = grandparent->_left;
				if (uncle != _nil && uncle->_color == Color::Red)
				{
					parent->_color = Color::Black;
					uncle->_color = Color::Black;
					grandparent->_color = Color::Red;
					newNode = grandparent;
				}
				else
				{
					if (newNode == parent->_left)
					{
						newNode = parent;
						RightRotate(newNode);
						parent = newNode->_parent;
						grandparent = parent->_parent;
					}
					parent->_color = Color::Black;
					grandparent->_color = Color::Red;
					LeftRotate(grandparent);
				}
			}
		}
	}

	_root->_color = Color::Black;
}

RBTree& RBTree::AddNode(const int& key)
{
	RBTreeNode* newNode = new RBTreeNode(key, Color::Red, nullptr,  _nil, _nil);
	if (_root == nullptr)
	{
		_root = newNode;
		newNode->_parent = _nil;
	}
	else
	{
		RBTreeNode* root = _root;
		RBTreeNode* parent = _nil;
		while (root != _nil)
		{
			parent = root;
			if (newNode->_key > root->_key)
			{
				root = root->_right;
			}
			else
			{
				root = root->_left;
			}
		}
		newNode->_parent = parent;

		if (newNode->_key > parent->_key)
		{
			parent->_right = newNode;
		}
		else
		{
			parent->_left = newNode;
		}
	}
	TreeAddFix(newNode);
	return *this;
}

RBTreeNode* RBTree::Search(const int& key)
{
	RBTreeNode* current = _root;

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

			if (current->_right == _nil)
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
			if (current->_left == _nil)
			{
				return current;
			}
			else
			{
				current = current->_left;
			}
		}
	}
}


RBTreeNode* RBTree::GetMin(RBTreeNode* root)
{
	if (root == _nil)
	{
		return NULL;
	}

	RBTreeNode* current = root;

	while (current->_left != _nil)
	{
		current = current->_left;
	}

	return current;
}



bool RBTree::DeleteNode(const int& key)
{
	RBTreeNode* deleteNode = Search(key);
	bool lastRoot = false;
	if (deleteNode == nullptr)
	{
		return false;
	}
	if (deleteNode == _root 
		&& deleteNode->_left == _nil 
		&& deleteNode->_right == _nil)
	{
		lastRoot = true;
	}

	RBTreeNode* fixNode;
	Color fixColor = deleteNode->_color;

	if (deleteNode->_left == _nil)
	{
		fixNode = deleteNode->_right;
		ChangeNodeInParent(deleteNode, deleteNode->_right);
	}
	else
	{
		if (deleteNode->_right == _nil)
		{
			fixNode = deleteNode->_left;
			ChangeNodeInParent(deleteNode, deleteNode->_left);
		}
		else
		{
			RBTreeNode* changedNode = GetMin(deleteNode->_right);
			fixColor = changedNode->_color;
			fixNode = changedNode->_left;
			if (deleteNode == changedNode->_parent)
			{
				fixNode->_parent = changedNode;
			}
			else
			{
				ChangeNodeInParent(changedNode, changedNode->_right);
				changedNode->_right = deleteNode->_right;
				changedNode->_right->_parent = changedNode;
			}
			ChangeNodeInParent(deleteNode, changedNode);
			changedNode->_left = deleteNode->_left;
			changedNode->_left->_parent = changedNode;
			changedNode->_color = deleteNode->_color;
		}
	}

	delete deleteNode;

	if (fixColor == Color::Black)
	{
		TreeDeleteFix(fixNode);
	}

	if (lastRoot)
	{
		_root = nullptr;
	}

	return true;
}

void RBTree::TreeDeleteFix(RBTreeNode* node)
{
	while (node != _root && node->_color == Color::Black)
	{
		RBTreeNode* parent = node->_parent;
		if (node == parent->_left)
		{
			RBTreeNode* brother = parent->_right;
			if (brother != _nil && brother->_color == Color::Red)
			{
				brother->_color = Color::Black;
				parent->_color = Color::Red;
				LeftRotate(parent);
				brother = parent->_right;
			}
			if (brother->_left->_color == Color::Black 
				&& brother->_right->_color == Color::Black)
			{
				brother->_color = Color::Red;
				node = node->_parent;
			}
			else
			{
				if (brother->_right->_color == Color::Black)
				{
					brother->_left->_color = Color::Black;
					brother->_color = Color::Red;
					RightRotate(brother);
					brother = parent->_right;
				}
				brother->_color = parent->_color;
				parent->_color = Color::Black;
				brother->_right->_color = Color::Black;
				LeftRotate(parent);
				node = _root;
			}
		}
		else
		{
			RBTreeNode* brother = parent->_left;
			if (brother->_color == Color::Red)
			{
				brother->_color = Color::Black;
				parent->_color = Color::Red;
				RightRotate(parent);
				brother = parent->_left;
			}
			if (brother->_left->_color == Color::Black 
				&& brother->_right->_color == Color::Black)
			{
				brother->_color = Color::Red;
				node = node->_parent;
			}
			else
			{
				if (brother->_left->_color == Color::Black)
				{
					brother->_right->_color = Color::Black;
					brother->_color = Color::Red;
					LeftRotate(brother);
					brother = parent->_left;
				}
				brother->_color = parent->_color;
				parent->_color = Color::Black;
				brother->_left->_color = Color::Black;
				RightRotate(parent);
				node = _root;
			}
		}
	}
	node->_color = Color::Black;
}

const RBTreeNode* RBTree::GetRoot()
{
	return _root;
}

const RBTreeNode* RBTree::GetNil()
{
	return _nil;
}

void RBTree::RemoveAll(RBTreeNode* node)
{
	if (node == _nil || node == nullptr) return;

	RemoveAll(node->_left);
	RemoveAll(node->_right);

	delete node;
}

RBTree::~RBTree()
{
	RemoveAll(_root);
	delete _nil;
}