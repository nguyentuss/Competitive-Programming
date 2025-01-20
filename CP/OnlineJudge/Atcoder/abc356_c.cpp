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

vector<int> adj[N];
char a[N];

string binary(int x) {
    string t = ""; 
    while (x) {
        t = t + to_string(x%2);
        x /= 2;
    }
    reverse(all(t)); 
    return t;
}

void solve() {
    int n, m , k; cin >> n >> m >> k;
    for (int i = 0 ; i < m ; i++) {
        int c; cin >> c;
        for (int j = 0 ; j < c ; j++) {
            int x; cin >> x; 
            x--;
            adj[i].push_back(x);
        }
        cin >> a[i];
    }
    int ans = 0;
    for (int mask = 0 ; mask < (1 << n) ; mask++) {
        bool ok = true;
        for (int i = 0 ; i < m ; i++) {
            int cnt = 0;
            for (int x : adj[i]) {
                cnt = cnt + (((1 << x)&mask) != 0 ? 1 : 0);
            }
            if (a[i] == 'o' && cnt < k) ok = false;
            if (a[i] == 'x' && cnt >= k) ok = false;
        }
        if (ok) {
            //cout << binary(mask) << '\n';
            ans++;
        } 
       
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