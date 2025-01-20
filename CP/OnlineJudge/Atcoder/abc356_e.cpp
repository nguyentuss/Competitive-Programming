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
const int N = 2e5 + 7; 
const int M = 1e6 + 7;

int a[N];

void solve() {
    int n; cin >> n;
    vector<int> a(n); 
    vector<int> f(2*M + 7);
    vector<int> cnt(M);
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
        f[a[i]]++;
        cnt[a[i]]++;
    }
    for (int i = 1 ; i < 2*M ; i++) {
        f[i] = f[i - 1] + f[i];
    }
    sort(a.begin() , a.end()); 
    a.resize(distance(a.begin() , unique(a.begin() , a.end())));
    int ans = 0;
    for (int x : a) {
        int cc = 1;
        for (int j = x ; j < M ; j += x) {
            int jj = min(M - 1 , j + x - 1);
            int tmp = ans;
            ans = ans + (cc++)*cnt[x]*(f[jj] - f[j - 1 + (j == x)]);
        }
    }
    for (int x : a) {
        ans += cnt[x]*(cnt[x] - 1)/2;
    }
    cout << ans;
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