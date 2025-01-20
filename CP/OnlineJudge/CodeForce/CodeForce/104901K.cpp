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
const int inf = 1e15;
const int N = 5e5 + 7;

int n , k;
int a[N];
map<int , int> mp;
int IT1[4 * N]; 
int IT2[4 * N];
int b[N];

void update1(int id , int l , int r , int i , int val) {
    if (l > i || r < i) return;
    if (l == r) {
        IT1[id] += val;
        return;
    }
    int mid = (l + r) >> 1; 
    update1(2 * id , l , mid , i , val);
    update1(2 * id + 1 , mid + 1 , r , i , val); 
    IT1[id] = IT1[2 * id] + IT1[2 * id + 1];
}

int query1(int id , int l , int r , int L , int R) {
    if (l > R || r < L) return 0; 
    if (L <= l && r <= R) return IT1[id]; 
    int mid = (l + r) >> 1;
    return (query1(2 * id , l , mid , L , R) + query1(2 * id + 1 , mid + 1 , r , L , R));
}

void update2(int id , int l , int r , int i , int val) {
    if (l > i || r < i) return;
    if (l == r) {
        IT2[id] += val;
        return;
    }
    int mid = (l + r) >> 1; 
    update2(2 * id , l , mid , i , val);
    update2(2 * id + 1 , mid + 1 , r , i , val); 
    IT2[id] = IT2[2 * id] + IT2[2 * id + 1];
}

int query2(int id , int l , int r , int K) {
    //cerr << l << " " << r << " " << IT2[id] << " " << K << " " << '\n';
    if (IT2[id] < K) return -1;
    if (l == r) {
        return l;
    }
    int mid = (l + r) >> 1; 
    if (IT2[2 * id] > K) {
        return query2(2 * id , l , mid , K);
    }
    return query2(2 * id + 1 , mid + 1,  r , K - IT2[2 * id]);
}

int query3(int id , int l , int r , int L , int R) {
    if (l > R || r < L) return 0; 
    if (L <= l && r <= R) return IT2[id]; 
    int mid = (l + r) >> 1;
    return (query3(2 * id , l , mid , L , R) + query3(2 * id + 1 , mid + 1 , r , L , R));
}

void init() {
    mp.clear();
    for (int i = 0 ; i <= 4*n + 7 ; i++) {
        IT1[i] = 0;
        IT2[i] = 0;
    }
}

bool check(int X) {
    if (X == 1) return true;
    int med = X/2;
    int vl = query2(1 , 1 , n , med);
    if (vl != -1) {
        int vc = query1(1 , 1 , n , vl , vl)/query3(1 , 1 , n , vl , vl);
        //cout << vc << '\n';
        int sum = query3(1 , 1 , n , 1 , vl - 1)*vc - query1(1 , 1 , n , 1 , vl - 1) - vc*query3(1 , 1 , n , vl + 1 , n) + query1(1 , 1 , n , vl + 1 , n); 
        if (sum <= k) return true;
    }
    return false;
}

void solve() {
    cin >> n >> k;
    int mn = inf;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        mn = min(mn , a[i]);
    }
    for (int i = 1 ; i <= n ; i++) {
        a[i] -= mn; 
        a[i] -= i;
    }
    set<int> s;
    for (int i = 1 ; i <= n ; i++) {
        s.insert(a[i]);
    }
    int idx = 0;
    for (int x : s) {
        mp[x] = ++idx;
    }

    for (int i = 1 ; i <= n ; i++) {
        b[i] = mp[a[i]];
    }
    // for (int i = 1 ; i <= n ; i++) {
    //     cerr << b[i] << " ";    
    // }
    // cerr << '\n';
    // for (int i = 1 ; i <= n ; i++) {
    //     cerr << a[i] << " ";
    // }
    // cerr << '\n';
    int l = 1 , r = 1;
    int ans = 1; 
    while (r <= n) {
        update1(1 , 1 , n , b[r] , a[r]); 
        update2(1 , 1 , n , b[r] , 1);
        if (check(r - l + 1)) {
            ans = max(ans , r - l + 1);
        }
        else {
            while (!check(r - l + 1)) {
                update1(1 , 1 , n , b[l] , -a[l]); 
                update2(1 , 1 , n , b[l] , -1);
                l++;
            }
        }
        r++;

    }    
    cout << ans << '\n';
    init();
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    cin >> test;
    while (test--) {
        solve();
    }

}