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
    // vector<int> v = {2, 8, 11};
    // vector<int> v = {2, 8, 5, 11};
    vector<int> v = {2, 3, 5, 11};
    int w = 0;
    for (auto i : v)
    {
        w += i;
    }
    if (w % 2 != 0)
    {
        cout << 0 << endl;
        return 0;
    }
    cout << subset_sum(v, w / 2);
    return 0;
}