#include "Node.h"

Node::Node(int _data, Node *_next)
{
    data = _data;
    next = _next;
}

int Node::get_data() { return data; }
Node *Node::get_next() { return next; }

void Node::set_next(Node *_next) { next = _next; }