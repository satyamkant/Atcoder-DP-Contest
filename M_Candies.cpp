// Author:- satyam kant//

#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl "\n"

const int mod = 1e9 + 7;

int dp[101][100001];

/*
    dp[i][j] = number of ways to distribute j candies if we are at i child

    dp[x][y] = dp[x-1][y] + dp[x-1][y-1] .... dp[x-1][y-a[x]]

*/

void solve() {
    int n, k;
    cin >> n >> k;
    memset(dp, 0, sizeof(dp));

    vector<int> arr(n);
    for (auto &it : arr) {
        cin >> it;
    }

    //////// base cases /////////////////
    for (int i = 0; i <= arr[0]; i++) {
        dp[0][i] = 1;
    }
    /////////////////////////////////////

    for (int x = 1; x < n; x++) {
        vector<int> pref;

        int sum = 0;
        for (int id = 0; id <= k; id++) {
            sum += dp[x - 1][id];
            sum %= mod;
            pref.push_back(sum);
        }

        for (int y = 0; y <= k; y++) {
            if (y > arr[x])
                dp[x][y] = (pref[y] - pref[y - min(y, arr[x]) - 1] + mod) % mod;
            else
                dp[x][y] = pref[y] % mod;
            // for (int neg = 0; neg <= min(y, arr[x]); neg++) {
            //     dp[x][y] += dp[x - 1][y - neg];
            // }
            /// from y to y-min(y,arr[x])....
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j <= k; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[n - 1][k] << endl;
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