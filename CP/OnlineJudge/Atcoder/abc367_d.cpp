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
const int N = 5e5 + 7; 
const int M = 2e6 +7 ;

int a[N];
int f[N];
int cnt[M]; 

void solve() {
    int n , m; cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i]; 
        a[i] %= m;
        a[i + n] = a[i];
    }
    for (int i = 1 ; i <= 2*n ; i++) {
        f[i] = (f[i - 1] + a[i])%m;
    }
    for (int i = 1 ; i < n ; i++) cnt[f[i]]++; 
    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        ans += cnt[f[i]]; 
        cnt[f[i + 1]]--;
        cnt[f[i + n]]++; 
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }

}