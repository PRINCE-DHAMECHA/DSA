//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;

string print_short_com_superseq(string a, string b)
{
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
    int i = a.size(), j = b.size();
    string s = "";
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            s.push_back(a[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (v[i - 1][j] > v[i][j - 1])
            {
                s.push_back(a[i - 1]);
                i--;
            }
            else
            {
                s.push_back(b[j - 1]);
                j--;
            }
        }
    }
    while (i > 0)
    {
        s.push_back(a[i - 1]);
        i--;
    }
    while (j > 0)
    {
        s.push_back(b[j - 1]);
        j--;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main()
{
    string a = "aggtab", b = "gxtxayb";
    cout << print_short_com_superseq(a, b) << endl;
    return 0;
}