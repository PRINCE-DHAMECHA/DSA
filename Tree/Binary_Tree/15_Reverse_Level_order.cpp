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

//~Approach: Reverse Level Order Binary Tree Traversal using Recursion O(n^2)
//* We use same approach as we used for simple Level Order Traversal, But instead of starting at level 1 we start from h to all the way down to 1.
int height(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        int lHeight = height(node->left);
        int rHeight = height(node->right);
        //* increasing count by one because we're adding current node in height
        //* choose maximum height subtree as per definition of height
        return (lHeight > rHeight ? lHeight : rHeight) + 1;
    }
}

void printCurrentLevel(Node *root, int level)
{
    if (root == NULL)
    {
        return;
    }
    else if (level == 1)
    {
        cout << root->val << " ";
    }
    else if (level > 1)
    {
        //* Went down recursively for level times to reach currentLevel because we're always starting from root
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

void printLevelOrderRec(Node *root)
{
    int h = height(root);
    //* h to 1
    for (int i = h; i >= 1; i--)
    {
        printCurrentLevel(root, i);
    }
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Level Order traversal of binary tree is \n";
    cout << "Using Recursion: ";
    printLevelOrderRec(root);

    return 0;
}