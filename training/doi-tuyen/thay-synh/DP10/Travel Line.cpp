#include <bits/stdc++.h>


using namespace std;

const int MOD = 1000000;

int main() {
    int n, m, L;
    cin >> n >> m >> L;

    vector<vector<pair<int, char>>> adj(n + 1);

    for (int i = 0; i < m; ++i) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<vector<int>> dp(L + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; ++i) {
        dp[0][i] = 1;
    }

    for (int length = 1; length <= L; ++length) {
        for (int u = 1; u <= n; ++u) {
            for (const auto &edge : adj[u]) {
                int v = edge.first;
                dp[length][v] = (dp[length][v] + dp[length - 1][u]) % MOD;
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= n; ++i) {
        result = (result + dp[L][i]) % MOD;
    }

    cout << result << '\n';
    return 0;
}
