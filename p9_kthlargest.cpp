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

int findKthLargest(vector<int> &v, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int n = v.size();
    for (int i = 0; i < k; i++)
    {

        pq.push(v[i]);
    }
    for (int i = k; i < n; i++)
    {
        if (pq.top() < v[i])
        {
            pq.pop();
            pq.push(v[i]);
        }
    }

    return pq.top();
}

int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v;
        int k;
        cin >> k;
        int x;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            v.push_back(x);
        }
        findKthLargest(v, k);
    }
    return 0;
}