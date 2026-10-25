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

struct line {
    int left , right , height;
};

void solve() {
    int n; cin >> n;
    vector<line> a(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i].left >> a[i].right >> a[i].height;
    }  
    int mx = 0;
    for (int i = 0 ; i < n; i++) {
        set<pair<int , int>> s;
        mx = max({mx , a[i].left , a[i].right});
        if (i != 0) {
            if (a[i - 1].right < a[i].left) {
                cout << a[i - 1].right << " " << 0 << '\n';
            }
        }
        for (int j = 0 ; j < n ; j++) {
            if (j != i) {
                if (a[i].height <= a[j].height) {
                    if (a[i].left <= a[j].left && a[j].right <= a[i].right) {
                        //cout << j << " " << a[j].left << " " << a[j].right << '\n';
                        s.insert(pii(a[j].left , a[j].right));
                    }
                    else if (a[i].left <= a[j].left && a[j].right > a[i].right) {
                        //cout << j << " " << a[j].left << " " << a[i].right << '\n';
                        s.insert(pii(a[j].left , a[i].right));
                    }
                    else {
                        if (a[j].left < a[i].left && a[j].right >= a[i].left) {
                            s.insert(pii(a[i].left , a[j].right));
                            //cout << j << " " << a[i].left << " " << a[j].right << '\n';
                        }
                    }
                }
            }
        }
        int mn = a[i].left;
        // for (auto [x , y] : s) {
        //     cerr << x << " " << y << '\n';
        // }
        // cerr << '\n';
        for (auto [x , y] : s) {
            if (mn >= x && mn <= y) {
                mn = y;
            }
        }
        cout << mn << " " << a[i].height << '\n';
    }
    cout << mx << " " << 0 << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }

}