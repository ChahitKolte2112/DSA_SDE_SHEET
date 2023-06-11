#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define endl "\n"
#define all(v) (v).begin(), (v).end()

#define mod 1000000000 + 7
int badd(int a, int b)
{
    return (a + b) % mod;
}
int bsub(int a, int b)
{
    return (((a - b) % mod) + mod) % mod;
}
int bmul(int a, int b)
{
    return ((a % mod) * (b % mod)) % mod;
}
int bpow(int base, int exp)
{
    int res = 1;
    while (exp)
    {
        if (exp % 2 == 1)
        {
            res = (res * base) % mod;
        }
        exp >>= 1;
        base = (base * base) % mod;
    }
    return res;
}
int binv(int base)
{
    return bpow(base, mod - 2);
}
int bdiv(int a, int b)
{
    return bmul(a, binv(b));
}
void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> pm(n);

    for (int i = 0; i < n; i++)
    {
        pm[i].push_back(1);

        for (int j = 1; j < i; j++)
        {
            pm[i].push_back((pm[i - 1][j - 1] + pm[i - 1][j]));
        }
        if (i > 0)
        {
            pm[i].push_back(1);
        }
    }

    for (int i = 0; i < pm.size(); i++)
    {
        for (int j = 0; j < pm[i].size(); j++)
        {
            cout << pm[i][j] << " ";
        }
        cout << endl;
    }
}

int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}