#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define endl "\n"

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> matrix;
    int x;

    for (int i = 0; i < n; i++)
    {
        vector<int> st;

        for (int j = 0; j < n; j++)
        {
            cin >> x;
            st.push_back(x);
        }
        matrix.push_back(st);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {

            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
    for (auto ans : matrix)
    {
        for (auto ans1 : ans)
        {
            cout << ans1 << " ";
        }
        cout << endl;
    }
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
