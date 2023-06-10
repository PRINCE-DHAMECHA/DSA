//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void push(Node **headRef, int newData)
{
    Node *newNode = new Node(newData);
    newNode->next = *headRef;
    *headRef = newNode;
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << " " << node->data;
        node = node->next;
    }
}

//* O(N)
bool searchIT(Node *node, int val)
{
    while (node != NULL)
    {
        if (node->data == val)
        {
            return true;
        }
        node = node->next;
    }
    return false;
}

//* O(N)
bool searchRec(Node *head, int x)
{
    if (head == NULL)
    {
        return false;
    }
    if (head->data == x)
    {
        return true;
    }
    return searchRec(head->next, x);
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    Node *head = NULL;
    push(&head, 7);
    push(&head, 1);
    push(&head, 6);
    push(&head, 3);
    push(&head, 14);
    cout << "Created Linked list is: ";
    printList(head);
    cout << endl
         << searchIT(head, 16) << " " << searchIT(head, 14) << endl;
    cout << searchRec(head, 16) << " " << searchRec(head, 14) << endl;
    return 0;
}