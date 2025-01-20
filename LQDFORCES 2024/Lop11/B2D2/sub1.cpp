//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define int long long	
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e18 + 7;

int nen(int x) {
    int res = 1; 
    if (x == 1) return x; 
    for (int i = 2 ; i <= x ; i++) {
        if (x % i == 0) {
            int cnt = 0;
            while (x % i == 0) {
                x /= i;
                cnt++;
            }
            if (cnt % 2) res *= i;
        }   
    }
    return res;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<int> p(n + 3);
    for (int i = 1 ; i <= n ; i++) {
        p[nen(i)]++;
    }
    int ans = 1;
    for (int i = 1 ; i <= n ; i++) {
        if (p[i]) {
            (ans *= (p[i] + 1))%=m;
        }
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test = 1; 
    //cin >> test; 
    while (test--) {
       solve();
    }
}