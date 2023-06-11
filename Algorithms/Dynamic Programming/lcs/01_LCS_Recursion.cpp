//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;

int lcs(string a, string b, int n, int m)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if (a[n - 1] == b[m - 1])
    {
        return (1 + lcs(a, b, n - 1, m - 1));
    }
    return max(lcs(a, b, n - 1, m), lcs(a, b, n, m - 1));
}

int main()
{
    string a = "abcdef", b = "aecdcf";
    cout << lcs(a, b, a.size(), b.size()) << endl;
    return 0;
}