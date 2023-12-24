#pragma once
#include "AVLTreeNode.h"

class AVLTree
{
private:
	AVLTreeNode* _root;

	/// <summary>
	/// Получить фактор баланса
	/// </summary>
	/// <param name="node">узел</param>
	/// <returns>фактор</returns>
	int GetBalanceFactor(AVLTreeNode* node);

	/// <summary>
	/// Получить высоту узла
	/// </summary>
	/// <param name="node">узел</param>
	/// <returns>высота</returns>
	int GetHeight(AVLTreeNode* node);
	
	/// <summary>
	/// Исправление высоты
	/// </summary>
	/// <param name="node">узел</param>
	void FixHeight(AVLTreeNode* node);

	/// <summary>
	/// Получить самой малый узел
	/// </summary>
	/// <param name="root">корень</param>
	/// <returns>AVLTreeNode*</returns>
	AVLTreeNode* GetMin(AVLTreeNode* root);

	/// <summary>
	/// Балансировка минимального узла
	/// </summary>
	/// <param name="root">корень</param>
	/// <returns>AVLTreeNode*</returns>
	AVLTreeNode* BalanceMin(AVLTreeNode* root);

	/// <summary>
	/// Левый поворот
	/// </summary>
	/// <param name="node">узел</param>
	/// <returns>AVLTreeNode*</returns>
	AVLTreeNode* LeftRotate(AVLTreeNode* node);

	/// <summary>
	/// Правый поворот
	/// </summary>
	/// <param name="node">узел</param>
	/// <returns>AVLTreeNode*</returns>
	AVLTreeNode* RightRotate(AVLTreeNode* node);

	/// <summary>
	/// Вставка узла
	/// </summary>
	/// <param name="root">корень</param>
	/// <param name="key">ключ</param>
	/// <returns>AVLTreeNode*</returns>
	AVLTreeNode* Insert(AVLTreeNode* root, const int& key);

	/// <summary>
	/// Балансировка
	/// </summary>
	/// <param name="node">узел</param>
	/// <returns>AVLTreeNode*</returns>
	AVLTreeNode* Balance(AVLTreeNode* node);

	/// <summary>
	/// Удаление узла
	/// </summary>
	/// <param name="root">корень</param>
	/// <param name="key">ключ</param>
	/// <returns>AVLTreeNode*</returns>
	AVLTreeNode* Remove(AVLTreeNode* root, const int& key);

	/// <summary>
	/// Удаление всех узлов
	/// </summary>
	/// <param name="node">узел</param>
	void RemoveAll(AVLTreeNode* node);

public:
	AVLTree();
	~AVLTree();

	/// <summary>
	/// Добавить узел
	/// </summary>
	/// <param name="key">ключ</param>
	/// <returns>AVLTree&</returns>
	AVLTree& AddNode(const int& key);

	/// <summary>
	/// Удаление узла
	/// </summary>
	/// <param name="key">ключ</param>
	/// <returns>статус выполнения</returns>
	bool DeleteNode(const int& key);

	/// <summary>
	/// Поиск узла
	/// </summary>
	/// <param name="key">ключ</param>
	/// <returns>AVLTreeNode*</returns>
	AVLTreeNode* Search(const int& key);

	/// <summary>
	/// Получить корень
	/// </summary>
	/// <returns>AVLTreeNode*</returns>
	const AVLTreeNode* GetRoot();
};