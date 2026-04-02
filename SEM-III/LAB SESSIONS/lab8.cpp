#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *rightNode;
    Node *leftNode;
};

Node *insertNode(Node *root, int data)
{
    if (data <= root->data)
    {
        if (root->leftNode == NULL)
        {
            Node *newNode = new Node();
            newNode->data = data;
            newNode->leftNode = NULL;
            newNode->rightNode = NULL;

            root->leftNode = newNode;
            return newNode;
        }
        else
        {
            return insertNode(root->leftNode, data);
        }
    }
    else
    {
        if (root->rightNode == NULL)
        {
            Node *newNode = new Node();
            newNode->data = data;
            newNode->leftNode = NULL;
            newNode->rightNode = NULL;

            root->rightNode = newNode;
            return newNode;
        }
        else
        {
            return insertNode(root->rightNode, data);
        }
    }
}

void printInOrder(Node *rootNode)
{
    if (rootNode == NULL)
    {
        cout << "NULL";
    }
    else
    {
        if (rootNode->leftNode != NULL)
        {
            printInOrder(rootNode->leftNode);
        }
        printf(" %d ", rootNode->data);
        if (rootNode->rightNode != NULL)
        {
            printInOrder(rootNode->rightNode);
        }
    }
}

bool exists(Node *rootNode, int target)
{
    if (rootNode->data == target)
    {
        return true;
    }
    else if ((rootNode->data > target) && (rootNode->leftNode != NULL))
    {
        return exists(rootNode->leftNode, target);
    }
    else if (rootNode->rightNode != NULL)
    {
        return exists(rootNode->rightNode, target);
    }
    else
    {
        return false;
    }
}

Node *findLargest(Node *rootNode)
{
    if (rootNode == NULL)
    {
        return NULL;
    }
    else if (rootNode->rightNode != NULL)
    {
        return findLargest(rootNode->rightNode);
    }
    return rootNode;
}

Node *deleteNode(Node *rootNode, int key)
{
    if (rootNode == NULL)
        return rootNode;
    else if (rootNode->data > key)
    {
        rootNode->leftNode = deleteNode(rootNode->leftNode, key);
        return rootNode;
    }
    else if (rootNode->data < key)
    {
        rootNode->rightNode = deleteNode(rootNode->rightNode, key);
        return rootNode;
    }

    else
    {
        int children = 0;
        if (rootNode->leftNode != NULL)
            children++;
        if (rootNode->rightNode != NULL)
            children++;

        switch (children)
        {
        case 0:
            return NULL;
            break;
        case 1:
            if (rootNode->leftNode == NULL)
            {
                return rootNode->rightNode;
            }
            else
                return rootNode->leftNode;
            break;
        case 2:
        {
            Node *leftMax = findLargest(rootNode->leftNode);
            rootNode->data = leftMax->data;
            rootNode->leftNode = deleteNode(rootNode->leftNode, leftMax->data);
            return rootNode;
            break;
        }
        default:
            return NULL;
        }
    }
}

int main()
{

    Node *n1 = new Node();
    n1->data = 10;
    n1->rightNode = NULL;
    n1->leftNode = NULL;

    Node *n2 = insertNode(n1, 2);
    Node *n3 = insertNode(n1, 12);
    Node *n4 = insertNode(n1, 8);
    Node *n5 = insertNode(n1, 18);
    Node *n6 = insertNode(n1, 1);
    Node *n7 = insertNode(n1, 3);

    // printInOrder(n1);

    // int target = 180;
    // printf("\nNumber %d exists? %d", target, exists(n1, target));

    // cout << findLargest(n6);

    printInOrder(n7);
    n7 = deleteNode(n7, 3);
    cout << "\nAfter deletion:\n";
    printInOrder(n7);

    return 0;
}