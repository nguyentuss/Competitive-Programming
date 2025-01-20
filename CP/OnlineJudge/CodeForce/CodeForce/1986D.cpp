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
    s = " " + s;
    int ans = 1E9;
    for (int i = 1 ; i <= n ; i ++) {
        vector<int> v;
        if (i == n) continue;
        string vl = s.substr(i , 2); 
        //cout << vl << '\n';
        for (int j = 1 ; j < i ; j++) {
            v.push_back(s[j] - '0'); 
        }
        v.push_back(stoi(vl)); 
        for (int j = i + 2 ; j <= n ; j++) {
            v.push_back(s[j] - '0'); 
        }
        stack<int> st; st.push(v[0]);
        for (int j = 1 ; j < sz(v) ; j++) {
            if (v[j] == 0 || v[j] == 1) {
                int c = st.top();
                st.pop(); 
                c = c * v[j]; 
                st.push(c);
            }
            else {
                int c = st.top();
                st.pop(); 
                if (c == 0 || c == 1) c = c * v[j];
                else c = c + v[j]; 
                st.push(c);
            }
        }
        ans = min(ans , st.top()); 
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