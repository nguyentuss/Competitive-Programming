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
    int n; cin >> n;
    vector<int> a(n) , b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    vector<ii> c(n);
    // 2*a[i] - b[i];

    for (int i = 0 ; i < n; i++) {
        c[i].first = a[i] + b[i];
        c[i].second = i;
    }
    sort(c.begin() , c.end() , greater<ii>()); 
    bool status = 0;
    int ans = 0;
    for (auto [x , id] : c) {
        if (!status) {
            ans = ans + a[id] - 1;
        }
        else {
            ans = ans - (b[id] - 1);
        }
        status ^= 1;
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