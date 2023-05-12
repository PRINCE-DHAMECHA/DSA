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

//~ Different scenarios for deleting the node:

//* Node to be deleted is the leaf node : Its simple you can just null it out.
//* Node to be deleted has one child : You can just replace the node with the child node.

//& Node to be deleted has two child :
//* Need to figure out what will be the replacement of the node to be deleted.
//* Want minimal disruption to the existing tree structure
//* Can table the replacement node from the deleted nodes left or right subtree.
//* If taking if from the left subtree, we have to take the largest value in the left subtree.
//* If taking if from the right subtree, we have to take the smallest value in the right subtree.
//* Choose one approach and stick to it.

//* inorder successor
Node *minValNode(Node *node)
{
    Node *curr = node;
    while (curr != NULL && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

Node *deleteNode(Node *root, int key)
{
    //* key doesn't exist
    if (root == NULL)
    {
        return root;
    }
    if (key < root->val)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->val)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        //* If only one child or no child
        //* in case of no child temp will be null!!
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *temp = minValNode(root->right);
        cout << temp->val << endl;
        root->val = temp->val;
        //* We recursively delete inorder successor because successor will be always left child of it's parent but it can have right
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

//! Problem: Recursive deleting successor is not efficient

//~ Approach-2 :- Since successor is always left child of its parent we can safely make successor's right child as left of its parent.

//* If there is no succ, then assign succ->right to succParent->right

Node *deleteNodeEff(Node *root, int key)
{
    //* key doesn't exist
    if (root == NULL)
    {
        return root;
    }
    if (key < root->val)
    {
        root->left = deleteNode(root->left, key);
        return root;
    }
    else if (key > root->val)
    {
        root->right = deleteNode(root->right, key);
        return root;
    }
    else
    {
        //* If only one child or no child
        //* in case of no child temp will be null!!
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            Node *succParent = root;
            Node *succ = root->right;
            while (succ->left != NULL)
            {
                succParent = succ;
                succ = succ->left;
            }
            if (succParent != root)
            {
                succParent->left = succ->right;
            }
            else
            {
                succParent->right = succ->right;
            }
            root->val = succ->val;
            delete succ;
            return root;
        }
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

    inorder(root);
    cout << endl;
    root = deleteNode(root, 50);
    inorder(root);
    return 0;
}