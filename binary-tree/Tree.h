#include "Node.h"

class Tree
{
public:
    Node *root;
    int size;

    Tree();
    ~Tree();

    void insert(int data);
    void print();
};
