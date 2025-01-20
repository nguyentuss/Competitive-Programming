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
    int mx = 10000 * n; 
    string tm = to_string(mx); 
    int len_d = to_string(n).size();
    vector<int> cnt(mx + 1);
    vector<int> d(20);
    string x = to_string(n); 
    string s = "";
    bool stat = false;
    int j = 1;
    while (true) {
        for (int i = 0 ; i < sz(x) ; i++) {
            s += x[i];
            int c = stoi(s);
            if (c > mx) {
                stat = true; 
                break;
            }
            d[j++] = c;
            cnt[c] = 1;

        }
        if (stat) break;
    }
    j--;
    // for (int i = 1 ; i <= 10000 ; i++) {
    //     if (cnt[i]) cerr << i << " ";
    // }
    //cerr << '\n';
    vector<int> v;
    for (int i = 1 ; i < sz(cnt) ; i++) {
        if (cnt[i]) {
            v.push_back(i);
        }
    }

    map<pair<int , int> , bool> mp;
    for (int b = 1 ; b <= 10000 ; b++) {
        for (int val : v) {
            if ((val + b) % n == 0) {
                int a = (val + b)/n; 
                if ((a <= 10000 && a*len_d - b > 0 && a*len_d - b <= j && d[a*len_d - b] == val) || (a - b <= 0 && a*n - b == 0)) {
                    mp[pii(a , b)] = 1;
                }
            }
        }
    }
    cout << sz(mp) << '\n';
    for (auto [key , val] : mp) {
        cout << key.first << " " << key.second << '\n';
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