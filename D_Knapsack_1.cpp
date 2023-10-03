// Author:- satyam kant//

#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl "\n"

int dp[100001][101];

int rec(vector<pair<int, int>> &arr, int id, int rem) {
    if (rem < 0) {
        return INT_MIN;
    }

    if (id >= arr.size()) {
        return 0;
    }

    if (dp[rem][id] != -1)
        return dp[rem][id];

    int op = 0;

    op = arr[id].second + rec(arr, id + 1, rem - arr[id].first);

    op = max(op, rec(arr, id + 1, rem));

    return dp[rem][id] = op;
}

void solve() {
    int n, w;
    cin >> n >> w;
    memset(dp, -1, sizeof(dp));
    vector<pair<int, int>> arr(n);
    for (auto &it : arr) {
        cin >> it.first >> it.second;
    }

    cout << rec(arr, 0, w) << endl;
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