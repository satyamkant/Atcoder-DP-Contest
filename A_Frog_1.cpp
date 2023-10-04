// Author:- satyam kant//

// Note:- both recursive and iterative dp is provided

#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl "\n"

int dp[100001];

int rec(vector<int> &arr, int id) {
    if (id == arr.size() - 1) {
        return 0;
    }

    if (dp[id] != -1)
        return dp[id];
    int op = 0;

    if (id + 1 < arr.size()) {
        op = abs(arr[id] - arr[id + 1]) + rec(arr, id + 1);
    }
    if (id + 2 < arr.size()) {
        op = min(op, abs(arr[id] - arr[id + 2]) + rec(arr, id + 2));
    }

    return dp[id] = op;
}

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &it : arr) {
        cin >> it;
    }

    memset(dp, 0, sizeof(dp));

    dp[1] = abs(arr[0] - arr[1]);

    for (int i = 2; i < n; i++) {
        dp[i] = min(dp[i - 1] + abs(arr[i - 1] - arr[i]),
                    dp[i - 2] + abs(arr[i - 2] - arr[i]));
    }
    cout << dp[n - 1] << endl;
    /////////// this part is for recursive /////////////////
    // for (int i = 0; i < n; i++) {
    //     dp[i] = -1;
    // }

    // // cout << rec(arr, 0) << endl;
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