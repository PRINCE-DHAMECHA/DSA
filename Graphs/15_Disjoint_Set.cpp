//~ Disjoint Set
//* DS that categorizes object into different sets and gives the ability to check if two objects belongs to the same set.
//* Also called DSU (Disjoint Set Union) or Union-Find

//~ Union Find Interface

//& union_set(x,y)
//* Merges the two specified sets (set that contains element x and set that contains element y)

//& Find(x)
//* returns the representative of the set that contains the element x
//* if find(x1)==find(x2) => x1 and x2 are in same set

//& make_set(x)
//* Creates a new set consisting of the new element x

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

void makeSet(vector<int> &parent, int x)
{
    parent[x] = x;
}

int find(vector<int> &parent, int x)
{
    if (x != parent[x])
    {
        return find(parent, parent[x]);
    }
    return parent[x];
}

void unionSet(vector<int> &parent, int x, int y)
{
    //* Finding parent of both
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    if (rootX == rootY)
    {
        return;
    }
    //* setting later node as parent
    parent[rootX] = rootY;
}

//~ Optimization-1 : Path compression
//* Here we are flattening given tree such that when we call find all nodes which we encounter will then be child to root

int findOpt(vector<int> &parent, int x)
{
    if (x != parent[x])
    {
        parent[x] = find(parent, parent[x]);
    }
    return parent[x];
}

//~ Optimization-2 : Union By Rank
//* Attaches the shorter tree to the root of the taller tree
//? Why this is optimal?
//* Because if we attach smaller to root of taller than height of taller will not increase but in vice versa hight of smaller will increase and can exceed to height of taller by one
//* Ex taller:- 5 smaller:-
//* smaller->taller :- 5 (max(5,1+4))
//* taller->smaller :- 6 (1+5)

void unionSetOpt(vector<int> &parent, vector<int> &rank, int x, int y)
{
    int rootX = findOpt(parent, x);
    int rootY = findOpt(parent, y);
    if (rootX == rootY)
    {
        return;
    }
    if (rank[rootX] > rank[rootY])
    {
        parent[rootY] = rootX;
    }
    else
    {
        parent[rootX] = rootY;
        if (rank[rootX] == rank[rootY])
        {
            rank[rootY]++;
        }
    }
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    int v = 10;
    vector<int> parent(v);
    vector<int> rank(v);
    for (int i = 0; i < v; i++)
    {
        makeSet(parent, i);
    }
    unionSet(parent, 2, 1);
    unionSet(parent, 4, 3);
    unionSet(parent, 8, 4);
    unionSet(parent, 9, 3);
    unionSet(parent, 6, 5);
    cout << find(parent, 4) << " " << find(parent, 8) << endl;
    cout << find(parent, 4) << " " << find(parent, 5) << endl;

    return 0;
}