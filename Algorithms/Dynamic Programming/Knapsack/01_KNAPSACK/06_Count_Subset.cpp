//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;

int count_subset(vector<int> v, int w)
{
    vector<vector<int>> sol(v.size() + 1, vector<int>(w + 1, 0));
    for (int i = 0; i <= v.size(); ++i)
    {
        sol[i][0] = 1;
    }
    for (int i = 1; i <= v.size(); ++i)
    {
        for (int j = 1; j <= w; ++j)
        {
            if (v[i - 1] <= j)
            {
                sol[i][j] = sol[i - 1][j - v[i - 1]] + sol[i - 1][j];
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
    vector<int> v = {1, 2, 3, 5, 7, 8, 9, 10};
    int w = 10;
    cout << count_subset(v, w) << endl;
    return 0;
}