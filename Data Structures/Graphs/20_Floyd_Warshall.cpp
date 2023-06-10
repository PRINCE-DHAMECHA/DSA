//~ Floyd Warshall

//* All pairs shortest path

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

void floydWarshall(vector<vector<int>> &dist, const int V)
{
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

void addEdge(vector<vector<int>> &dist,
             int u, int v, int w)
{
    dist[u][v] = w;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    int V = 5;
    vector<vector<int>> dist(V, vector<int>(V, INT_MAX));

    addEdge(dist, 0, 1, 3);
    addEdge(dist, 0, 4, -4);
    addEdge(dist, 0, 2, 8);
    addEdge(dist, 1, 3, 1);
    addEdge(dist, 1, 4, 7);
    addEdge(dist, 2, 1, 4);
    addEdge(dist, 3, 0, 2);
    addEdge(dist, 3, 2, -5);
    addEdge(dist, 4, 3, 6);
    for (int i = 0; i < V; i++)
        dist[i][i] = 0;

    floydWarshall(dist, V);
    cout << "Shortest distance between all pairs: " << endl;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {

            cout << i << "," << j << " : " << dist[i][j] << endl;
        }
        cout << endl;
    }
    return 0;
}