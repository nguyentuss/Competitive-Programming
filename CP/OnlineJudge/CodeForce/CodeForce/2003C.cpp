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
    string s; cin >> s;
    map<int,int> mp;
    for (auto x : s) mp[x - 'a']++; 
    
    int pos = 0;
    for (int i = 0 ; i < n ; i++) {
        while (true) {
            if (mp[pos]) {
                cout << (char) (pos + 'a');
                mp[pos]--;
                pos = (pos + 1)%26;
                break;
            }
            pos = (pos + 1)%26;
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