#include <iostream>
#include "RBTree.h"
#include "RBTreeNode.h"
#include <windows.h>
using namespace std;

void RBTree::ChangeNodeInParent(RBTreeNode* node, RBTreeNode* changeNode)
{
	RBTreeNode* parent = node->_parent;

	if (node->_parent == _nil)
	{
		_root = changeNode;
	}
	else if (parent->_left->_key == node->_key)
	{
		parent->_left = changeNode;
	}
	else
	{
		parent->_right = changeNode;
	}
	parent = changeNode->_parent;
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

RBTreeNode* RBTree::FindInsertionPoint(const int& value)
{
	RBTreeNode* current = _root;

	while (true)
	{
		if (value >= current->_key)
		{
			if (current->_right == _nil)
			{
				return current;
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
	RBTreeNode* parent = nullptr;
	RBTreeNode* grandParent = nullptr;
	while (newNode != _root && newNode->_color == Color::Red && newNode->_parent->_color == Color::Red)
	{
		parent = newNode->_parent;
		grandParent = parent->_parent;
		if (parent == grandParent->_left)
		{
			RBTreeNode* uncle = grandParent->_right;
			if (uncle->_color == Color::Red)
			{
				uncle->_color = Color::Black;
				parent->_color = Color::Black;
				grandParent->_color = Color::Red;
				newNode = grandParent;
			}
			else
			{
				if (newNode == parent->_right)
				{
					LeftRotate(parent);
					newNode = parent;
					parent = newNode->_parent;
				}
				RightRotate(grandParent);
				const Color color = grandParent->_color;
				grandParent->_color = parent->_color;
				parent->_color = color;
				newNode = parent;
			}
		}
		else
		{
			RBTreeNode* uncle = grandParent->_left;
			if (uncle->_color == Color::Red)
			{
				uncle->_color = Color::Black;
				parent->_color = Color::Black;
				grandParent->_color = Color::Red;
				newNode = grandParent;
			}
			else
			{
				if (newNode == parent->_left)
				{
					RightRotate(parent);
					newNode = parent;
					parent = newNode->_parent;
				}
				LeftRotate(grandParent);
				const Color color = grandParent->_color;
				grandParent->_color = parent->_color;
				parent->_color = color;
				newNode = parent;
			}
		}
	}
	_root->_color = Color::Black;
}

RBTreeNode* RBTree::Insert(RBTreeNode* root, RBTreeNode* node)
{
	if (root == nullptr || root == _nil)
	{
		return node;
	}

	if (node->_key < root->_key)
	{
		root->_left = Insert(root->_left, node);
		root->_left->_parent = root;
	}
	else
	{
		root->_right = Insert(root->_right, node);
		root->_right->_parent = root;
	}

	return root;
}

RBTree& RBTree::AddNode(const int& key)
{
	RBTreeNode* newNode = new RBTreeNode(key, Color::Red, nullptr, _nil, _nil);

	if (_root == nullptr)
	{
		newNode->_parent = _nil;
	}

	_root = Insert(_root, newNode);
	TreeAddFix(newNode);
	return *this;
}

void RBTree::PrintRBTree(RBTreeNode* root, int space, int count)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (root == nullptr) {
		return;
	}

	space += count;
	PrintRBTree(root->_right, space, count);

	cout << endl;

	for (int i = count; i < space; i++) {
		cout << " ";
	}

	if (root->_color == Color::Black)
	{
		cout << root->_key << "\n";
	}
	else
	{
		cout << "\x1B[31m" << root->_key << "\033[0m\t\t" << "\n";
	}

	PrintRBTree(root->_left, space, count);
}

void RBTree::VisualisateRBTree()
{
	PrintRBTree(_root);
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

void RBTree::DeleteCase1(RBTreeNode* node)
{

	if (node->_left == _nil && node->_right == _nil)
	{
		delete _root;
		_root = nullptr;
		return;
	}
	RBTreeNode* current = _root;

	if (_root->_left != _nil)
	{
		_root = _root->_left;
	}
	else
	{
		_root = _root->_right;
	}

	_root->_color = Color::Black;
	_root->_parent = _nil;
	delete current;
}

void RBTree::DeleteCase2(RBTreeNode* node)
{
	RBTreeNode* child;

	if(node->_left != _nil)
	{
		child = node->_left;
	}
	else
	{
		child = node->_right;
	}


	if (node == node->_parent->_left)
	{
		node->_parent->_left = child;
		if (child != _nil)
		{
			child->_parent = node->_parent;
		}
		child->_color = Color::Black;
		delete node;
	}
	else if (node == node->_parent->_right)
	{
		node->_parent->_right = child;
		if (child != _nil)
		{
			child->_parent = node->_parent;
		}
		child->_color = Color::Black;
		delete node;
	}
}

bool RBTree::DeleteCase3(RBTreeNode* sibling, RBTreeNode* parent, RBTreeNode* pointer)
{
	sibling = parent->_right;
	if (sibling->_color == Color::Red)
	{
		sibling->_color = Color::Black;
		parent->_color = Color::Red;
		LeftRotate(parent);
	}
	else if (sibling->_color != Color::Red)
	{
		if (sibling->_left->_color == Color::Black &&
			sibling->_right->_color == Color::Black)
		{
			sibling->_color = Color::Red;
			if (parent->_color == Color::Red)
			{
				parent->_color = Color::Black;
			}
			else if (parent->_color != Color::Red)
			{
				parent->_color = Color::Black;
			}
			pointer = parent;
		}
		else if (sibling->_left->_color != Color::Black
			|| sibling->_right->_color != Color::Black)
		{
			if (sibling->_right->_color == Color::Black)
			{
				sibling->_left->_color = Color::Black;
				sibling->_color = Color::Red;
				RightRotate(sibling);
				sibling = parent->_right;
			}
			sibling->_color = parent->_color;
			parent->_color = Color::Black;
			sibling->_right->_color = Color::Black;
			LeftRotate(parent);
			return true;
		}
	}
	return false;
}

bool RBTree::DeleteCase4(RBTreeNode* sibling, RBTreeNode* parent, RBTreeNode* pointer)
{
	sibling = parent->_left;
	if (sibling->_color == Color::Red)
	{
		sibling->_color = Color::Black;
		parent->_color = Color::Red;
		RightRotate(parent);
	}
	else if (sibling->_color == Color::Black)
	{
		if (sibling->_left->_color == Color::Black &&
			sibling->_right->_color == Color::Black)
		{
			sibling->_color = Color::Red;
			if (parent->_color == Color::Red)
			{
				parent->_color = Color::Black;
			}
			else if (parent->_color == Color::Black)
			{
				parent->_color = Color::Black;
			}
			pointer = parent;
		}
		else if (sibling->_left->_color != Color::Black
			|| sibling->_right->_color != Color::Black)
		{
			if (sibling->_left->_color == Color::Black)
			{
				sibling->_right->_color = Color::Black;
				sibling->_color = Color::Red;
				LeftRotate(sibling);
				sibling = parent->_left;
			}
			sibling->_color = parent->_color;
			parent->_color = Color::Black;
			sibling->_left->_color = Color::Black;
			RightRotate(parent);
			return true;
		}
	}
	return false;
}

void RBTree::TreeDeleteFix(RBTreeNode* node)
{
	if (node == nullptr)
	{
		return;
	}

	if (node == _root)
	{
		DeleteCase1(node);
		return;
	}

	if (node->_color == Color::Red
		|| node->_left->_color == Color::Red
		|| node->_right->_color == Color::Red)
	{
		DeleteCase2(node);
	}
	else if (node->_color != Color::Red
		&& node->_left->_color == Color::Red
		&& node->_right->_color == Color::Red)
	{
		RBTreeNode* sibling = nullptr;
		RBTreeNode* parent = nullptr;
		RBTreeNode* pointer = node;
		pointer, Color::Black;
		while (pointer != _root && pointer->_color == Color::Black)
		{
			parent = pointer->_parent;
			if (pointer == parent->_left)
			{
				if (DeleteCase3(sibling, parent, pointer))
				{
					break;
				}

			}
			else if (pointer != parent->_left)
			{
				if (DeleteCase4(sibling, parent, pointer))
				{
					break;
				}
			}
		}

		if (node == node->_parent->_left)
		{
			node->_parent->_left = _nil;
		}
		else if (node == node->_parent->_right)
		{
			node->_parent->_right = _nil;
		}
		delete node;
		_root->_color = Color::Black;
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

RBTreeNode* RBTree::Remove(RBTreeNode* root, const int& key)
{
	if (root == nullptr || root == _nil)
	{
		return root;
	}

	if (key < root->_key)
	{
		return Remove(root->_left, key);
	}

	if (key > root->_key)
	{
		return Remove(root->_right, key);
	}

	if (root->_left == _nil || root->_right == _nil)
	{
		return root;
	}

	RBTreeNode* temp = GetSmallestRightNode(root);
	root->_key = temp->_key;

	return Remove(root->_right, temp->_key);
}

bool RBTree::DeleteNode(const int& key)
{
	RBTreeNode* node = Remove(_root, key);
	TreeDeleteFix(node);
	return true;
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