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

//~ Approach-1: iterative
//* Time: O(N) - Space: O(1)
void reverseIT(Node **headRef)
{
    Node *curr = *headRef;
    Node *prev = NULL, *next = NULL;
    while (curr != NULL)
    {
        //* Point next
        next = curr->next;
        //* Change current's next to prev
        curr->next = prev;
        //* set current as prev for next node
        prev = curr;
        //* Set current as next
        curr = next;
    }
    *headRef = prev;
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
    printList(head);
    reverseIT(&head);
    cout << endl;
    printList(head);
    return 0;
}