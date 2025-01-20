#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
#define int long long
#define f first
#define s second

int ans[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<pair<int , int>> a;
        for (int i = 1 ; i <= n ; i++) {
            int x; cin >> x;
            a.push_back(make_pair(x , i));
        }
        sort(a.begin() , a.end());
        int l = 0 , r = n - 1 , d = 0; 
        bool ok = true;
        while (l <= r) {
            while (l <= r && a[l].f - d == 0) {
                ans[a[l].s] = -(r - l + 1);
                l++;
            }
            if (l > r) break;
            if (r - l + 1 != a[r].f - d) {
                ok = false;
                break;
            }
            ans[a[r].s] = r - l + 1;
            r--; 
            d++;
        }
        if (!ok) {
            cout << "NO" << '\n';
        }
        else {
            cout << "YES" << '\n';
            for (int i = 1 ; i <= n ; i++) {
                cout << ans[i] << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}