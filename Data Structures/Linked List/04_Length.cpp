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
int lenIT(Node *node)
{
    int count = 0;
    while (node != NULL)
    {
        ++count;
        node = node->next;
    }
    return count;
}

//* O(N)
int lenRec(Node *head)
{
    if (head != NULL)
    {
        return 1 + lenRec(head->next);
    }
    return 0;
}

//* O(N) + Constant space
int lenRec2(Node *head, int count = 0)
{
    if (head != NULL)
    {
        return lenRec2(head->next, count + 1);
    }
    return count;
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
    cout << lenIT(head) << endl;
    cout << lenRec(head) << endl;
    cout << lenRec2(head) << endl;
    return 0;
}