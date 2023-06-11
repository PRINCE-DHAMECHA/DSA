//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;

int count_subset_with_diff(vector<int> v, int w)
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
    vector<int> v = {1, 2, 4, 6, 8};
    int diff = 3;
    int total = accumulate(v.begin(), v.end(), 0);
    if ((diff + total) % 2 != 0)
    {
        cout << 0 << endl;
        return 0;
    }
    int sum = (total + diff) / 2; // s1-s2=diff and s1+s2=total
    cout << count_subset_with_diff(v, sum) << endl;
    return 0;
}