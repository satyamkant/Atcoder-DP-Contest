// Author:- satyam kant//

// Note:- both recursive and iterative dp is provided

#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl "\n"

int dp[100001][4];

int rec(vector<vector<int>> &arr, int id, int last) {
    if (id >= arr.size()) {
        return 0;
    }

    if (dp[id][last] != -1) {
        return dp[id][last];
    }

    int op = 0;
    for (int i = 1; i <= 3; i++) {
        if (i != last)
            op = max(op, arr[id][i] + rec(arr, id + 1, i));
    }

    return dp[id][last] = op;
}

void solve() {
    int n;
    cin >> n;

    memset(dp, 0, sizeof(dp));

    vector<vector<int>> arr(n, vector<int>(4));

    for (auto &it : arr) {
        cin >> it[1] >> it[2] >> it[3];
    }

    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];
    dp[0][3] = arr[0][3];

    for (int i = 1; i < n; i++) {
        dp[i][1] = arr[i][1] + max(dp[i - 1][2], dp[i - 1][3]);
        dp[i][2] = arr[i][2] + max(dp[i - 1][1], dp[i - 1][3]);
        dp[i][3] = arr[i][3] + max(dp[i - 1][1], dp[i - 1][2]);
    }

    cout << max({dp[n - 1][1], dp[n - 1][2], dp[n - 1][3]}) << endl;

    //// this is for recursive call ////
    // cout << rec(arr, 0, 0) << endl;
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