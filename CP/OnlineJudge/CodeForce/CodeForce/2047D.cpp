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
const int inf = 1e15;

vi lis(const vi a) {
    int res = 0;
    int n = sz(a);
    vector<int> f(n), b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = inf;
        f[i] = upper_bound(b.begin(), b.begin() + res + 1, a[i]) - b.begin();
        // cout << f[i] << " ";
        res = max(res, f[i] + 1);
        b[f[i]] = a[i];
    }
    for (int i = 0 ; i < n ; i++) {
        f[i]++;
    }
    res = *max_element(f.begin(),f.end()) + 1;
    vector<int> lis;
    for (int p = b.size() ; p-->0;) {
        if (res == f[p] + 1) {
            res--;
            lis.push_back(p);
        }
    }
    return lis;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    min_heap<int> pq;
    int mn = inf;
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
        mn = min(mn , a[i]);
    }
    int mx_pos = 0;
    for (int i = 0 ; i < n ; i++) {
        if (mn == a[i]) mx_pos = i;
    }
    int cnt = 0;
    for (int i = 0 ; i <= mx_pos ; i++) {
        if (a[i] != mn) {
            pq.push(a[i] + 1);
        }
        else cnt++;
    }
    vector<int> b;
    for (int i = mx_pos + 1 ; i < n ; i++) {
        if (pq.size() && pq.top() < a[i]) pq.push(a[i] + 1);
        else {
            b.push_back(a[i]);
        }
    }
    vi c;
    if (sz(b)) c = lis(b);
    vector<int> pos(n);
    for (int x : c) {
        // cerr << x << " ";
        pos[x] = true;
    }
    for (int i = 0 ; i < sz(b) ; i++) {
        if (pos[i] == false) {
            pq.push(b[i] + 1);
        }
    }
    while (cnt) {
        cnt--;
        cout << mn << " ";
    }
    reverse(all(c));
    for (int x : c) cout << b[x] << " ";
    while (!pq.empty()) {
        int u = pq.top(); 
        pq.pop();
        cout << u << " ";
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
