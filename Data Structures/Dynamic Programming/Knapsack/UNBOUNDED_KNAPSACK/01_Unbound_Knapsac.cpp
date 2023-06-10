//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 3, w = 8;
    vector<int> wt = {1, 2, 3};
    vector<int> p = {10, 15, 40};
    vector<vector<int>> v(n + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= w; ++j)
        {
            if (wt[i - 1] <= j)
                v[i][j] = max(p[i - 1] + v[i][j - wt[i - 1]], v[i - 1][j]);
            else
                v[i][j] = v[i - 1][j];
        }
    }
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= w; ++j)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << v[n][w] << endl;
    return 0;
}