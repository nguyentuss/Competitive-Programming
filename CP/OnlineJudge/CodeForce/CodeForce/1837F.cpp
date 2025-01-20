//source:: 
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define vi vector<int>
#define fi first
#define se second
#define int long long
#define sz(a) (int) a.size()
typedef unsigned __int128 ull;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 3e5 + 7;
const int MOD = 1e9 + 7;

vector<int> a;
int n , k;

bool ok(int m) {
    vector<int> pref(n + 3);
    vector<int> suff(n + 3);
    priority_queue<int> pq;
    int now = 0;
    for (int i = 0 ; i < n ; i++) {
        now += a[i];
        pq.push(a[i]);
        for (; now > m ; pq.pop()) now -= pq.top(); 
        pref[i + 1] = pq.size();
    }
    now = 0;
    for (;!pq.empty() ; pq.pop());
    for (int i = n - 1 ; i >= 0 ; i--) {
        now += a[i];
        pq.push(a[i]);
        for (; now > m ; pq.pop()) now -= pq.top(); 
        suff[i] = pq.size();
    }
    for (int i = 0 ; i <= n ; i++) {
        if ((pref[i] + suff[i]) >= k) return true;
    }
    return false;
}


void solve() {
    cin >> n >> k;
    a.resize(n);
    for (int &x : a) cin >> x;
    int l = 1 , r = 2e15;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (ok(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1; 
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}