//~ Breadth First Search
//* Goes as far as it can give path, Then backtracks until it finds an unexplored path

//~ Which DS to use?
//* LIFO(Stack)

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

vi DFSIterative(vector<vi> &graph, int start)
{
    stack<int> s;
    s.push(start);
    vector<bool> visited(graph.size());
    vi traversal;
    while (!s.empty())
    {
        int top = s.top();
        s.pop();
        visited[top] = true;
        cout << top << " ";
        traversal.push_back(top);
        for (auto i : graph[top])
        {
            if (!visited[i])
            {
                visited[i] = true;
                s.push(i);
            }
        }
    }
    return traversal;
}

vector<bool> visitedRec(100, false);

void DFS(vector<vi> &graph, vector<bool> &visited, int node)
{
    visited[node] = true;
    cout << node << " ";
    for (auto i : graph[node])
    {
        if (!visited[i])
        {
            DFS(graph, visited, i);
        }
    }
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
    vi t = DFSIterative(graph, 0);
    cout << endl;
    for (auto i : t)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<bool> visited(7, false);
    //* Not necessarily same as above
    DFS(graph, visited, 0);
    return 0;
}
