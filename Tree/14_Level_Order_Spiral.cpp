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

//~ Approach: Recursion O(n^2)
//* The idea is to first calculate the height of the tree, then recursively traverse each level and print the level order traversal according to the current level.

int height(Node *root)
{
    queue<Node *> q;
    q.push(root);

    int height = 0;

    while (!q.empty())
    {
        //* Instead adding NULL to separate element we first take size and process all that element with adding their children
        //* We already remembering size so we'll take out that size and add all it's children and after each iteration we increase height by one
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
        height++;
    }
    return height;
}

void printGivenLevel(Node *root, int level, int ltr)
{
    if (root == NULL)
    {
        return;
    }
    //* Same approach as discussed in previous question, We recursively reach to currentLevel because we start from level=n and decreasing level by 1 so when level=1 will reach to desired level with all it's element
    if (level == 1)
    {
        cout << root->val << " ";
    }
    else if (level > 1)
    {
        if (ltr)
        {
            //! Don't change ltr(left to right)
            printGivenLevel(root->left, level - 1, ltr);
            printGivenLevel(root->right, level - 1, ltr);
        }
        else
        {
            //* ltr is false that means we need to print in backward direction i.e. right to left
            printGivenLevel(root->right, level - 1, ltr);
            printGivenLevel(root->left, level - 1, ltr);
        }
    }
}

void printSpiral(Node *root)
{
    int h = height(root);
    bool ltr = false;
    for (auto i = 1; i <= h; i++)
    {
        printGivenLevel(root, i, ltr);
        ltr = !ltr;
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
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    printf("Spiral Order traversal of "
           "binary tree is \n");

    printSpiral(root);

    return 0;
}