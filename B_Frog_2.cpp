// Author:- satyam kant//

#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl "\n"

int dp[100001];

int rec(vector<int> &arr, int id, int k) {
    if (id == arr.size() - 1) {
        return 0;
    }

    if (dp[id] != -1)
        return dp[id];

    int op = INT_MAX;
    for (int i = 1; i <= k; i++) {
        if (id + i < arr.size()) {
            op = min(op, abs(arr[id] - arr[id + i]) + rec(arr, id + i, k));
        } else {
            break;
        }
    }

    return dp[id] = op;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (auto &it : arr) {
        cin >> it;
    }

    for (int i = 0; i < n; i++) {
        dp[i] = -1;
    }

    cout << rec(arr, 0, k) << endl;
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