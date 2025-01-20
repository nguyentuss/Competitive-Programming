//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define le(x) (x << 1ll)
#define ri(x) ((x << 1ll) + 1)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e9;

void solve() {
    int n; cin >> n;
    vector<int> cnt(26 , -1); 
    bool isFound = false;
    char charFound;
    int ans = 0;
    bool stat = false;
    n--;
    while (n--) {
        char c; cin >> c;
        string s; cin >> s;
        // for (int i = 0 ; i < 26 ; i++) {
        //     cout << cnt[i] << " ";
        // }
        if (isFound && (c == '?' || c == '!')) ans++;
        if (c == '!') {
            vector<int> tmp(26);
            for (auto x : s) {
                tmp[x - 'a'] = true;    
            }
            for (int i = 0 ; i < 26 ; i++) {
                if (!stat) {
                    if (cnt[i] == -1) {
                        cnt[i] = tmp[i];
                    }
                }
                else {
                    if (cnt[i] == true && tmp[i] == false) cnt[i] = false;
                }
            }
            // for (int i = 0 ; i < 26 ; i++) {
            //     cerr << cnt[i] << " ";
            // }
            // cerr << '\n';
            stat = true;
        }
        if (c == '.') {
            for (auto x : s) {
                cnt[x - 'a'] = false;
            }
        }
        if (c == '?') {
            cnt[s[0] - 'a'] = false;
        }
        int num1 = 0, num0 = 0;
        for (int i = 0 ; i < 26 ; i++) {
            if (cnt[i] == 0) num0++; 
            if (cnt[i] == 1) num1++;
        }
        if (num0 == 25 || num1 == 1) isFound = true;
    }
    
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }

}