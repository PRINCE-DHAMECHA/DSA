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

void printInorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printInorder(root->left);  // Left subtree first
    cout << root->val << " ";  // Then root
    printInorder(root->right); // Then right subtree
}

void printPreorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->val << " ";   //  root
    printPreorder(root->left);  // Left subtree
    printPreorder(root->right); // Then right
}

void printPostorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printPostorder(root->left);  // Left subtree
    printPostorder(root->right); // Then right
    cout << root->val << " ";    // Then root
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    //*        1
    //*       / \
    //*      2   3
    //*    /  \   
    //*   4    5

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "\nInorder traversal of binary tree is \n";
    printInorder(root);
    cout << "\nPreorder traversal of binary tree is \n";
    printPreorder(root);
    cout << "\nPostorder traversal of binary tree is \n";
    printPostorder(root);

    return 0;
}