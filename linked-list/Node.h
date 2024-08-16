class Node
{
private:
    int data;
    Node *next;

public:
    Node(int data, Node *next);

    int get_data();
    Node *get_next();
    void set_next(Node *next);
};
//