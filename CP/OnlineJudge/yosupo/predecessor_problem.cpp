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
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1;
    //cin >> test;
    while (test--) {
        int n , q; cin >> n >> q;
        string T; cin >> T;
        set<int> s;
        for (int i = 0 ; i < (int) T.size() ; i++) 
            if (T[i] == '1') s.insert(i);
        while (q--) {
            int c , k; cin >> c >> k;
            if (c == 0) {
                if (s.find(k) == s.end())
                    s.insert(k);
            }
            if (c == 1) {
                if (s.find(k) != s.end())
                    s.erase(k);
            }
            if (c == 2) {
                if (s.find(k) != s.end()) cout << "1\n";
                else cout << "0\n";
            }
            if (c == 3) {
                auto it = s.lower_bound(k); 
                cout << (it == s.end() ? -1 : *it) << '\n';
            }
            if (c == 4) {
                auto it = s.upper_bound(k); 
                cout << (it == s.begin() ? -1 : *(--it)) << '\n';
            }
        }
    }
    return 0;
}