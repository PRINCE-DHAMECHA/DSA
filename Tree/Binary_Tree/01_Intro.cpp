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

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    //     1
    //    / \
    //   2   3
    //  /
    // 4

    return 0;
}

//* The height of a binary tree is defined as the number of edges from the root node to the deepest leaf node.

//* The maximum number of nodes at level ‘l’ of a binary tree is 2^l // start from 0

//* The Maximum number of nodes in a binary tree of height ‘h’ is (2^h) – 1 // 2^0+2^1...+2^(h-1)=1+2+4+...

//* In a Binary Tree with N nodes, the minimum possible height or the minimum number of levels is Log2(N+1) // N<=2^(h)-1

//* A Binary Tree with L leaves has at least | Log2L |+ 1 levels // L   <=  2^(l-1) // root from 1

//* In a Binary tree where every node has 0 or 2 children, the number of leaf nodes is always one more than nodes with two children.

//* In a non-empty binary tree, if n is the total number of nodes and e is the total number of edges, then e = n-1.