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

vector<int> topologicalSort(vector<vector<int>> &graph, int size)
{
    vector<int> res;
    queue<int> q;
    vector<int> inDegree(size, 0);
    for (auto i : graph)
    {
        for (auto j : i)
        {
            inDegree[j]++;
        }
    }
    for (auto i = 0; i < inDegree.size(); i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        res.push_back(v);
        for (auto i : graph[v])
        {
            inDegree[i]--;
            //* indegree will never be <0 because if it will <0 then there's node more than our calculated indegreee
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }
    }
    return res;
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
    //! addEdge(graph, 2, 0); // cycle will not give topological sort
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);

    vector<int> result = topologicalSort(graph, v);
    //* If topological sort not exists then
    if (result.size() != v)
    {

        cout << "Topological sort not possible" << endl;
    }
    else
    {
        cout << "Topological sort using Kahn's algorithm: " << endl;
        for (int i : result)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}