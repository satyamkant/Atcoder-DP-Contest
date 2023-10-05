// Author:- satyam kant//

// Note:- both recursive and iterative dp is provided

#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl "\n"

// int dp[100011][3];

// int rec(vector<int> &arr, int turn, int rem) {

//     if (rem == 0) {
//         return 1 - turn;
//     }

//     if (rem < 0) {
//         return turn;
//     }

//     if (dp[rem][turn] != -1) {
//         return dp[rem][turn];
//     }

//     int op = 1 - turn;
//     for (auto &it : arr) {
//         if (turn) {
//             op = max(op, rec(arr, turn ^ 1, rem - it));
//         } else {
//             op = min(op, rec(arr, turn ^ 1, rem - it));
//         }
//     }

//     return dp[rem][turn] = op;
// }

int dp[100001];

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (auto &it : arr) {
        cin >> it;
    }

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++) {
        dp[arr[i]] = 1;
    }

    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            if (i - arr[j] >= 1) {
                dp[i] = max(dp[i], 1 - dp[i - arr[j]]);
            }
        }
    }

    if (dp[k]) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }

    // memset(dp, -1, sizeof(dp));

    // if (n == 1 && arr[0] == 1) {
    //     if (k % 2 == 0) {
    //         cout << "Second" << endl;
    //         return;
    //     }
    //     cout << "First" << endl;
    //     return;
    // }

    // cout << ((rec(arr, 1, k) == 1) ? "First" : "Second") << endl;
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