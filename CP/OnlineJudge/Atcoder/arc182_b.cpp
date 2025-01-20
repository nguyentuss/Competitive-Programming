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
    int n , k; cin >> n >> k;
    if (k == 1) {
        for (int i = 1 ; i <= n ; i++) {
            cout << 1 << " ";
        }
        cout << '\n';
        return;
    }
    int init = (1 << k) >> 1;
    int level = 0;
    int cnt = 0;
    vector<int> v;
    int l = 0;
    int mask = (1 << k) >> 1; 
    mask++;
    int zz = (1 << (k - 2)); 
    cout << init << " ";
    v.push_back(init);
    vector<int> tmp;
    n--;
    while (n--) {   
        cout << v[l] + zz << " ";
        tmp.push_back(v[l] + zz);
        l++; 
        cnt++;
        if (cnt == (1 << level)) {
            level++; 
            reverse(all(tmp));
            for (int x : tmp) {
                v.push_back(x);  
            }
            tmp.clear();
            l=0;
            cnt=0;
            zz >>= 1;
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