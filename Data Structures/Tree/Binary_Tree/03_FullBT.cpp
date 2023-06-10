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
    int val;
    Node *left;
    Node *right;
    Node(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

//* In a full binary tree, every node except the leaves has exactly two children. // All node has 0 or 2 child.
//& https://media.geeksforgeeks.org/wp-content/uploads/20221125111700/full.png

class FullBT
{
public:
    Node *root;
    FullBT()
    {
        root = NULL;
    }
    void insert(int val);
};

void FullBT::insert(int val)
{
    Node *newNode = new Node(val);
    if (!root)
    {
        root = newNode;
        return;
    }
    else
    {
        Node *currentNode = root;
        while (1)
        {
            if (!currentNode->left)
            {
                currentNode->left = newNode;
                break;
            }
            else if (!currentNode->right)
            {
                currentNode->right = newNode;
                break;
            }
            else
            {
                currentNode = currentNode->left;
            }
        }
    }
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    FullBT tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    return 0;
}
