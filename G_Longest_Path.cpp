// Author:- satyam kant//

#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl "\n"

int dp[100001];

int rec(vector<int> adj[], int node) {
    int mx = 0;
    if (dp[node] != 0)
        return dp[node];

    for (auto &it : adj[node]) {
        mx = max(mx, rec(adj, it));
    }

    dp[node] = mx + 1;
    return dp[node];
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        adj[u].push_back(v);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] == 0) {
            ans = max(ans, rec(adj, i) - 1);
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