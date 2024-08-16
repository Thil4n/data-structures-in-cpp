#include "Node.h"

Node::Node(int _data)
{
    data = _data;
    next = nullptr;
}

int Node::get_data() { return data; }
Node *Node::get_next() { return next; }

void Node::set_next(Node *_next) { next = _next; }