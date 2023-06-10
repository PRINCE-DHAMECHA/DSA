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

//* O(1)
void insertAfter(Node *prev, int newData)
{
    if (prev == NULL)
    {
        cout << "Previous node cannot be NULL" << endl;
        return;
    }
    Node *newNode = new Node(newData);
    newNode->next = prev->next;
    prev->next = newNode;
    return;
}

//* O(N)
void append(Node **headRef, int newData)
{
    Node *newNode = new Node(newData);
    Node *last = *headRef;
    //* Current list is empty then insert only node as head node
    if (*headRef == NULL)
    {
        *headRef = newNode;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
    return;
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << " " << node->data;
        node = node->next;
    }
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    // Start with the empty list
    //* Head stores location of first node
    //* i.e. head contains address of first node
    Node *head = NULL;

    // Insert 6. So linked list becomes 6->NULL
    //* Now we need to change head node
    //* So we pass address of head which contains address of first node and in function we place address of new first node
    //* So we need pointer to pointer i.e. pointer to head
    append(&head, 6);

    // Insert 7 at the beginning.
    // So linked list becomes 7->6->NULL
    push(&head, 7);

    // Insert 1 at the beginning.
    // So linked list becomes 1->7->6->NULL
    push(&head, 1);

    // Insert 4 at the end. So
    // linked list becomes 1->7->6->4->NULL
    append(&head, 4);

    // Insert 8, after 7. So linked
    // list becomes 1->7->8->6->4->NULL
    insertAfter(head->next, 8);

    cout << "Created Linked list is: ";
    printList(head);
    return 0;
}