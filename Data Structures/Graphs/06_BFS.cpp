//~ Breadth First Search
//* Analogy:- Army of soldiers spreading out to cover the area
//* Layer wise

//~ Which DS to use?
//* FIFO(Queue)

//~ How to avoid cycles?
//* keep track of node which is already visited

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)
typedef vector<int> vi;

void addEdge(vector<vi> &graph, int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

vi BFS(vector<vi> &graph, int start)
{
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    vi traversal;
    while (!q.empty())
    {
        int v = q.front();
        cout << v << " ";
        traversal.push_back(v);
        q.pop();
        for (auto i : graph[v])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    return traversal;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    int v = 7;
    vector<vi> graph(v, vi(v, 0));
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 6);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 6);
    vi t = BFS(graph, 0);
    cout << endl;
    for (auto i : t)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
