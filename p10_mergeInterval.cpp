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
bool cmp(const vector<int> a, const vector<int> b)
{
    return a[0] < b[0];
}
void solve()
{

    vector<vector<int>> v{{2, 3}, {4, 5}, {6, 7}, {8, 9}, {1, 10}};
    vector<vector<int>> ans;
    sort(v.begin(), v.end(), cmp);
    int n = v.size();
    int low = v[0][0];
    int high = v[0][1];
    for (int i = 0; i < n; i++)
    {
        cout << v[i][0] << " " << v[i][1] << endl;
    }
    for (int i = 1; i < n; i++)
    {
        if (high >= v[i][0])
        {
            cout << "check" << endl;
            high = max(v[i][1], high);
            low = min(low, v[i][0]);
        }
        else
        {
            ans.push_back({low, high});

            low = v[i][0];
            high = v[i][1];
        }
    }

    ans.push_back({low, high});
    cout << endl;
    for (auto ans1 : ans)
    {
        cout << ans1[0] << " " << ans1[1] << endl;
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
