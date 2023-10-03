// Author:- satyam kant//

#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl "\n"

int dp[3001][3001][2];

int rec(vector<int> &arr, int l, int r, int turn) {
    if (l > r) {
        return 0;
    }

    if (dp[l][r][turn] != -1)
        return dp[l][r][turn];

    int op;

    if (turn) {
        op = max(arr[l] + rec(arr, l + 1, r, turn ^ 1),
                 arr[r] + rec(arr, l, r - 1, turn ^ 1));
    } else {
        op = min(-arr[l] + rec(arr, l + 1, r, turn ^ 1),
                 -arr[r] + rec(arr, l, r - 1, turn ^ 1));
    }

    return dp[l][r][turn] = op;
}

void solve() {
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));

    vector<int> arr(n);
    for (auto &it : arr) {
        cin >> it;
    }

    cout << rec(arr, 0, n - 1, 1) << endl;
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