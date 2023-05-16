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

//* O(1)
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
        cout << node->data << " ";
        node = node->next;
    }
}

//* Iterative way
Node *getNth(Node *head, int index)
{
    Node *current = head;
    int count = 0;
    while (current != NULL)
    {
        if (count == index)
        {
            return current;
        }
        count++;
        current = current->next;
    }
    return NULL;
}

//* Recursive
Node *getNthRec(Node *head, int n)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (n == 0)
    {
        return head;
    }
    return getNthRec(head->next, n - 1);
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    Node *head = NULL;
    push(&head, 7);
    push(&head, 1);
    push(&head, 8);
    push(&head, 10);
    push(&head, 11);
    push(&head, 100);
    printList(head);
    cout << endl;
    cout << (getNth(head, 3))->data << endl;
    cout << (getNthRec(head, 2))->data << endl;
    return 0;
}