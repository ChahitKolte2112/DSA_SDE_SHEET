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
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int low = 0;
    int high = n - 1;
    int buy = v[0];
    int profit = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] < buy)
        {
            buy = v[i];
        }
        else if (profit < (v[i] - buy))
        {
            profit = v[i] - buy;
        }
    }
    cout << profit << endl;
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