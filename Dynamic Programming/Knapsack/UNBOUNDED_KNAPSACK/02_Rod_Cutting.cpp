//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // same as unbound knapsack
    int n = 3, total_length = 6;
    vector<int> length = {1, 2, 3};
    vector<int> price = {10, 15, 40};
    vector<vector<int>> v(n + 1, vector<int>(total_length + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= total_length; j++)
        {
            if (length[i - 1] <= j)
                v[i][j] = max(price[i - 1] + v[i][j - length[i - 1]], v[i - 1][j]);
            else
                v[i][j] = v[i - 1][j];
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= total_length; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Total maximum profit after cutting rod: " << endl;
    cout << v[n][total_length] << endl;
    return 0;
}