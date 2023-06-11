//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef float flt;
typedef string str;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<lli, lli> plli;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vii;
typedef vector<vll> vvll;
typedef vector<vb> vvb;
typedef set<int> seti;
typedef set<ll> setl;
typedef set<pii> setpii;
typedef set<pll> setpll;
typedef vector<seti> vseti;
typedef vector<setl> vsetl;
typedef map<int, int> mpii;
typedef map<ll, ll> mpll;
typedef map<str, int> masi;
typedef map<int, str> mais;
const double pi = 3.1415926535897932384626433832795;
#define gcd(a, b) __gcd(a, b)
#define all(element) element.begin(), element.end()
#define sortv(v) sort(all(v))
#define rsortv(v) sort(all(v), greater<int>())
#define pp pop_back
#define pb push_back
#define maxi(a, b) max(a, b)
#define mini(a, b) min(a, b)
#define maxii(a, b, c) max({a, b, c})
#define minii(a, b, c) min({a, b, c})
#define ff first
#define ss second
#define rz resize
#define sz size()
#define cnt continue
#define brk break
#define rtn return
#define solvef void solve
#define solveT   \
    ll T;        \
    cin >> T;    \
    while (T--)  \
    {            \
        solve(); \
    }
#define ni(x) \
    int x;    \
    cin >> x;
#define nii(x, y) \
    int x, y;     \
    cin >> x >> y;
#define niii(x, y, z) \
    int x, y, z;      \
    cin >> x >> y >> z;
#define niiii(w, x, y, z) \
    int w, x, y, z;       \
    cin >> w >> x >> y >> z;
#define nl(x) \
    ll x;     \
    cin >> x;
#define nll(x, y) \
    ll x, y;      \
    cin >> x >> y;
#define nlll(x, y, z) \
    ll x, y, z;       \
    cin >> x >> y >> z;
#define nllll(w, x, y, z) \
    ll w, x, y, z;        \
    cin >> w >> x >> y >> z;
#define ns(x) \
    str x;    \
    cin >> x;
#define nss(x, y) \
    str x, y;     \
    cin >> x >> y;
#define nsss(x, y, z) \
    str x, y, z;      \
    cin >> x >> y >> z;
#define nssss(x, y, z, w) \
    str x, y, z, w;       \
    cin >> x >> y >> z >> w;
#define nc(x) \
    char x;   \
    cin >> x;
#define ncc(x, y) \
    char x, y;    \
    cin >> x >> y;
#define nccc(x, y, z) \
    char x, y, z;     \
    cin >> x >> y >> z;
#define ncccc(x, y, z, w) \
    char x, y, z, w;      \
    cin >> x >> y >> z >> w;
#define cout1(x) cout << x
#define cout2(x, y) cout << x << " " << y
#define cout3(x, y, z) cout << x << " " << y << " " << z
#define cout4(x, w, y, z) cout << x << " " \
                               << " " << w << " " << y << " " << z
#define in(e) cin >> e
#define outl(e) cout << e << endl
#define forr(i, n) for (ll i = 0; i < n; i++)
#define forl(i, b, n) for (int i = b; i <= n; i++)
#define getvecti(v, n) \
    vi v(n);           \
    forr(i, n) in(v[i]);
#define printv(v)         \
    for (auto i : v)      \
    {                     \
        cout << i << " "; \
    }                     \
    cout << endl;
#define printmp(v)                           \
    for (auto i : v)                         \
    {                                        \
        cout << i.ff << " " << i.ss << endl; \
    }
#define imax(a, b) max(a, b)
#define imaxx(a, b, c) max({a, b, c})
#define imaxxx(a, b, c, d) max({a, b, c, d})
#define imin(a, b) min(a, b)
#define iminn(a, b, c) min({a, b, c})
#define iminnn(a, b, c, d) min({a, b, c, d})

int minimun_subset_diff(vector<int> v, int w)
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
    int maxi = 0;
    for (int j = 0; j <= w / 2; ++j)
    {
        if (sol[v.size()][j] == true)
        {
            maxi = max(maxi, j);
        }
    }
    return (w - (2 * maxi)); // min (s2-s1) === ((w-s1) - s1)
}

int main()
{
    vector<int> v = {4, 4, 5, 7};
    int w = accumulate(v.begin(), v.end(), 0);
    cout << minimun_subset_diff(v, w);
    rtn 0;
}