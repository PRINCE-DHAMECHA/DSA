//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;

int lcs(string a, string b)
{
    vector<vector<int>> v(a.size() + 1, vector<int>(b.size() + 1, 0));
    int res = 0;
    for (int i = 1; i <= a.size(); ++i)
    {
        for (int j = 1; j <= b.size(); ++j)
        {
            if (a[i - 1] == b[j - 1])
            {
                v[i][j] = 1 + v[i - 1][j - 1];
                res = max(res, v[i][j]);
            }
            else
            {
                v[i][j] = 0;
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
    return res;
}

int main()
{
    string a = "abcdeffg", b = "edgehdeffd";
    cout << lcs(a, b) << endl;
    return 0;
}