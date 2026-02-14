#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *nextNode;
};

void printList(Node *head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << "->"; // (*temp).data and temp->data are same thing
        temp = temp->nextNode;
    }

    cout << "NULL" << endl;
}

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

// REMOVE

void removeLast(Node *&head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->nextNode->nextNode == nullptr)
        {
            temp->nextNode = nullptr;
            return;
        }
        else if (temp->nextNode->nextNode == nullptr)
        {
            temp->nextNode = nullptr;
            return;
        }

        temp = temp->nextNode;
    }

    // head = nullptr;
}

void insertAtBeginning(Node *&head, int val)
{
    Node *newNode = new (nothrow) Node;
    newNode->nextNode = head;
    newNode->data = val;
    head = newNode;
}

void reverseList(Node *head)
{

    Node *prev = nullptr;
    Node *curr = head;

    if (curr != nullptr)
    {
        Node *next = curr->nextNode;

        while (curr != nullptr)
        {
            curr->nextNode = prev; // current node's nextNode becomes the previous node (reversing)

            prev = curr; // previous node is now the current node
            curr = next; // current node is now the next node
            if (curr != nullptr)
                next = curr->nextNode; // next node is now current node's nextNode
        }

        head = prev;
    }
}

void sortList(Node *&head)
{
    for (size_t i = 0; i < (listSize(head) - 1); i++)
    {
        Node **prevLink = &head;
        Node *current = head;
        Node *next = current->nextNode;
        // cout << "prevLink: " << prevLink << " current: " << current->data << " next: " << next->data << endl;
        while (current->nextNode != nullptr)
        {
            if (next->data < current->data)
            {
                // Swap
                *prevLink = next;                   // change previous node's link from current node to next
                current->nextNode = next->nextNode; // change current node's nextNode link from next to next's nextNode
                next->nextNode = current;           // change next's nextNode to current node

                // Move
                prevLink = &(next->nextNode); // move the prevLink variable from old prev to new prev
                if (current->nextNode != nullptr)
                {
                    next = current->nextNode; // move the next variable from next to current next
                }
            }
            else
            {
                prevLink = &(current->nextNode);
                current = current->nextNode;
                if (current->nextNode != nullptr)
                {
                    next = current->nextNode;
                }
            }
            // cout << "prevLink: " << prevLink << " current: " << current->data << " next: " << next->data << endl;
        }
    cout << endl;
    }
}

int main()
{
    Node node;
    node.data = 4;
    node.nextNode = nullptr;

    Node *head = &node;

    insertAtBeginning(head, 5);
    insertAtBeginning(head, 8);
    insertAtBeginning(head, 6);
    insertAtBeginning(head, 3);
    insertAtBeginning(head, 7);

    // insertAtBeginning(head, 3);
    // insertAtBeginning(head, 2);
    // insertAtBeginning(head, 1);

    // removeLast(head);
    // printList(head);
    // cout << "Size: " << listSize(head) << endl;

    // printList(head);
    // reverseList(head);
    printList(head);
    sortList(head);
    printList(head);
}