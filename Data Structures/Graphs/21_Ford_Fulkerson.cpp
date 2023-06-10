//~ Ford Fulkerson O(VE^2)

//* Maximum Flow Problem

//! Flow<=capacity
//! Incoming==Outgoing (Except for source and sink)

//~ Residual Capacity:
//* It is the capacity of the edges after subtracting the flow from the maximum capacity

//~ Residual Graph:
//* A graph with the same vertices and same edges but we use the residual capacities as capacities.

//~ Augmenting Path:
//* Simple path in residual graph, i.e. Along the edges whose residual capacity is positive.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//* Find Augmented Path
int BFS(int source, int sink, vector<int> &parent, vector<vector<int>> &residualGraph)
{
    fill(parent.begin(), parent.end(), -1);
    int V = residualGraph.size();
    parent[source] = -2;
    queue<pair<int, int>> q;
    q.push({source, INT_MAX});
    while (!q.empty())
    {
        int u = q.front().first;
        int capacity = q.front().second;
        q.pop();
        for (int av = 0; av < V; av++)
        {
            if (u != av && parent[av] == -1 && residualGraph[u][av] != 0)
            {
                //* Save parent for updating weights
                parent[av] = u;
                int minCap = min(capacity, residualGraph[u][av]);
                if (av == sink)
                {
                    return minCap;
                }
                q.push({av, minCap});
            }
        }
    }
    return 0;
}

int fordFulkerson(vector<vector<int>> &graph, int source, int sink)
{
    vector<int> parent(graph.size(), -1);
    vector<vector<int>> residualgraph = graph;
    int minCap = 0, maxFlow = 0;
    //* While augmented path
    while (minCap = BFS(source, sink, parent, residualgraph))
    {
        maxFlow += minCap;
        int u = sink;
        while (u != source)
        {
            int v = parent[u];
            //* update residual graph
            residualgraph[u][v] += minCap;
            residualgraph[v][u] -= minCap;
            //* For reaching source
            u = v;
        }
    }
    return maxFlow;
}

void addEdge(vector<vector<int>> &graph,
             int u, int v, int w)
{
    graph[u][v] = w;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    int V = 6;
    vector<vector<int>> graph(V, vector<int>(V, 0));

    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 3, 3);
    addEdge(graph, 1, 2, 4);
    addEdge(graph, 2, 3, 3);
    addEdge(graph, 2, 5, 2);
    addEdge(graph, 3, 4, 6);
    addEdge(graph, 4, 5, 6);

    cout << "Maximum Flow: " << fordFulkerson(graph, 0, 5) << endl;
    return 0;
}