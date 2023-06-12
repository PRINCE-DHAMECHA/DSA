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

//~ Approach:2 :-
Node *reverseRec(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    //* Eventually we need to return last node, so that head can point into that
    Node *rest = reverseRec(head->next);
    head->next->next = head;
    //* We set next of current to NULL because next of current will be decided by previous call i.e. in above step
    head->next = NULL;
    //* Return last node
    return rest;
}

//~ Approach:3 :-
void reverseTailRec(Node *curr, Node *prev, Node **head)
{
    //* Last Node
    if (!curr->next)
    {
        //* Make head to point curr // last node
        *head = curr;
        curr->next = prev;
        return;
    }
    Node *next = curr->next;
    curr->next = prev;
    reverseTailRec(next, curr, head);
}

void reverseTailRec(Node **head)
{
    if (!head)
    {
        return;
    }
    reverseTailRec(*head, NULL, head);
}

//~ Approach:4 :-
//* Use stack to store element and create new list while popping
//* Noob Approach

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
    cout << endl;
    head = reverseRec(head);
    printList(head);
    cout << endl;
    reverseTailRec(&head);
    printList(head);
    return 0;
}