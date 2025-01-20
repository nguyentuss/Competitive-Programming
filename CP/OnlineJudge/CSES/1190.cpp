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

struct seg {
    int pref , suf , sum , ans;
}IT[4*N];

void update(int id , int l , int r , int pos , int val) {
    if (l > pos || r < pos) return ;
    if (l == r) {
        IT[id].pref = IT[id].suf = IT[id].ans = max(0ll , val);
        IT[id].sum = val;
        return;
    }
    int mid = (l + r) /2; 
    update(2 * id , l , mid , pos , val);
    update(2 * id + 1 , mid + 1 , r , pos , val) ;
    IT[id].pref = max(IT[2*id].pref, IT[2*id].sum + IT[2*id + 1].pref); 
    IT[id].suf = max(IT[2*id + 1].suf , IT[2*id + 1].sum + IT[2*id].suf);
    IT[id].sum = IT[2*id].sum + IT[2*id + 1].sum;
    IT[id].ans = max({IT[2*id + 1].ans , IT[2*id].ans, IT[2*id].suf + IT[2*id + 1].pref});
    return;
}

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) { 
        int x; cin >> x;
        update(1 , 1 , n , i , x);
    }
    while (m--) {
        int pos , x; cin >> pos >> x;
        update(1 , 1 , n , pos , x); 
        cout << IT[1].ans << '\n';
    }
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