#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define endl "\n"

void makezero(vector<vector<int>> &matrix, int n, int m)
{
    vector<pair<int, int>> pa;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                pa.push_back(make_pair(i, j));
            }
        }
    }

    for (auto ans : pa)
    {
        int row = ans.first;
        int col = ans.second;
        for (int i = 0; i < m; i++)
        {
            matrix[i][col] = 0;
        }
        for (int j = 0; j < n; j++)
        {
            matrix[row][j] = 0;
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    int m;
    cin >> m;

    vector<vector<int>> matrix;
    for (int i = 0; i < m; i++)
    {
        vector<int> v(n);
        for (int j = 0; j < n; j++)
        {

            cin >> v[j];
        }
        matrix.push_back(v);
    }
    cout << matrix.size() << endl;
    cout << matrix[0].size() << endl;
    for (int i = 0; i < m; i++)
    {

        for (int j = 0; j < n; j++)
        {

            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "new matrix" << endl;
    makezero(matrix, n, m);
    for (int i = 0; i < m; i++)
    {

        for (int j = 0; j < n; j++)
        {

            cout << matrix[i][j] << " ";
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