//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//* A skewed binary tree is a pathological/degenerate tree in which the tree is either dominated by the left nodes or the right nodes. Thus, there are two types of skewed binary tree: left-skewed binary tree and right-skewed binary tree.

class Node
{
public:
    int val;
    Node *right;
    Node(int data)
    {
        val = data;
        right = NULL;
    }
};

class SkewedBT
{
public:
    Node *root;
    SkewedBT() { root = NULL; }
    void insert(int val);
};

void SkewedBT::insert(int val)
{
    Node *newNode = new Node(val);
    if (!root)
    {
        root = newNode;
    }
    else
    {
        Node *currentNode = root;
        while (currentNode->right)
        {
            currentNode = currentNode->right;
        }
        currentNode->right = newNode;
    }
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    SkewedBT tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    return 0;
}