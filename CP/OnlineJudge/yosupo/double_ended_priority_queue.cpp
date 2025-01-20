//source:: https://judge.yosupo.jp/problem/double_ended_priority_queue
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
const int N = 5e5 + 7;
const int MOD = 1e9 + 7;

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1; 
    //cin >> test;
    while (test--) {
        int n, q; cin >> n >> q;
        multiset<int> s; 
        for (int i = 0 ; i < n; i++) {
            int x; cin >> x;
            s.insert(x);
        }
        while (q--) {
            int ask; cin >> ask;
            if (ask == 0) {
                int x; cin >> x;
                s.insert(x);
            }
            if (ask == 1) {
                auto it = s.begin();
                cout << *it << '\n';
                if (!s.empty())
                    s.erase(s.find(*it));
            }
            if (ask == 2) {
                auto it = s.rbegin();
                cout << *it << '\n';
                if (!s.empty())
                   s.erase(s.find(*it));
            }
        }
    }
    return 0;
}