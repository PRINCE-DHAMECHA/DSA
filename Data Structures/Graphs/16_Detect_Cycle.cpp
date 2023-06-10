//~ Detect Cycle

//* Create set for each vertex
//* Process each edge and union it's vertices
//* If find on this vertices returns same parent then cycle is present

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

void makeSet(vector<int> &parent)
{
    for (int i = 0; i < parent.size(); i++)
    {
        parent[i] = i;
    }
}

int find(vector<int> &parent, int x)
{
    if (x != parent[x])
    {
        parent[x] = find(parent, parent[x]);
    }
    return parent[x];
}

void unionSet(vector<int> &parent, vector<int> &rank, int x, int y)
{
    int rootX = find(parent, x);
    int rootY = find(parent, y);
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

bool isCyclePresent(vector<pair<int, int>> &allEdges, int size)
{
    vector<int> parent(size);
    vector<int> rank(size, 0);

    makeSet(parent);

    for (int i = 0; i < allEdges.size(); i++)
    {
        int rootX = find(parent, allEdges[i].first);
        int rootY = find(parent, allEdges[i].second);
        if (rootX == rootY)
        {
            return true;
        }
        else
        {
            unionSet(parent, rank, rootX, rootY);
        }
    }
    return false;
}

void addEdge(vector<vector<int>> &graph, vector<pair<int, int>> &allEdges, int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
    allEdges.push_back({u, v});
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    int v = 6;
    vector<vector<int>> graph(v);
    vector<pair<int, int>> allEdges;
    addEdge(graph, allEdges, 0, 1);
    addEdge(graph, allEdges, 0, 2);
    addEdge(graph, allEdges, 1, 3);
    addEdge(graph, allEdges, 2, 3);
    addEdge(graph, allEdges, 3, 4);
    addEdge(graph, allEdges, 4, 5);
    bool isCycle = isCyclePresent(allEdges, v);
    if (isCycle)
    {
        cout << "Cycle Detected" << endl;
    }
    else
    {
        cout << "Cycle Not Exists" << endl;
    }
    return 0;
}