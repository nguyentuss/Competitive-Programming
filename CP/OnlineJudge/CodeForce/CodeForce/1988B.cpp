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

void solve() {
    int n; cin >> n;
    string s; cin >> s; 
    int cnt_1 = 0 , cnt_0 = 0;
    
    for (int i = 0 ; i < s.size() ; i++) {
        if (i == n - 1 && s[i] == '0') {
            cnt_0++;
        }
        else if (s[i] == '0' && s[i + 1] == '1') {
            cnt_0++;
        }
        else if (s[i] == '1') cnt_1++;
    }
    if (cnt_0 >= cnt_1) cout << "No\n"; 
    else cout << "Yes\n";   
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