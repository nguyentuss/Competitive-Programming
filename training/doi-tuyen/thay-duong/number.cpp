#include <bits/stdc++.h>

using namespace std;

#define int long long

int n , a , b;

bool check(int x) {
    int sum = 0;
    int tmp=(a*b)/__gcd(a,b);
    sum = x/a + x/b - x/tmp;
    return (sum >= n);
}
signed main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    freopen("number.inp","r",stdin);
    freopen("number.out","w",stdout);
    int t; cin >> t;
    while (t--) {
        cin >> a >> b >> n;
        int l = min(a , b) , r = 1e15;
        int ans = 0;
        while (l <= r) {
            int mid = (l + r)/2;
            if (check(mid)) {
                r = mid - 1;
                ans = mid;
            }
            else {
                l = mid + 1;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
