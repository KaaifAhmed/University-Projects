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
    cout << endl;
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
    newNode->prevNode = nullptr;
    newNode->nextNode = head;
    if (head != nullptr)
        head->prevNode = newNode;
    head = newNode;
}

void insertAtPosition(int data, int pos, Node *&head)
{
    Node *newNode = new (nothrow) Node;
    if (!newNode)
        return;
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

// DELETION
void deleteAtPosition(int pos, Node *&head)
{
    if (head == nullptr)
        return;
    Node *temp = head;
    if (pos <= 0)
    {
        head = temp->nextNode;
        (temp->nextNode)->prevNode = nullptr;
    }
    else if (pos < listSize(head) - 1)
    {
        int cpos = 0;
        while (cpos < pos)
        {
            temp = temp->nextNode;
            cpos++;
        }
        (temp->prevNode)->nextNode = temp->nextNode;
        (temp->nextNode)->prevNode = temp->prevNode;
    }
    else
    {
        while (temp->nextNode != nullptr)
        {
            temp = temp->nextNode;
        }
        (temp->prevNode)->nextNode = nullptr;
    }
}

// REVERSING
void reverseList(Node *&head)
{
    Node *temp = head;
    while (temp->nextNode != nullptr)
    {
        Node *swapTemp = temp->nextNode;
        temp->nextNode = temp->prevNode;
        temp->prevNode = swapTemp;
        temp = temp->prevNode;
    }
    head = temp;
    temp->nextNode = temp->prevNode;
    temp->prevNode = nullptr;
}

// MERGE DLLs
Node *mergeLists(Node *head1, Node *head2)
{
    Node *temp = head1;
    while (temp->nextNode != nullptr)
    {
        temp = temp->nextNode;
    }
    temp->nextNode = head2;
    head2->prevNode = temp;

    Node *newHead = head1;

    return newHead;
}

int main()
{
    Node *head = nullptr;
    Node *head1 = nullptr;

    insertAtBeginning(9, head);
    insertAtBeginning(8, head);
    insertAtBeginning(7, head);
    insertAtBeginning(6, head);

    insertAtBeginning(5, head1);
    insertAtBeginning(4, head1);
    insertAtBeginning(3, head1);
    insertAtBeginning(2, head1);

    int choice;
    while (true)
    {
        cout << "\n1) Print Lists\n2) Size L1 & L2\n3) Insert L1\n4) Insert L2\n5) Delete L1\n6) Delete L2\n7) Reverse L1 & L2\n8) Merge\n9) Quit\n";
        cout << "Choice: ";
        cin >> choice;
        cout << endl;

        if (choice == 9)
            break;
        else if (choice == 1){
            cout << "List # 1: ";
            printList(head);
            cout << "\nList # 2: ";
            printList(head1);
        }            
        else if (choice == 2){
            cout << "Size of List # 1: " << listSize(head) << endl;            
            cout << "Size of List # 2: " << listSize(head1) << endl;
        }
        else if (choice == 3)
        {
            int x;
            cout << "Value: ";
            cin >> x;
            int pos;
            cout << "Position: ";
            cin >> pos;
            insertAtPosition(x, pos, head);
        }
        else if (choice == 4)
        {
            int x;
            cout << "Value: ";
            cin >> x;
            insertAtBeginning(x, head1);
        }
        else if (choice == 5)
        {
            int p;
            cout << "Pos: ";
            cin >> p;
            deleteAtPosition(p, head);
        }
        else if (choice == 6)
        {
            int p;
            cout << "Pos: ";
            cin >> p;
            deleteAtPosition(p, head1);
        }
        else if (choice == 7) {
            reverseList(head);
            reverseList(head1);
            printList(head);
            printList(head1);
        }
        else if (choice == 8)
        {
            Node *merged = mergeLists(head1, head);
            printList(merged);
        }
    }

    return 0;
}