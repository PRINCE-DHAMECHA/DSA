//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;

int min_dlt_pal_sequence(string a)
{
    string b = a;
    reverse(a.begin(), a.end());
    vector<vector<int>> v(a.size() + 1, vector<int>(b.size() + 1, 0));
    for (int i = 1; i <= a.size(); ++i)
    {
        for (int j = 1; j <= b.size(); ++j)
        {
            if (a[i - 1] == b[j - 1])
            {
                v[i][j] = 1 + v[i - 1][j - 1];
            }
            else
            {
                v[i][j] = max(v[i - 1][j], v[i][j - 1]);
            }
        }
    }
    for (int i = 0; i <= a.size(); ++i)
    {
        for (int j = 0; j <= b.size(); ++j)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return b.size() - v[a.size()][b.size()];
}

int main()
{
    string a = "aghbcfba";
    cout << min_dlt_pal_sequence(a) << endl; // abcba
    return 0;
}