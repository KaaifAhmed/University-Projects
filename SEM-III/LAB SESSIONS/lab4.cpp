#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prevNode;
    Node *nextNode;
};

int listSize(Node *head)
{
    Node *temp = head;
    int size = 0;

    while (temp != nullptr)
    {
        size++;
        temp = temp->nextNode;
    }

    return size;
}

void printList(Node *head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->nextNode;
    }
}

int searchVal(int val, Node *head)
{
    Node *temp = head;
    int pos = 0;

    while (temp != nullptr)
    {
        if (temp->data == val)
        {
            return pos;
        }
        temp = temp->nextNode;
        pos++;
    }

    return -1;
}

// INSERTION
void insertAtBeginning(int data, Node *&head)
{
    Node *newNode = new (nothrow) Node;
    newNode->data = data;

    newNode->nextNode = head;
    head = newNode;
    newNode->prevNode = nullptr;

    newNode->nextNode->prevNode = newNode;
}

void insertAtPosition(int data, int pos, Node *&head)
{
    Node *newNode = new (nothrow) Node;
    newNode->data = data;
    Node *temp = head;

    if (pos >= listSize(head))
    {

        while (temp->nextNode != nullptr)
            temp = temp->nextNode;

        newNode->nextNode = nullptr;
        newNode->prevNode = temp;

        temp->nextNode = newNode;
    }
    else
    {
        int cpos = 0;
        while (cpos < pos)
        {
            temp = temp->nextNode;
            cpos++;
        }

        newNode->nextNode = temp;
        newNode->prevNode = temp->prevNode;

        (newNode->prevNode)->nextNode = newNode;
        (newNode->nextNode)->prevNode = newNode;
    }
}

void insertAtEnd(int data, Node *&head)
{
    Node *temp = head;

    while (temp->nextNode != nullptr)
        temp = temp->nextNode;

    Node *newNode = new (nothrow) Node;
    newNode->data = data;
    newNode->nextNode = nullptr;
    newNode->prevNode = temp;

    temp->nextNode = newNode;
}

int main()
{
    Node node;
    node.data = 9;
    node.nextNode = nullptr;
    node.prevNode = nullptr;

    Node *head = &node;

    insertAtBeginning(8, head);
    insertAtBeginning(7, head);
    insertAtBeginning(6, head);
    insertAtEnd(10, head);
    insertAtPosition(55, 5, head);
    printList(head);

    cout << "\nThe list size is: " << listSize(head);
    // cout << &node << ": " << head;
    cout << "\nThe number 8 exists at position: " << searchVal(8, head);

    return 0;
}