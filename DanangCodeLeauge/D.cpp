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

void solve() {
    int n; cin >> n;
    vector<int> d(n + 1, inf);
    d[0] = 0;
    set<int> s; 
    vector<int> a(n + 1);
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
    a[n] = 0;
    for (int i = 1 ; i <= n ; i++) {
        s.insert(i);
    }
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        //cerr << u << '\n'; 
        if (u == n) break;
        q.pop();
        auto it = s.lower_bound(u);
        while (it != s.end() && *it <= u + a[u]) {
            //cerr << u << " " << *it << '\n';
            q.push(*it);
            d[*it] = d[u] + 1;
            auto tm = it;
            it++;
            s.erase(tm);
        }
        //cerr << '\n';
    }
    if (d[n] == inf) {
        cout << "CANNOT GET DESTINATION";
    }
    else cout << d[n];

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