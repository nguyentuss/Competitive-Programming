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
const int N = 2e5 + 7;

void solve() {
    int n; cin >> n;
    string s1 , s2; cin >> s1 >> s2;
    string s = "";
    s = s1[0];
    int pos = -1;
    int cnt = 1;
    for (int i = 0 ; i < n - 1 ; i++) {
        if (s2[i] < s1[i + 1]) {
            s += s2[i]; 
            pos = i;
            break;
        }
        else {
            s += s1[i + 1]; 
            if (s2[i] == s1[i + 1]) cnt++;
            else cnt = 1; 
        }
    }
    if (pos == -1) {
        s += s2[n - 1];
    }
    else {
        for (int i = pos + 1 ; i < n ;i ++) {
            s += s2[i];
        }
    }
    cout << s << '\n';
    cout << cnt << '\n';
    
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