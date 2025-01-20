//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
typedef pair<int, int> ii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

int cnt[35];

void solve() {
    int m; cin >> m;
    while (m--) {
        int ask , x; cin >> ask >> x;
        if (ask == 1) {
            cnt[x]++;   
        }
        else {
            for (int i = 29 ; i >= 0 ; i--) {
                if (cnt[i]) {
                    int last = x/(1 << i); 
                    x = x - min(last , cnt[i])*(1 << i);
                }
            }
            if (x == 0) {
                cout << "YES\n";
            }
            else cout << "NO\n";
        }
    }
}

main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
    int test = 1;
    while (test--) {
        solve();
    }
}