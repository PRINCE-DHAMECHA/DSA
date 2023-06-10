//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//* A Tree where every internal node has one child. Such trees are performance-wise same as linked list. A degenerate or pathological tree is a tree having a single child either left or right.

class Node
{
public:
    int val;
    Node *next;
    Node(int data)
    {
        val = data;
        next = NULL;
    }
};

class DegenerateBT
{
public:
    vector<Node *> nodes;
    DegenerateBT() {}
    void insert(int val);
};

void DegenerateBT::insert(int val)
{
    Node *newNode = new Node(val);
    if (nodes.empty())
    {
        nodes.push_back(newNode);
    }
    else
    {
        Node *lastNode = nodes.back();
        lastNode->next = newNode;
        nodes.push_back(newNode);
    }
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    DegenerateBT tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    return 0;
}