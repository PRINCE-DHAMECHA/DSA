#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> MEM(1000, vector<int>(1000, -1));

int knapsack(int n, int w, vector<int> p, vector<int> wt)
{
    if (MEM[n][w] != -1)
    {
        return MEM[n][w];
    }
    if (n == 0 || w == 0)
    {
        return MEM[n][w] = 0;
    }
    if (wt[n - 1] <= w)
    {
        return MEM[n][w] = max(p[n - 1] + knapsack(n - 1, w - wt[n - 1], p, wt), knapsack(n - 1, w, p, wt));
    }
    else
    {
        return MEM[n][w] = knapsack(n - 1, w, p, wt);
    }
}

int main()
{
    int n = 4, w = 5;
    vector<int> wt = {5, 3, 2, 1};
    vector<int> p = {9, 7, 3, 2};
    vector<vector<int>> v(n + 1, vector<int>(w + 1, 0));
    cout << knapsack(n, w, p, wt) << endl; // one item will not included more than one time
    return 0;
}