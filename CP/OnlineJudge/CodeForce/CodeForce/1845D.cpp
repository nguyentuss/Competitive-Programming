#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 3e5 + 7;
const int inf = 1e18;

int a[N]; 

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0 ; i < n ; i++) 
            cin >> a[i];
        int ans = 0;
        int sum = 0 , mx = 0 , delta = -inf;
        for (int i = 0 ; i < n ; i++) {
            sum += a[i];
            mx = max(mx , sum);
            if (mx - sum > delta) {
                delta = mx - sum;
                ans = mx;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}