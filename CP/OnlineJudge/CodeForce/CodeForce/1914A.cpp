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

void solve() {
    vector<int> cnt(100);
    int n; cin >> n;
    string s; cin >> s;
    for (auto c : s) {
        cnt[c - 'A']++;
    }
    int ans = 0;
    for (int i = 0 ; i < 26 ; i++) {
        if (cnt[i] > i) {
            ans ++; 
        }
    }
    cout << ans << '\n';
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test; 
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}