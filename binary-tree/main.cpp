#include "Tree.h"

int main(int argc, char const *argv[])
{
    Tree tree;

    tree.insert(4);
    tree.insert(5);
    tree.insert(32);
    tree.insert(2);
    tree.insert(11);
    // tree.find(0);
    tree.print();

    return 0;
}
