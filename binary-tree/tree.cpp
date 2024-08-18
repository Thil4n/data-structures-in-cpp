#include "Tree.h"
#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;

Tree::Tree()
{
    root = nullptr;
    size = 0;
}

void Tree::insert(int data)
{
    cout << "inserting data : " << data << endl;

    Node *temp = new Node(data);

    if (root == nullptr)
    {

        root = temp;
        size++;
    }
    else
    {
        Node *current = root;
        while (true)
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

void Tree::find(int data)
{
    cout << "finding data : " << data << endl;

    if (root == nullptr)
    {

        cout << "Not found" << endl;
    }
    else
    {
        Node *current = root;
        bool found = false;
        while (true)
        {

            if (current->data == data)
            {
                cout << "Found" << endl;
                found = true;
                break;
            }

            if (current->data < data)
            {

                if (current->right == nullptr)
                {

                    break;
                }
                else
                {
                    current = current->right;
                }
            }
            else if (current->data > data)
            {

                if (current->left == nullptr)
                {

                    break;
                }
                else
                {
                    current = current->left;
                }
            }
        }

        if (!found)
        {

            cout << "Not found" << endl;
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

// void Tree::print()
// {
//     rec_print(root, 8);
// }

void Tree::print()
{
    if (root == nullptr)
    {
        cout << "Tree is empty." << endl;
        return;
    }

    // Use a queue to perform level-order traversal
    queue<Node *> q;
    q.push(root);

    int level = 0;
    while (!q.empty())
    {
        int nodeCount = q.size();

        cout << "Level " << level++ << ": ";

        while (nodeCount > 0)
        {
            Node *node = q.front();
            q.pop();

            // Print the current node's data
            cout << setw(4) << node->data << " ";

            // Enqueue left and right children
            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);

            nodeCount--;
        }
        cout << endl;
    }
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