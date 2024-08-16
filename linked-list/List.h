#include "Node.h"

class List
{
private:
    Node *head, *tail;
    int size;

public:
    List();
    ~List();

    void append(int data);
    void print();
};
