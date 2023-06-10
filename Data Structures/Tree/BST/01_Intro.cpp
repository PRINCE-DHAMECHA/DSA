//~ What is Binary Search Tree?

//* The left subtree of a node contains only nodes with keys lesser than the node’s key.
//* The right subtree of a node contains only nodes with keys greater than the node’s key.
//* The left and right subtree each must also be a binary search tree.
//* The root of a BST is the node that has the largest value in the left subtree and the smallest value in the right subtree.

//~ Handling approach for Duplicate values in the Binary Search tree:

//* You can not allow the duplicated values at all.
//* We must follow a consistent process throughout i.e either store duplicate value at the left or store the duplicate value at the right of the root, but be consistent with your approach.
//* We can keep the counter with the node and if we found the duplicate value, then we can increment the counter

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

Node *insert(Node *node, int key)
{
    if (node == NULL)
    {
        return new Node(key);
    }
    if (key < node->val)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->val)
    {
        node->right = insert(node->right, key);
    }
    return node;
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    inorder(root);

    return 0;
}

//* In case of binary search trees (BST), Inorder traversal gives nodes in non-decreasing order.

//* Preorder traversal: Preorder traversal first visits the root node and then traverses the left and the right subtree. It is used to create a copy of the tree. Preorder traversal is also used to get prefix expression on of an expression tree.

//* Postorder traversal: Postorder traversal first traverses the left and the right subtree and then visits the root node. It is used to delete the tree. In simple words, visit the root of every subtree last.