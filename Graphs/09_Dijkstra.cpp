//~ Dijkstra's Algorithm for shortest path

//* Shortest possible path from the source has to come from one of the shortest paths already discovered

//* Pros:- Fast and simple
//* Cons:- Need to store large parts of the graph in-memory and also fails for negative edges

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

void addEdge(vector<vector<pair<int, int>>> &graph, int u, int v, int w)
{
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
}

vector<int> Dijkstra(vector<vector<pair<int, int>>> &graph, int start)
{
    vector<int> dist(graph.size(), INT_MAX);
    //* For avoiding linear search to find min dist node we can use priority queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({start, 0});
    dist[start] = 0;
    while (!pq.empty())
    {
        int u = pq.top().first;
        pq.pop();
        for (auto i : graph[u])
        {
            int v = i.first;
            int weight = i.second;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push({v, dist[v]});
            }
        }
    }
    return dist;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    int v = 9;
    vector<vector<pair<int, int>>> graph(v);
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);
    vector<int> dist = Dijkstra(graph, 0);
    for (auto i : dist)
    {
        cout << i << " ";
    }
    return 0;
}
