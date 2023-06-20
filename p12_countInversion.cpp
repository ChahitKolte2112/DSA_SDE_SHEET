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
void merge(vector<int> &v, int l, int m, int h, int &count)
{
    vector<int> ans;
    int i = l;
    int j = m + 1;
    int k = l;
    while (i <= m && j <= h)
    {
        if (v[i] < v[j])
        {
            ans.push_back(v[i]);
            i++;
        }
        else if (v[i] > v[j])
        {
            // cout << m << " " << i << endl;
            count += (m + 1 - i);
            cout << count << endl;
            ans.push_back(v[j]);
            j++;
        }
    }
    for (i; i <= m; i++)
    {
        ans.push_back(v[i]);
    }
    for (j; j <= h; j++)
    {
        ans.push_back(v[j]);
    }
    for (int i = 0; i < ans.size(); i++)
    {
        v[l + i] = ans[i];
    }
    return;
}
void merge_sort(vector<int> &v, int l, int h, int &count)
{
    if (l == h)
    {
        return;
    }
    int m = (l + h) / 2;
    merge_sort(v, l, m, count);
    merge_sort(v, m + 1, h, count);
    merge(v, l, m, h, count);
}
 solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int count = 0;
    // vector<int> ans;
    merge_sort(v, 0, n - 1, count);
    
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