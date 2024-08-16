#include "List.h"
#include <iostream>

using namespace std;

List::List()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void List::append(int data)
{

    Node *temp = new Node(data);
    if (head == nullptr)
    {
        head = temp;
        tail = temp;
    }
    else
    {

        tail->set_next(temp);
        tail = temp;
    }
}
void List::print()
{
    Node *current = head;

    while (current != nullptr)
    {
        cout << current->get_data() << endl;
        current = current->get_next();
    }
}

List::~List()
{
}
