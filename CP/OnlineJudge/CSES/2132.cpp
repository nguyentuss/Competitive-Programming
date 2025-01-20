//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define int long long	
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e18 + 7;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0 ; i < n ;i++) {
        cin >> a[i]; 
        //a[i] -= i;
    }
    priority_queue<int> pq;
    int ans = 0;
    pq.push(a[0]);
    for (int i = 1 ; i < n ; i++) {
        pq.push(a[i]);
        if (a[i] < pq.top()) {
            ans += abs(pq.top() - a[i]);
            pq.pop();
            pq.push(a[i]);
        }
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test = 1; 
    //cin >> test; 
    while (test--) {
       solve();
    }
}