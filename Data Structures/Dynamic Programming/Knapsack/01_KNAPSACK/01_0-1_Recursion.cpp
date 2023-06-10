//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, int w, vector<int> p, vector<int> wt)
{
    if (n == 0 || w == 0)
    {
        return 0;
    }
    if (wt[n - 1] <= w)
    {
        return max(p[n - 1] + knapsack(n - 1, w - wt[n - 1], p, wt), knapsack(n - 1, w, p, wt));
    }
    else
    {
        return knapsack(n - 1, w, p, wt);
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