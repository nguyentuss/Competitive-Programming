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
    int n , m; cin >> n >> m;
    int max_mex = 0;
    vector<pii> edge;
    for (int i = 0 ; i < n ; i++) {
        int l; cin >> l; 
        vector<int> a;
        for (int j = 0 ; j < l ; j++) {
            int x; cin >> x;
            a.push_back(x);
        }
        sort(all(a));
        int mex = 0;
        for (int x : a) if (x == mex) mex++;
        int m1 = mex;
        a.push_back(mex); 
        sort(all(a)); 
        mex = 0;
        for (int x : a) if (x == mex) mex++; 
        max_mex = max(max_mex , mex);
        //cout << m1 << " " << mex << '\n';
        edge.push_back(pii(m1 , mex));
    }
    vector<vi> adj(max_mex+1);
    for (auto [u , v] : edge) adj[u].push_back(v);  
    vector<int> f(max_mex + 1);
    
    for (int u = max_mex ; u >= 0 ; u--) {
        for (int v : adj[u]) {
            f[u] = max({f[u] , f[v] , v});
        }
    }
    int max1 = 0; // cho nhung thang kh co chạy vào được chính nó
    int max2 = 0; // cho nhung thang nao vao duoc chinh no
    for (int i = 0 ; i <= max_mex ; i++) {
        if (sz(adj[i]) >= 2) max1 = max(max1 , f[i]);
        if (sz(adj[i])) max2 = max(max2 , i);
    }
    int ans = 0;
    for (int i = 0 ; i <= min(m , max_mex) ; i++) {
        int vl = max({i , max1 , f[i] , max2});
        //cout << vl << " ";
        ans += vl;
    }
    if (m > max_mex) {
        ans = ans + m*(m + 1)/2 - (max_mex)*(max_mex + 1)/2;
    }
    cout << ans << '\n';

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