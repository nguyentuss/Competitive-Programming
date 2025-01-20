//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define le(x) (x << 1ll)
#define ri(x) ((x << 1ll) + 1)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e9;

// 3 2 4 8 2 2 2 3 3 1 2 2
// 3 2 4 8 2 1 3 3 

void solve() {
    int n; cin >> n;
    set<pii> s; 
    for (int i = 0 ; i < n ; i ++) {
        s.insert({0 , i});
    }
    vi cnt(n);
    for (int i = 0 ; i < n ; i++) {
        int x; cin >> x;
        x--; 
        auto it = *s.begin();
        if (it.first == cnt[x]) {
            s.erase({cnt[x],x});
            cnt[x]++;
            s.insert({cnt[x],x});
            cout << x + 1 << ' ';
        }
        else {
            int y = it.second; 
            s.erase(s.begin());
            cnt[y]++; 
            s.insert({cnt[y],y});
            cout << y + 1 << ' ';
        }   
    }
    cout << '\n';
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
