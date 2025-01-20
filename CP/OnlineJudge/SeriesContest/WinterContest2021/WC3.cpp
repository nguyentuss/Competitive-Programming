#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    freopen("WC3.inp", "r", stdin);
    freopen("WC3.out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        int ans = 0, x , total;
        vector<int> v; 
        v.push_back(0);
        for (int i=1; i<=n; i++){
            total = 0;
            for (int j=1; j<=m; j++){
                cin >> x;
                total += x * (1 << (m - j));
            }
            v.push_back(total);
            if (total == 0 || total == ((1 << m) - 1))ans += 1;
        }
        for (int i=2; i<=n; i++){
            total = v[i];
            for (int j=i-1; j>=1; j--){
                if (v[j] == 0 || v[j] == ((1 << m) - 1)) {
                    if (total == 0 || total == ((1 << m) - 1)) ans++;
                    else continue;
                }
                else {
                    total = (total ^ v[j]);
                    if (total == 0 || total == ((1 << m) - 1)) ans++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}