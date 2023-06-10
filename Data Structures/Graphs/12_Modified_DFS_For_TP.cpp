//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

void addEdge(vector<vector<int>> &graph, int u, int v)
{
    graph[u].emplace_back(v);
}

void topologicalSort(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &result, int node)
{
    visited[node] = true;
    for (auto i : graph[node])
    {
        if (!visited[i])
        {

            topologicalSort(graph, visited, result, i);
        }
    }
    result.push_back(node);
}

vector<int> topologicalSortWrapper(vector<vector<int>> &graph)
{
    vector<bool> visited(graph.size(), false);
    vector<int> result;
    for (int i = 0; i < graph.size(); ++i)
    {
        if (!visited[i])
        {
            topologicalSort(graph, visited, result, i);
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    int v = 5;
    vector<vector<int>> graph(v);
    vector<bool> visited(v, false);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    //!!! addEdge(graph, 2, 0); //! cycle will give wrong output
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);

    vector<int> result = topologicalSortWrapper(graph);
    cout << "Topological sort using DFS: " << endl;
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}