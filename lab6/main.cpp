#include <iostream>
#include "RBTree.h"
#include "AVLTree.h"
using namespace std;

void PrintRBTree(const RBTreeNode* root, RBTree* tree, int space, int count)
{
    if (root == nullptr || root == tree->GetNil())
    {
        return;
    }

    space += count;
    PrintRBTree(root->_right, tree, space, count);

    cout << endl;

    for (int i = count; i < space; i++) 
    {
        cout << " ";
    }

    if (root == tree->GetNil())
    {
        cout << "[]" << "\n";
    }
    else if (root->_color == Color::Black)
    {
        cout << root->_key << "\n";
    }
    else
    {
        cout << "\x1B[31m" << root->_key << "\033[0m\t\t" << "\n";
    }

    PrintRBTree(root->_left, tree, space, count);
}

void PrintAVLTree(const AVLTreeNode* root, int space, int count) {
    if (root == nullptr) {
        return;
    }

    space += count;
    PrintAVLTree(root->_right, space, count);

    cout << endl;

    for (int i = count; i < space; i++) {
        cout << " ";
    }

    cout << root->_key << "\n";
    PrintAVLTree(root->_left, space, count);
}


template <typename T>
void ValidInput(T& variable)
{
    cin >> variable;
    while (cin.fail() || cin.get() != '\n')
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Enter correct value: ";
        cin >> variable;
    }
}

/// <summary>
/// Меню кчд
/// </summary>
void ControllerRBTree()
{
    string menu = "Choose one of activity:\
                   \n1 - Add\n2 - Remove\n3 - Search\nq - Exit to main menu\nYour choice: ";
    int data;
    RBTree* tree = new RBTree;
    char mode = '\0';
    string enterMessage = "Enter value for ";

    while (mode != 'q')
    {
        PrintRBTree(tree->GetRoot(), tree, 0, 5);
        cout << menu;
        ValidInput(mode);
        system("cls");
        switch (mode) {
        case '1':
            cout << enterMessage << "adding: ";
            ValidInput(data);
            tree->AddNode(data);
            break;
        case '2':
            cout << enterMessage << "deletion: ";
            ValidInput(data);
            tree->DeleteNode(data);
            break;
        case '3':
            cout << enterMessage << "search: ";
            ValidInput(data);
            if (tree->Search(data) != nullptr)
            {
                cout << "Value " << data << " is contained in red-black tree!\n";
            }
            else
            {
                cout << "No value " << data << " in red-black tree!\n";
            }
            break;
        default:
            break;
        }
    }
}

/// <summary>
/// Меню авл дерева
/// </summary>
void ControllerAVLTree()
{
    string menu = "Choose one of activity:\
                   \n1 - Add\n2 - Remove\n3 - Search\nq - Exit to main menu\nYour choice: ";
    int value;
    AVLTree* tree = new AVLTree;
    char mode = '\0';
    string enterMessage = "Enter value for ";

    while (mode != 'q')
    {
        PrintAVLTree(tree->GetRoot(), 0, 5);
        cout << menu;
        ValidInput(mode);
        system("cls");
        switch (mode) {
        case '1':
            cout << enterMessage << "adding: ";
            ValidInput(value);
            tree->AddNode(value);
            break;
        case '2':
            cout << enterMessage << "delete: ";
            ValidInput(value);
            tree->DeleteNode(value);
            break;
        case '3':
            cout << enterMessage << "search: ";
            ValidInput(value);
            if (tree->Search(value) != nullptr)
            {
                cout << "Value " << value << " is contained in AVL-tree!\n";
            }
            else
            {
                cout << "No value " << value << " in AVL-tree!\n";
            }
            break;
        default:
            break;
        }
    }
}

void MainController()
{
    string menu = "Choose one of structure:\
                  \n1 - Red-black tree\n2 - AVL tree\nq - Quit\nYour choice: ";
    char mode = '\0';

    while (mode != 'q')
    {
        cout << menu;
        ValidInput(mode);
        system("cls");
        switch (mode) {
        case '1':
            ControllerRBTree();
            break;
        case '2':
            ControllerAVLTree();
            break;
        default:
            break;
        }
    }
}


int main()
{
    MainController();
	return 0;
}