// Author:- satyam kant//

#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl "\n"

int dp[1001][1001];
const int mod = 1e9 + 7;

int rec(vector<string> &grid, int i, int j) {
    if (i >= grid.size() || j >= grid[0].size() || grid[i][j] == '#') {
        return 0;
    }
    if (i == grid.size() - 1 && j == grid[0].size() - 1)
        return 1;

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    return dp[i][j] = (rec(grid, i + 1, j) + rec(grid, i, j + 1)) % mod;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> arr(n);
    memset(dp, -1, sizeof(dp));
    for (auto &it : arr) {
        cin >> it;
    }

    cout << rec(arr, 0, 0) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // test case...;
    int t = 1;
    // cin >> t;
    // test case end...;
    for (int i = 1; i <= t; i++) {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}