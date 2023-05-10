//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~  Case 1: (0—n-1)
// if (say)father=p;
// then left_son=(2*p)+1;
// and right_son=(2*p)+2;

//~  Case 1: (1—n)
// if (say)father=p;
// then left_son=(2*p);
// and right_son=(2*p)+1;

char tree[10];

void root(char key)
{
    if (tree[0] != '\0')
    {
        cout << "Already had a root" << endl;
    }
    else
    {
        tree[0] = key;
    }
}

void setLeft(char key, int parent)
{
    if (tree[parent] == '\0')
    {
        cout << "Can't set child at" << (parent * 2) + 1 << ", No parent found" << endl;
    }
    else
    {
        tree[(2 * parent) + 1] = key;
    }
}
void setRight(char key, int parent)
{
    if (tree[parent] == '\0')
    {
        cout << "Can't set child at" << (parent * 2) + 2 << ", No parent found" << endl;
    }
    else
    {
        tree[(2 * parent) + 2] = key;
    }
}

int printTree()
{
    cout << "\n";
    for (int i = 0; i < 10; i++)
    {
        if (tree[i] != '\0')
            cout << tree[i];
        else
            cout << "-";
    }
    return 0;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    root('A');
    setLeft('B', 0);
    setRight('C', 0);
    setLeft('D', 1);
    setRight('E', 1);
    setRight('F', 2);
    printTree();
    return 0;
}