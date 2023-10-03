// Author:- satyam kant//

#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl "\n"

long double dp[3000][3000];

long double rec(vector<long double> &arr, int id, int rem) {
    if (id >= arr.size()) {
        return 1.0;
    }

    if (dp[id][rem] != (-1.0)) {
        return dp[id][rem];
    }

    long double ret = (long double)1.0 * arr[id] * rec(arr, id + 1, rem);

    if (rem > 0) {
        ret += (long double)(1.0 - arr[id]) * rec(arr, id + 1, rem - 1);
    }

    return dp[id][rem] = ret;
}

void solve() {
    int n;
    cin >> n;

    vector<long double> arr(n);
    for (auto &it : arr) {
        cin >> it;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = (-1.0);
        }
    }

    int cnt = n - (n / 2 + 1);

    cout << setprecision(10) << rec(arr, 0, cnt) << endl;
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