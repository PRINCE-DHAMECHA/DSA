//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;

int maximum_way(vector<int> v, int w)
{
    vector<vector<int>> sol(v.size() + 1, vector<int>(w + 1, 0));
    for (int i = 0; i <= v.size(); i++)
    {
        sol[i][0] = 1;
    }
    for (int i = 1; i <= v.size(); i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (v[i - 1] <= j)
            {
                sol[i][j] = sol[i][j - v[i - 1]] + sol[i - 1][j];
            }
            else
            {
                sol[i][j] = sol[i - 1][j];
            }
        }
    }
    for (int i = 0; i <= v.size(); i++)
    {
        for (int j = 0; j <= w; j++)
        {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
    return sol[v.size()][w];
}

int main()
{
    vector<int> v = {1, 3, 4};
    int total = 7;
    cout << maximum_way(v, total);
    return 0;
}