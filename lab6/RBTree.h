#pragma once
#include "RBTreeNode.h"

class RBTree
{
private:
	RBTreeNode* _root;
	RBTreeNode* _nil;

	/// <summary>
	/// Левый поворот
	/// </summary>
	/// <param name="node">узел</param>
	void LeftRotate(RBTreeNode* node);

	/// <summary>
	/// Правый поворот
	/// </summary>
	/// <param name="node">узел</param>
	void RightRotate(RBTreeNode* node);

	/// <summary>
	/// Балансировка и перекраска дерева после добавления узла
	/// </summary>
	/// <param name="node">узел</param>
	void TreeAddFix(RBTreeNode* node);

	/// <summary>
	/// Балансировка и перекраска дерева после удаления узла
	/// </summary>
	/// <param name="node">узел</param>
	void TreeDeleteFix(RBTreeNode* node);

	/// <summary>
	/// Изменить дочерний узел в родителе node на changeNode
	/// </summary>
	/// <param name="node">Узел в родителя которого нужно изменить</param>
	/// <param name="changeNode">Узел на который нужно изменить</param>
	void ChangeNodeInParent(RBTreeNode* node, RBTreeNode* changeNode);

	/// <summary>
	/// Найти самый малый узел справа
	/// </summary>
	/// <param name="startNode">начальный узел</param>
	/// <returns>RBTreeNode*</returns>
	RBTreeNode* GetSmallestRightNode(RBTreeNode* startNode);

	/// <summary>
	/// Удаления всех узлов дерева
	/// </summary>
	/// <param name="node">узел</param>
	void RemoveAll(RBTreeNode* node);

	/// <summary>
	/// Найти самое малое значение
	/// </summary>
	/// <param name="root">корень дерева</param>
	/// <returns>RBTreeNode*</returns>
	RBTreeNode* GetMin(RBTreeNode* root);

public:
	RBTree();
	~RBTree();

	/// <summary>
	/// Добавить узел
	/// </summary>
	/// <param name="key">ключ</param>
	/// <returns>RBTree&</returns>
	RBTree& AddNode(const int& key);

	/// <summary>
	/// Удалить узел
	/// </summary>
	/// <param name="key">ключ</param>
	/// <returns>bool</returns>
	bool DeleteNode(const int& key);

	/// <summary>
	/// Поиск узла
	/// </summary>
	/// <param name="key">значение</param>
	/// <returns>RBTreeNode*</returns>
	RBTreeNode* Search(const int& key);

	/// <summary>
	/// Получить корень
	/// </summary>
	/// <returns>RBTreeNode*</returns>
	const RBTreeNode* GetRoot();

	/// <summary>
	/// Получить лист
	/// </summary>
	/// <returns>RBTreeNode*</returns>
	const RBTreeNode* GetNil();
};