#include<bits/stdc++.h>

#define endl "\n"
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = n; i >= 1; i--) {
        for (int j = n; j >= 1; j--) {
            if (j % i == 0 && !a[j]) a[j] = i;
        }
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}