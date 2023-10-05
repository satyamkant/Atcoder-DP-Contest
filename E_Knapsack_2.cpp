// Author:- satyam kant//

#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl "\n"

int dp[100001][101];

void solve() {

    for (int i = 0; i < 100001; i++) {
        for (int j = 0; j < 101; j++) {
            dp[i][j] = INT_MAX;
        }
    }

    int n, w;
    cin >> n >> w;

    vector<pair<int, int>> arr(n);

    for (auto &it : arr) {
        cin >> it.first >> it.second;
    }

    dp[0][0] = 0;
    dp[arr[0].second][0] = arr[0].first;

    // for (int i = 0; i < 100001; i++) {
    //     for (int j = 1; j < arr.size(); j++) {
    //         dp[i][j] = min(dp[i][j], dp[i][j - 1]);
    //         if (i - arr[j].second >= 0) {
    //             dp[i][j] =
    //                 min(dp[i][j], arr[j].first + dp[i - arr[j].second][j -
    //                 1]);
    //         }
    //     }
    // }

    /// 2nd way of doing the same
    for (int i = 1; i < n; i++) {
        for (int val = 0; val < 100001; val++) {
            dp[val][i] = min(dp[val][i], dp[val][i - 1]);
            if (val >= arr[i].second) {
                dp[val][i] = min(dp[val][i],
                                 dp[val - arr[i].second][i - 1] + arr[i].first);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 100001; i++) {
        for (int j = 0; j < 101; j++) {
            if (dp[i][j] <= w) {
                ans = max(ans, i);
            }
        }
    }
    cout << ans << endl;
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