//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long
typedef pair<int, int> ii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

int cv(string &s) {
    int ans = 0;
    for (auto x : s) {
        ans = ans + x - '0'; 
        ans *= 10;
    }
    ans /= 10;
    return ans;
}

void solve() {
    string s; cin >> s;
    int n = sz(s);
    int l = 0 , r = 1;
    while (r < n && s[r] == '0') {
        r++; 
        l++;
    }
    string a = "";
    for (int i = 0 ; i <= l ; i++) {
        a += s[i];
    }   
    string b = "";
    for (int i = r ; i < n ; i++) {
        b += s[i];
    }
    int x1 = cv(a);
    int x2 = cv(b);
    if (x1 >= x2) cout << -1 << '\n';
    else {
        cout << a << " " << b << '\n';
    }
}

main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
    int test; cin >> test;
    while (test--) {
        solve();
    }
}