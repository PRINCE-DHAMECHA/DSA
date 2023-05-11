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

void inorder(Node *temp)
{
    if (!temp)
        return;
    inorder(temp->left);
    cout << temp->val << " ";
    inorder(temp->right);
}

//~ Given a binary tree, delete a node from it by making sure that the tree shrinks from the bottom (i.e. the deleted node is replaced by the bottom-most and rightmost node). This is different from BST deletion. Here we do not have any order among elements, so we replace them with the last element.

void deleteDeepest(Node *root, Node *d_node)
{
    queue<Node *> q;
    q.push(root);
    Node *temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp == d_node)
        {
            temp = NULL;
            delete (d_node);
            return;
        }
        if (temp->right)
        {
            if (temp->right == d_node)
            {
                temp->right = NULL;
                delete (d_node);
                return;
            }
            else
            {
                q.push(temp->right);
            }
        }

        if (temp->left)
        {
            if (temp->left == d_node)
            {
                temp->left = NULL;
                delete (d_node);
                return;
            }
            else
            {
                q.push(temp->left);
            }
        }
    }
}

Node *deletion(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        if (root->val == key)
        {
            // delete (root);
            return NULL;
        }
        else
        {
            return root;
        }
    }
    queue<Node *> q;
    q.push(root);
    Node *temp;
    Node *keyNode = NULL;

    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp->val == key)
        {
            keyNode = temp;
        }
        if (temp->left)
        {
            q.push(temp->left);
        }
        //!  Make sure to check for right after checking for left because we're considering last element as deepest node because it'll be rightmost deepest node
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
    //* If given key actually present
    if (keyNode != NULL)
    {
        //* Preserve rightmost deepest node's value
        int x = temp->val;
        //*  Delete It :(
        deleteDeepest(root, temp);
        //* Make value of key node equal to value of rightmost deepest node
        keyNode->val = x;
    }
    return root;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    Node *root = new Node(10);
    root->left = new Node(11);
    root->left->left = new Node(7);
    root->left->right = new Node(12);
    root->right = new Node(9);
    root->right->left = new Node(15);
    root->right->right = new Node(8);

    cout << "Inorder traversal before deletion: ";
    inorder(root);

    int key = 11;
    root = deletion(root, key);

    cout << endl;
    cout << "Inorder traversal after deletion: ";
    inorder(root);

    return 0;
}