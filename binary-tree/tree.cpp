#include "Tree.h"
#include <iostream>

using namespace std;

Tree::Tree()
{
    root = nullptr;
    size = 0;
}

void Tree::insert(int data)
{

    Node *temp = new Node(data);
    if (root == nullptr)
    {
        root = temp;
    }
    else
    {
        Node *current = root;
        while (current != nullptr)
        {
            if (current->data < data)
            {
                if (current->right == nullptr)
                {
                    current->right = temp;
                    break;
                }
                else
                {
                    current = current->right;
                }
            }
            else if (current->data < data)
            {
                if (current->left == nullptr)
                {
                    current->left = temp;
                    break;
                }
            }
            else
            {
                cout << "already exist" << endl;
                break;
            }
        }
    }
}

// void Tree::print()
// {
//     Node *current = head;

//     while (current != nullptr)
//     {
//         cout << current->get_data() << endl;
//         current = current->get_next();
//     }
// }

Tree::~Tree()
{
}
