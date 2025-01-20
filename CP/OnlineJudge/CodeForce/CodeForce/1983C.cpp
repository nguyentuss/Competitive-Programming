//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e9;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1) , b(n + 1) , c(n + 1); 
    vector<int> sum_a(n + 1) , sum_b(n + 1) , sum_c(n + 1);
    for (int i = 1 ; i <= n ; i++) cin >> a[i] , sum_a[i] = sum_a[i - 1] + a[i];
    for (int i = 1 ; i <= n ; i++) cin >> b[i] , sum_b[i] = sum_b[i - 1] + b[i];
    for (int i = 1 ; i <= n ; i++) cin >> c[i] , sum_c[i] = sum_c[i - 1] + c[i];
    int tot = sum_a[n]/3;
    if (sum_a[n] % 3) {
        tot++;
    }
    for (int i = 1 ; i <= n ; i++) {
        int l = 1 , r = i; 
        while (l <= r) {
            int mid = (l + r)/2; 
            if (sum_a[i] - sum_a[mid - 1] >= tot) {
                l = mid + 1;
                if ((sum_b[mid - 1] >= tot && (sum_c[n] - sum_c[i] >= tot))) {
                    cout << mid << " " << i << " " << 1 << " " << mid - 1 << " " << i + 1 << " " << n << '\n';
                    return;
                }
                if ((sum_c[mid - 1] >= tot && (sum_b[n] - sum_b[i] >= tot))) {
                    cout << mid << " " << i << " " << i + 1 << " " << n << " " << 1 << " " << mid - 1 << '\n';
                    return;
                }
            }
            else {
                r = mid - 1;
            }
        }
    }
    for (int i = 1 ; i <= n ; i++) {
        int l = 1 , r = i; 
        while (l <= r) {
            int mid = (l + r)/2; 
            if (sum_b[i] - sum_b[mid - 1] >= tot) {
                l = mid + 1;
                if ((sum_a[mid - 1] >= tot && (sum_c[n] - sum_c[i] >= tot))) {
                    cout << 1 << " " << mid - 1 << " " << mid << " " << i << " " << i + 1 << " " << n << '\n';
                    return;
                }
                if ((sum_c[mid - 1] >= tot && (sum_a[n] - sum_a[i] >= tot))) {
                    cout << i + 1 << " " << n << " " << mid << " " << i << " " << 1 << " " << mid - 1 << '\n';
                    return;
                }
            }
            else {
                r = mid - 1;
            }
        }
    }
    for (int i = 1 ; i <= n ; i++) {
        int l = 1 , r = i; 
        while (l <= r) {
            int mid = (l + r)/2; 
            if (sum_c[i] - sum_c[mid - 1] >= tot) {
                l = mid + 1;
                if ((sum_a[mid - 1] >= tot && (sum_b[n] - sum_b[i] >= tot))) {
                    cout << 1 << " " << mid - 1 << " " << i + 1 << " " << n << " " << mid << " " << i <<'\n';
                    return;
                }
                if ((sum_b[mid - 1] >= tot && (sum_a[n] - sum_a[i] >= tot))) {
                    cout << i + 1 << " " << n << " " << 1 << " " << mid - 1 << " " << mid << " " << i << '\n';
                    return;
                }
            }
            else {
                r = mid - 1;
            }
        }
    }
    cout << -1 << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    cin >> test;
    while (test--) {
        solve();
    }

}