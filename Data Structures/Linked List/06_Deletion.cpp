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
        cout << " " << node->data;
        node = node->next;
    }
}

//* position from 0 to 1
void deleteN(Node **head, int position)
{
    Node *temp = *head;
    Node *prev = *head;
    if (position == 1)
    {
        *head = (*head)->next;
        free(temp);
        return;
    }
    for (int i = 0; i < position; i++)
    {
        if (i == position - 1 && temp)
        {
            prev->next = temp->next;
            free(temp);
            return;
        }
        else
        {
            prev = temp;
            if (prev == NULL)
            {
                break;
            }
            temp = temp->next;
        }
    }
}

//* Delete with key
void deleteKey(Node **head, int key)
{
    Node *temp = *head;
    Node *prev = *head;
    if ((*head)->data == key)
    {
        *head = (*head)->next;
        free(temp);
        return;
    }
    while (temp != NULL)
    {
        if (temp && temp->data == key)
        {
            prev->next = temp->next;
            free(temp);
            return;
        }
        else
        {
            prev = temp;
            if (prev == NULL)
            {
                break;
            }
            temp = temp->next;
        }
    }
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
    // deleteN(&head, 5);
    // printList(head);
    // cout << endl;
    // deleteN(&head, 2);
    // printList(head);
    // cout << endl;
    deleteKey(&head, 7);
    printList(head);
    cout << endl;
    return 0;
}