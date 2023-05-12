//~ Adjacency List:
//* An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a vertex in the graph.
//* Size = # vertices

//* For adding weight we'll use pairs

//~ Advantages
//* Space:- O(V+E)
//* Adding an edge is efficient

//~ Disadvantages
//* Finding edge exist or not is not efficient O(V)
//* Time taken to remove an edge is O(E)
//* Time taken to remove vertex is O(V+E)

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
}

void addWeightedEdge(vector<vector<pair<int, int>>> &graph, int u, int v, int w)
{
    graph[u].push_back({v, w});
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    int v = 5;
    vector<vi> graph(v); //? Change int to pair to store weight
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 3, 2);
    addEdge(graph, 3, 4);
    cout << "Adjacency List: " << endl;
    for (int i = 0; i < v; i++)
    {
        cout << i;
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << " -> " << graph[i][j] << " ";
        }
        cout << endl;
    }

    vector<vector<pair<int, int>>> wGraph(v); //? Change int to pair to store weight
    addWeightedEdge(wGraph, 0, 1, 3);
    addWeightedEdge(wGraph, 0, 4, 2);
    addWeightedEdge(wGraph, 1, 1, 4);
    addWeightedEdge(wGraph, 1, 2, 1);
    addWeightedEdge(wGraph, 1, 3, 6);
    addWeightedEdge(wGraph, 1, 4, 8);
    addWeightedEdge(wGraph, 3, 2, 3);
    addWeightedEdge(wGraph, 3, 4, 5);
    cout << "Adjacency List: " << endl;
    for (int i = 0; i < v; i++)
    {
        cout << i;
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << " -> "
                 << "( " << wGraph[i][j].first << ", " << wGraph[i][j].second << " )"
                 << " ";
        }
        cout << endl;
    }

    return 0;
}
