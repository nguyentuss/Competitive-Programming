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
    vector<int> a(n + 1);
    for (int i = 1 ; i <= n ; i ++) cin >> a[i];
    map<int , int> mp;
    map<int , int> mp1;
    for (int i = 1 ; i <= n ; i ++) {
        cin >> b[i];
        mp[b[i]] = i;
        mp1[a[i]] = i;
    } 
    queue<tuple<int , int , int>> q; 
    vector<set<int>> vl(n + 1);
    for (int i = 1 ; i <= n ; i++) {
        int val = abs(mp[a[i]] - i);
        if (b[i] == b[mp[a[i]]]) {
            q.push({val , i  , mp[a[i]]});
        }
        else {
            vl.insert(b[i]);
        }
    }
    while (!q.empty()) {
        auto [val , i , j] = q.front();;
        q.pop(); 
        if (vl[val].begin() == s.end()) {
            cout << "NO\n"; 
            return;
        }
        swap(mp1[a[i]] , mp1[a[j]]);
        swap(a[i] , a[j]);
        int x = *vl.begin(); 
        int val_ini = abs(mp[b[mp[mp1[x]]]] - )
        vl.erase(x);
        swap(b[mp[x]] , b[mp[mp1[x]]]);
        int val1 = abs(mp[x] - mp1[b[mp[x]]]);
        
        swap(mp[x] , mp[mp1[x]]);
    }
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