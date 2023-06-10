//~ Bellman Ford

//* Single source shortest path
//* Works on negative edges too
//* DP
//* Relaxation

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

bool bellmanFord(map<pair<int, int>, int> &edges, int start, int V, vector<int> &dist)
{
    for (int i = 0; i < V; i++)
    {
        for (auto e : edges)
        {
            int u = e.first.first;
            int v = e.first.second;
            int weight = e.second;
            if (dist[u] != INT_MAX && (dist[v] > dist[u] + weight))
            {
                dist[v] = dist[u] + weight;
            }
        }
    }
    for (auto e : edges)
    {
        int u = e.first.first;
        int v = e.first.second;
        int weight = e.second;
        if (dist[u] != INT_MAX && (dist[v] > dist[u] + weight))
        {
            return false;
        }
    }
    return true;
}

void addEdge(map<pair<int, int>, int> &edges,
             int u, int v, int w)
{
    edges[make_pair(u, v)] = w;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    int V = 5;
    map<pair<int, int>, int> edges;

    addEdge(edges, 0, 1, 4);
    addEdge(edges, 0, 2, 2);
    addEdge(edges, 1, 3, 2);
    addEdge(edges, 1, 4, 3);
    addEdge(edges, 1, 2, 3);
    addEdge(edges, 2, 1, 1);
    addEdge(edges, 2, 4, 5);
    addEdge(edges, 2, 3, 4);
    addEdge(edges, 4, 3, -5);

    vector<int> dist(V, INT_MAX);
    int start = 0;
    dist[start] = 0;
    bool res = bellmanFord(edges, start, V, dist);
    if (!res)
        cout << "Negative-weight cycle exists" << endl;
    else
    {
        cout << "Shortest path distance from start vertex (" << start << ")" << endl;
        for (int i = 0; i < V; i++)
        {
            cout << start << "-" << i << " : " << dist[i] << endl;
        }
    }
    return 0;
}