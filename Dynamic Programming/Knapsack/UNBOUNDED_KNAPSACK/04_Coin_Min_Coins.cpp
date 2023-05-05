//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;

int max_way(vector<int> v, int w)
{
    vector<vector<int>> sol(v.size() + 1, vector<int>(w + 1, 0));
    for (int i = 0; i <= v.size(); ++i)
    {
        sol[i][0] = 0;
    }
    for (int i = 0; i <= w; ++i)
    {
        sol[0][i] = 9999;
    }
    for (int i = 1; i <= w; ++i)
    {
        if (i % v[0] == 0)
        {
            sol[1][i] = i / v[0];
        }
        else
        {
            sol[1][i] = 9999;
        }
    }
    for (int i = 2; i <= v.size(); ++i)
    {
        for (int j = 1; j <= w; ++j)
        {
            if (v[i - 1] <= j)
            {
                sol[i][j] = min(1 + sol[i][j - v[i - 1]], sol[i - 1][j]);
            }
            else
            {
                sol[i][j] = sol[i - 1][j];
            }
        }
    }
    for (int i = 0; i <= v.size(); ++i)
    {
        for (int j = 0; j <= w; ++j)
        {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
    return sol[v.size()][w];
}

int main()
{
    vector<int> v = {1, 3, 18};
    int w = 23;
    cout << max_way(v, w) << endl;
    return 0;
}