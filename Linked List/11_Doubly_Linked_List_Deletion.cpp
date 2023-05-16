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
    n->next = *headRef;
    if (*headRef != NULL)
    {
        (*headRef)->prev = n;
    }
    *(headRef) = n;
}

void deleteNode(Node **headRef, Node *del)
{
    if (*headRef == NULL && del == NULL)
    {
        return;
    }
    //* If deleted node to be head
    if (*headRef == del)
    {
        *headRef = del->next;
    }
    //* if deleted node to be not last one
    if (del->next != NULL)
    {
        del->next->prev = del->prev;
    }
    //* if deleted node is not first one
    if (del->prev != NULL)
    {
        del->prev->next = del->next;
    }
    free(del);
    return;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    Node *head = NULL;
    insertAtHead(&head, 8);
    insertAtHead(&head, 7);
    insertAtHead(&head, 6);
    insertAtHead(&head, 5);
    insertAtHead(&head, 4);
    insertAtHead(&head, 3);
    insertAtHead(&head, 2);
    insertAtHead(&head, 1);
    printList(head);
    deleteNode(&head, head);
    printList(head);
    deleteNode(&head, head->next);
    printList(head);
    deleteNode(&head, head->next->next);
    printList(head);
    deleteNode(&head, head->next->next->next->next);
    printList(head);
    deleteNode(&head, head->next->next);
    printList(head);
    return 0;
}