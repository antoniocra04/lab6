#include <iostream>
#include "RBTree.h"
#include "AVLTree.h"
using namespace std;

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

/*!
 * \brief Меню и управление красно-черным деревом
 */
void ControllerRBTree()
{
    string menu = "Choose one of activity:\n1 - Add\n2 - Remove\n3 - Search\nq - Exit to main menu\nYour choice: ";
    int data;
    RBTree tree;
    char mode = '\0';

    while (mode != 'q')
    {
        tree.VisualisateRBTree();
        cout << menu;
        ValidInput(mode);
        system("cls");
        switch (mode) {
        case '1':
            cout << "Enter value for adding: ";
            ValidInput(data);
            tree.AddNode(data);
            break;
        case '2':
            cout << "Enter value for deletion: ";
            ValidInput(data);
            tree.DeleteNode(data);
            break;
        case '3':
            cout << "Enter value for search: ";
            ValidInput(data);
            if (tree.Search(data) != nullptr)
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

/*!
 * \brief Меню и управление АВЛ-деревом
 */
void ControllerAVLTree()
{
    string menu = "Choose one of activity:\n1 - Add\n2 - Remove\n3 - Search\nq - Exit to main menu\nYour choice: ";
    int value;
    AVLTree tree;
    char mode = '\0';

    while (mode != 'q')
    {
        tree.VisualisateAVLTree();
        cout << menu;
        ValidInput(mode);
        system("cls");
        switch (mode) {
        case '1':
            cout << "Enter value for adding: ";
            ValidInput(value);
            tree.AddNode(value);
            break;
        case '2':
            cout << "Enter value for adding: ";
            ValidInput(value);
            tree.DeleteNode(value);
            break;
        case '3':
            cout << "Enter value for search: ";
            ValidInput(value);
            if (tree.Search(value) != nullptr)
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
    string menu = "Choose one of structure:\n1 - Red-black tree\n2 - AVL tree\nq - Quit\nYour choice: ";
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