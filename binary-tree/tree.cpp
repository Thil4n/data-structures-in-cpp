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
        size++;
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
                    size++;
                    break;
                }
                else
                {
                    current = current->right;
                }
            }
            else if (current->data > data)
            {
                cout << "data " << data << endl;
                if (current->left == nullptr)
                {
                    current->left = temp;
                    size++;
                    break;
                }
                else
                {
                    current = current->left;
                }
            }
            else
            {
                cout << "Already exists" << endl;
                break;
            }
        }
    }
}

void Tree::rec_print(Node *current, int space)
{
    if (current == NULL)
        return;

    space += 8;

    rec_print(current->right, space);

    for (int i = 8; i < space; i++)
    {
        cout << " ";
    }

    cout << current->data << endl;

    rec_print(current->left, space);
}

void Tree::print()
{
    rec_print(root, 8);
}

void Tree::destroy(Node *current)
{
    if (current != nullptr)
    {
        destroy(current->left);
        destroy(current->right);
        delete current;
    }
}

Tree::~Tree()
{
    destroy(root);
}