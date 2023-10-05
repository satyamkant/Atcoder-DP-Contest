// Author:- satyam kant//

#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl "\n"

int dp[405][405];

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = n; i >= 1; i--) {
        for (int j = i; j <= n; j++) {
            if (i == j) {
                dp[i][j] = 0;
                continue;
            }
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }
            dp[i][j] = 1e18 + 5;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum);
            }
        }
    }
    cout << dp[1][n] << endl;
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