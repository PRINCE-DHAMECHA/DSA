//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;

bool subset_sum(vector<int> v, int w)
{
    vector<vector<bool>> sol(v.size() + 1, vector<bool>(w + 1, false));
    for (int i = 0; i <= v.size(); ++i)
    {
        sol[i][0] = true;
    }
    for (int i = 1; i <= v.size(); ++i)
    {
        for (int j = 1; j <= w; ++j)
        {
            if (v[i - 1] <= j)
            {
                sol[i][j] = sol[i - 1][j - v[i - 1]] || sol[i - 1][j];
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
    vector<int> v = {2, 4, 8, 10, 3, 7};
    int w = 34;
    cout << subset_sum(v, w) << endl;
    return 0;
}