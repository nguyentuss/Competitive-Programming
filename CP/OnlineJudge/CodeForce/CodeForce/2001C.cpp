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
const int N = 1e3 + 7;

int vis[N];
int par[N];

void DFS(int u , int v) {
    cout << "? " << u << " " << v << endl;
    cout.flush();
    int x; cin >> x;
    if (x == u || x == v) {
        vis[v] = true; 
        par[v] = u;
        return;
    }   
    if (!vis[x]) DFS(u , x);
    DFS(x , v);
}

void solve() {
    int n; cin >> n; 
    for (int i = 1 ; i <= n ; i++) vis[i] = false , par[i] = -1;
    vis[1] = 1;
    for (int i = 2 ; i <= n ; i++) {
        if (!vis[i]) DFS(1 , i);
    }
    cout << "! ";
    cout.flush();
    for (int i = 2 ; i <= n ; i++) {
        cout << i << " " << par[i] << endl , cout.flush();
    }
    cout << endl;
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