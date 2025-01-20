//source:: 
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long
typedef unsigned __int128 ull;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test; 
    cin >> test;
    while (test--) {
        int n; cin >> n;
        string s; cin >> s;

        int cnt = 1;
        int ans = 0;
        s += '#';
        for (int i = 0 ; i < n ;i ++) {
            if (s[i] == '.') {
                if (s[i] == s[i + 1]) {
                    cnt++;
                }
                if (s[i] != s[i + 1]) {
                    ans = max(ans , cnt);
                    cnt = 1;
                }
            }
        }
        if (ans >= 3) {
            cout << 2 << '\n';
        }
        else {
            int cc = 0;
            for (int i = 0 ; i < n; i++) {
                if (s[i] == '.') cc++;
            }
            cout << cc << '\n';
        }
    }
    return 0;
}