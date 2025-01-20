#include <bits/stdc++.h>
 
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
 
#define ii pair<int , int>
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define v pair<iv , int>
#define fi first
#define se second
const int inf = 1e9 + 7;
const int MAX_N = 4e5 + 7 ;
const int MOD = 1e9 + 7;

int a[MAX_N];
v q[MAX_N];
int ans[MAX_N];
int IT[4*MAX_N];
int n , m;

void build(int id , int l , int r) {
    if (l == r) {
        IT[id] = 0; 
        return;
    }
    int mid = (l + r)/2;
    build(2*id , l , mid);
    build(2*id + 1 , mid + 1 , r);
    IT[id] = min(IT[2*id + 1] , IT[2*id]);
}

void update(int id , int i , int L , int R , int val) {
    if (i > R || i < L) return;
    if (L == R) {
        IT[id] = val;
        return;
    }
    int mid = (L + R)/2;
    update(2*id , i , L , mid , val);
    update(2*id + 1 , i , mid + 1 , R , val);
    IT[id] = min(IT[2*id] , IT[2*id + 1]);
}

int get(int id , int l , int r , int L , int R , int val) {
    if (r < L || l > R || IT[id] >= val) return -1;
    if (L == R) {
        return L;
    }
    int mid = (L + R)/2;
    int res = -1;
    if (IT[2*id] < val) 
        res = get(2*id , l , r , L , mid , val);
    if (res == -1 && IT[2*id + 1] < val) {
        res = get(2*id + 1, l , r , mid + 1 , R , val); 
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    build(1 , 1 , n);
    for (int i = 1; i <= n ;i ++) {
        cin >> a[i];
    }  
    for (int i = 1 ; i <= m ; i++) {
        cin >> q[i].fi.se.fi >> q[i].fi.se.se >> q[i].fi.fi.se >> q[i].fi.fi.fi;
        q[i].se = i;
    }
    sort(q + 1 , q + 1 + m);
    // for (int i = 1 ; i <= m ;i ++) {
    //     cerr << q[i].fi.se.fi << " " << q[i].fi.se.se << " " << q[i].fi.fi.se << " " <<  q[i].fi.fi.fi << '\n';
    // }
    int prevR = 0;
    for (int i = 1 ; i <= m ; i++) {
        for (int j = prevR + 1 ; j <= q[i].fi.fi.fi ; j++) {
            //cerr << a[j] << " ";
            update(1 , a[j] , 1 , n , j);
        }   
        prevR = q[i].fi.fi.fi;
        ans[q[i].se] = get(1 , q[i].fi.se.fi , q[i].fi.se.se , 1 , n , q[i].fi.fi.se);
    }
    for (int i = 1 ; i <= m ; i++) {
        if (ans[i] == -1) cout << "OK" << '\n';
        else cout << ans[i] << '\n';
    }
    return 0;
}