#include "Node.h"

class Tree
{
public:
    Node *root;
    int size;

    Tree();
    ~Tree();

    void insert(int data);
    void rec_print(Node *current, int space);
    void print();

    void destroy(Node *current);
};
