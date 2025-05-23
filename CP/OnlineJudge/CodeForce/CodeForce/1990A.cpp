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
    vector<int> a(n);
    set<int , greater<int>> s;
    for (int &u : a) {
        cin >> u;
        s.insert(u);
    }
    sort(a.begin() , a.end()); 
    int mx = a[0]; 
    vector<int> cnt(57);
    for (int x : a) {
        cnt[x]++;
    }
    if (cnt[a[0]] % 2) {
        cout << "YES\n"; 
        return;
    }
    s.erase(a[0]);
    for (int x : s) {
        if (cnt[x] % 2) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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