//~ Incidence List
//* A list which stores for each vertex a list of objects representing the edges incident to that vertex

//* if A->B
//  A->E1
//! We can't make graph from this

//* We need to store extra info
// A->(E1,B)

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

typedef vector<int> vi;

void addEdge(vector<vector<pair<int, int>>> &graph, int u, int v, int e)
{
    graph[u].emplace_back(make_pair(e, v));
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    int v = 5, e = 8;
    vector<vector<pair<int, int>>> graph(v);
    addEdge(graph, 0, 1, 0);
    addEdge(graph, 0, 4, 1);
    addEdge(graph, 1, 4, 2);
    addEdge(graph, 1, 3, 3);
    addEdge(graph, 1, 1, 5);
    addEdge(graph, 1, 2, 6);
    addEdge(graph, 3, 4, 4);
    addEdge(graph, 3, 2, 7);

    cout << "Incidence list:" << endl;
    for (int i = 0; i < v; i++)
    {
        cout << i;
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << " --> ( " << graph[i][j].first << "," << graph[i][j].second << " )";
        }
        cout << endl;
    }

    return 0;
}