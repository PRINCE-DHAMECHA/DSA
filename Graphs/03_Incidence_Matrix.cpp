//~ Incidence Matrix
//* A matrix where each column  represents an edge connected to two vertices
//* VxE matrix

//* if edge between A - B and A - C
//   E1 E2
// A 1  1
// B 1  0
// C 0  1
// D 0  0
// E 0  0

//* For weight we add weight instead of 1

//* undirected graph we add -1

//* if edge between A -> B and A -> C
//   E1 E2
// A  1  1
// B -1  0
// C  0 -1
// D  0  0
// E  0  0

//~ Disadvantages
//* space:- O(VE)
//* find out related node is O(E)
//* finding adjacent nodes is O(E)

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

typedef vector<int> vi;

void addEdge(vector<vi> &graph, int u, int v, int e)
{
    graph[u][e] = 1;
    if (u != v)
    {
        graph[v][e] = -1;
    }
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    int v = 5, e = 8;
    vector<vi> graph(v, vi(e, 0));
    addEdge(graph, 0, 1, 0);
    addEdge(graph, 0, 4, 1);
    addEdge(graph, 1, 4, 2);
    addEdge(graph, 1, 3, 3);
    addEdge(graph, 1, 1, 5);
    addEdge(graph, 1, 2, 6);
    addEdge(graph, 3, 4, 4);
    addEdge(graph, 3, 2, 7);

    cout << "Incidence matrix:" << endl;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < e; j++)
            cout << setw(2) << graph[i][j] << "   ";
        cout << endl;
    }

    return 0;
}