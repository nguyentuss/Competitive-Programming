//source:: https://codeforces.com/contest/1913/problem/D
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
const int MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    vector<int> f(n + 1);
    vector<int> g(n + 1);
    vector<int> f_sum(n + 1);
    deque<int> dq;
    dq.push_back(0);
    a[0] = 0;
    f[1] = 1;
    f_sum[1] = 1;
    g[1] = 1;
    dq.push_back(1);
    g[0] = 1;
    for (int i = 2 ; i <= n ; i++) {
        while (dq.size() && a[i] <= a[dq.back()]) dq.pop_back();
        int l = dq.back();
        f[i] = (f[i]%MOD + f_sum[i - 1] - f_sum[l] + MOD)%MOD;
        (f[i] += g[l])%=MOD;
        (g[i] += (l == 0 ? 0 : g[l]) + f[i])%=MOD;
        (f_sum[i] = f_sum[i - 1] + f[i])%=MOD; 
        dq.push_back(i);
    }
    cout << g[n] << '\n';
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