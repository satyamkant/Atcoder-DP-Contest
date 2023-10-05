// Author:- satyam kant//

// Note:- both recursive and iterative dp is provided

#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl "\n"

long double dp[3000][3000];

// long double rec(vector<long double> &arr, int id, int rem) {
//     if (id >= arr.size()) {
//         return 1.0;
//     }

//     if (dp[id][rem] != (-1.0)) {
//         return dp[id][rem];
//     }

//     long double ret = (long double)1.0 * arr[id] * rec(arr, id + 1, rem);

//     if (rem > 0) {
//         ret += (long double)(1.0 - arr[id]) * rec(arr, id + 1, rem - 1);
//     }

//     return dp[id][rem] = ret;
// }

void solve() {
    int n;
    cin >> n;

    vector<long double> arr(n);
    for (auto &it : arr) {
        cin >> it;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = (0.0);
        }
    }

    // int cnt = n - (n / 2 + 1);

    dp[0][0] = 1.0;
    for (int i = 1; i <= n; i++) {
        for (int head = 0; head <= n; head++) {
            if (head == 0)
                dp[i][head] = dp[i - 1][head] * (1.0 - arr[i - 1]);
            else
                dp[i][head] = dp[i - 1][head - 1] * arr[i - 1] +
                              dp[i - 1][head] * (1.0 - arr[i - 1]);
        }
    }

    long double ans = 0.0;

    for (int i = n / 2 + 1; i <= n; i++) {
        ans += dp[n][i];
    }

    cout << setprecision(10) << ans << endl;

    // cout << setprecision(10) << rec(arr, 0, cnt) << endl;
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