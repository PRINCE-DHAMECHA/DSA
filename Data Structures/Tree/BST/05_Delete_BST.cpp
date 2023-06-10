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

Node *emptyBST(Node *root)
{
    Node *temp;
    if (root != NULL)
    {
        //* Traverse to left
        emptyBST(root->left);
        //* Traverse to right
        emptyBST(root->right);
        cout << "\nReleased Node: " << root->val;
        temp = root;
        free(temp);
    }
    return root;
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
    cout << "BST before deleting:\n";
    inorder(root);
    root = emptyBST(root);
    return 0;
}