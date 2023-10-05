// Author:- satyam kant//

// Note:- both recursive and iterative dp is provided

#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl "\n"

// int dp[100001][101];

// int rec(vector<pair<int, int>> &arr, int id, int rem) {
//     if (rem < 0) {
//         return INT_MIN;
//     }

//     if (id >= arr.size()) {
//         return 0;
//     }

//     if (dp[rem][id] != -1)
//         return dp[rem][id];

//     int op = 0;

//     op = arr[id].second + rec(arr, id + 1, rem - arr[id].first);

//     op = max(op, rec(arr, id + 1, rem));

//     return dp[rem][id] = op;
// }

int dp[101][100001];

void solve() {
    int n, w;
    cin >> n >> w;

    vector<pair<int, int>> arr(n);
    for (auto &it : arr) {
        cin >> it.first >> it.second;
    }

    memset(dp, 0, sizeof(dp));
    dp[0][arr[0].first] = arr[0].second;

    for (int i = 1; i < n; i++) {
        for (int x = 0; x <= w; x++) {
            if (x >= arr[i].first)
                dp[i][x] = max(dp[i - 1][x],
                               dp[i - 1][x - arr[i].first] + arr[i].second);
            else
                dp[i][x] = dp[i - 1][x];
        }
    }

    int ans = 0;
    for (int i = 0; i <= w; i++) {
        ans = max(ans, dp[n - 1][i]);
    }
    cout << ans << endl;

    ////////// recursive call /////////
    // memset(dp, -1, sizeof(dp));
    // cout << rec(arr, 0, w) << endl;
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