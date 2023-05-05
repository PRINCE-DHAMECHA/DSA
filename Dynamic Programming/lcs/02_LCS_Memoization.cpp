//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v(1000, vector<int>(1000, -1));

int lcs(string a, string b, int n, int m)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if (v[n][m] != -1)
    {
        return v[n][m];
    }
    if (a[n - 1] == b[m - 1])
    {
        return v[n][m] = (1 + lcs(a, b, n - 1, m - 1));
    }
    return v[n][m] = max(lcs(a, b, n - 1, m), lcs(a, b, n, m - 1));
}

int main()
{
    string a = "LAGRANGE", b = "LAPLACE";
    cout << lcs(a, b, a.size(), b.size()) << endl;
    return 0;
}