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

//~Approach1: Level Order Binary Tree Traversal using Recursion:
//* Print the level order traversal of the tree using recursive function to traverse all nodes of a level. Find height of tree and run depth first search and maintain current height, print nodes for every height from root and for 1 to height and match if the current height is equal to height of the iteration then print node’s data.

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
        // Went down recursively for level times to reach currentLevel because we're always starting from root
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

void printLevelOrderRec(Node *root)
{
    int h = height(root);
    for (int i = 1; i <= h; i++)
    {
        printCurrentLevel(root, i);
    }
}

//~Approach2: Using Q
//* For each node, first, the node is visited and then it’s child nodes are put in a FIFO queue. Then again the first node is popped out and then it’s child nodes are put in a FIFO queue and repeat until queue becomes empty.

void printLevelOrderQueue(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        Node *node = q.front();
        cout << node->val << " ";
        q.pop();
        if (node->left != NULL)
        {
            q.push(node->left);
        }
        if (node->right != NULL)
        {
            q.push(node->right);
        }
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
    cout << endl;
    cout << "Using Queue: ";
    printLevelOrderQueue(root);

    return 0;
}