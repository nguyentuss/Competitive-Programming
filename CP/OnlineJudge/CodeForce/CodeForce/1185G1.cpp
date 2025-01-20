#include <bits/stdc++.h>

using namespace std;

#define MOD (int) (1e9 + 7)

int f[1 << 15][4];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    int n , T; cin >> n >> T;
    vector<int> t , g;
    t.resize(15 , 0);
    g.resize(15 , 0);
    for (int i = 0 ; i < n ; i++) {
        cin >> t[i] >> g[i];
        g[i] --;
    }
    f[0][3] = 1;
    int ans = 0;
    for (int mask = 0 ; mask < (1 << n) ; mask++) {
        for (int status = 0 ; status <= 3 ; status ++) {
            for (int j = 0 ; j < n ; j++) {
                if (f[mask][status] == 0) continue;
                if (!(mask & (1 << j)) && g[j] != status) {
                    (f[mask | (1 << j)][g[j]] += f[mask][status]) %= MOD;
                }
            }
            int sum = 0;
            for (int j = 0 ; j < n ; j++) {
                if (mask & (1 << j)) {
                    sum += t[j];
                }
            }
            if (sum == T) (ans += f[mask][status])%=MOD;
        }
    }
    cout << ans%MOD;
    return 0;
}