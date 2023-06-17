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
    int sum = (n * (n + 1) / 2);
    int sq_sum = ((sum * (2 * n + 1)) / 3);
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        sum1 += v[i];
        sum2 += (v[i] * v[i]);
    }
    int x = (sum1 - sum);
    int y = (sum2 - sq_sum);
    y = y / x;
    x = (y + x) / 2;
    sum1 = sum1 - x;
    int mi = sum - sum1;

    cout << mi << " " << x << endl;
    return;
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
