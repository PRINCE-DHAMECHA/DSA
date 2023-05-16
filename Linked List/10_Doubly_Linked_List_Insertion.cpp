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
    Node *prev;
    int data;
    Node *next;
    Node(int val)
    {
        prev = NULL;
        data = val;
        next = NULL;
    }
};

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insertAtHead(Node **headRef, int val)
{
    Node *n = new Node(val);
    //* New head->next = old head
    n->next = *headRef;
    if (*headRef != NULL)
    {
        //* old head->prev=new head
        (*headRef)->prev = n;
    }
    //* set new head
    *(headRef) = n;
}

void insertAfter(Node *node, int data)
{
    if (node == NULL)
    {
        cout << "Given node cannot be null" << endl;
        return;
    }
    Node *newNode = new Node(data);
    newNode->next = node->next;
    node->next = newNode;
    newNode->prev = node;
    if (newNode != NULL)
    {
        newNode->next->prev = newNode;
    }
}

void insertBefore(Node *head, Node *node, int data)
{
    if (node == NULL)
    {
        cout << "Given node cannot be null" << endl;
        return;
    }
    Node *newNode = new Node(data);
    newNode->prev = node->prev;
    node->prev = newNode;
    newNode->next = node;
    if (newNode->prev != NULL)
    {
        newNode->prev->next = newNode;
    }
    else
    {
        head = newNode;
    }
}

void insertAtTail(Node **headRef, int val)
{
    if (*headRef == NULL)
    {
        insertAtHead(headRef, val);
        return;
    }
    Node *n = new Node(val);
    Node *temp = *headRef;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    //* old tail->next=new tail
    temp->next = n;
    //* new tail->pre = old tail
    n->prev = temp;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    Node *head = NULL;
    insertAtTail(&head, 1);
    insertAtTail(&head, 2);
    insertAtTail(&head, 3);
    insertAtTail(&head, 4);
    printList(head);
    insertBefore(head, head->next->next->next, 11);
    printList(head);
    insertAfter(head->next->next->next, 16);
    printList(head);
    insertAtTail(&head, 5);
    insertAtHead(&head, 6);
    insertAtTail(&head, 7);
    printList(head);
    return 0;
}