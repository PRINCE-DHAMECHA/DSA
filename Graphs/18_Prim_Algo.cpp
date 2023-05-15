//~ Prim's Algo
//* Greedy

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

void addEdge(vector<vector<pair<int, int>>> &graph,
             int u, int v, int w)
{
    graph[u].push_back(make_pair(v, w));
    graph[v].push_back(make_pair(u, w));
}

vector<tuple<int, int, int>> prim(vector<vector<pair<int, int>>> &graph, int start)
{
    vector<int> parent(graph.size(), -1);
    vector<int> key(graph.size(), INT_MAX);
    vector<bool> inMST(graph.size(), false);
    key[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));
    vector<tuple<int, int, int>> res;
    while (!pq.empty())
    {
        int v = pq.top().second;
        pq.pop();
        if (parent[v] != -1 && inMST[v] == false)
        {
            res.push_back(make_tuple(parent[v], v, key[v]));
        }
        inMST[v] = true;
        cout << v << endl;
        for (auto x : graph[v])
        {
            int av = x.first;
            int weight = x.second;
            if (inMST[av] == false && key[av] > weight)
            {
                parent[av] = v;
                key[av] = weight;
                pq.push({key[av], av});
            }
        }
    }
    return res;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    int V = 7;
    // pair of vertex, weight
    vector<vector<pair<int, int>>> graph(V, vector<pair<int, int>>(V));

    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 3, 7);
    addEdge(graph, 0, 5, 2);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 3, 4);
    addEdge(graph, 1, 4, 3);
    addEdge(graph, 1, 5, 5);
    addEdge(graph, 2, 4, 4);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 1);
    addEdge(graph, 3, 6, 5);
    addEdge(graph, 4, 6, 7);

    vector<tuple<int, int, int>> res = prim(graph, 0);
    cout << "Minimum Spanning Tree: " << endl;
    for (tuple<int, int, int> t : res)
    {
        cout << get<0>(t) << "-" << get<1>(t) << "," << get<2>(t) << endl;
    }
    return 0;
}