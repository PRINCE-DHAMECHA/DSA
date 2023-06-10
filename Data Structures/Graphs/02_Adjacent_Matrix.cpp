//~ Adjacency Matrix

//* 2D Matrix with VxV size where A[V][U] = 0 or 1 // 0-> No edge // 1-> Edge exists
//* For weighted graph we put weight instead of 1

//~ Advantages
//* Easy to understand and implement
//* O(1) for adding and removing edges
//* Query to find out edge exists or not is easy and efficient

//~ Disadvantages
//* More space for sparse graph O(V^2)
//* Adding vertex is not efficient

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)
typedef vector<int> vi;

void addEdge(vector<vi> &graph, int u, int v, int weight = 1) //* In case of weight
{
    graph[u][v] = weight;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    int v = 5;
    vector<vi> graph(v, vi(v, 0));
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 3, 2);
    addEdge(graph, 3, 4);
    cout << "Adjacency Matrix: " << endl;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
