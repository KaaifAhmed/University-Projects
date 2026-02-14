#include <iostream>
using namespace std;

struct Node {
    int data;
    Node * nextNode;
};

int listSize (Node *head) {
    Node *temp = head;
    int size = 0;

    while (temp != nullptr)
    {
        size++;
        temp = temp->nextNode;
    }
    
    return size;
}

void printList (Node *head) {
    Node *temp = head;

    while (temp != nullptr) {
        cout << temp->data << "->";     // (*temp).data and temp->data are same thing
        temp = temp->nextNode;
    }

    cout << "NULL" << endl;
}


// INSERTIONS

void insertAtBeginning (Node* &head, int val) {
    Node *newNode = new(nothrow) Node;
    newNode->nextNode = head;
    newNode->data = val;
    head = newNode;
}

void insertAtEnd (Node *head, int val) {
    Node *newNode = new(nothrow) Node;
    newNode->data = val;
    newNode->nextNode = nullptr;
    Node *temp = head;
    while (temp->nextNode != nullptr)
    {
        temp = temp->nextNode;
    }
    temp->nextNode = newNode;
}

void insertAfterNum (Node *head, int val, int num) {
    Node *newNode = new(nothrow) Node;
    newNode->data = val;

    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == num)
        {
            newNode->nextNode = temp->nextNode;
            temp->nextNode = newNode;
        }

        temp = temp->nextNode;
        
    }
    
}




// SEARCH

bool exists(Node *head, int val) {
    Node *temp = head;

    while (temp != nullptr) {
        if (temp->data == val)
        {
            return true;
        }
        
        temp = temp->nextNode;
    }

    return false;
}

int main() {

    Node node;
    node.data = 10;
    node.nextNode = nullptr;

    Node *head = &node;

    printList(head);
    cout << "Size: " << listSize(head) << endl;
    
    insertAtBeginning(head, 9);

    printList(head);
    cout << "Size: " << listSize(head) << endl;

    insertAtEnd(head, 12);
    
    printList(head);
    cout << "Size: " << listSize(head) << endl;

    insertAfterNum(head, 11, 10);
    
    printList(head);
    cout << "Size: " << listSize(head) << endl;

    // cout << "\n\'10\' exists? " << (exists(head, 10)?"True": "False") << endl;
    // cout << "\'1\' exists? " << (exists(head, 1)?"True": "False") << endl;
    
    
}