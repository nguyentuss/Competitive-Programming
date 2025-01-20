#include <bits/stdc++.h>
 
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
 
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long
const int inf = 1e9 + 7;
const int MAX_N = 3e5 + 7;
const int MOD = 1e9 + 9;

int n , m;
int a[MAX_N];
int f[MAX_N];
int IT[4 * MAX_N];
ii lz[4 * MAX_N];

int ls(int id) {
    return (id << 1);
}
int rs(int id) {
    return (ls(id) + 1);
}

void build(int id , int l , int r) {
    if (l == r) {
        IT[id] = a[l];
        return;
    }
    int mid = (l + r)>>1;
    build(ls(id) , l , mid);
    build(rs(id) , mid + 1 , r);
    IT[id] = IT[ls(id)] + IT[rs(id)];
    return;
}

void down(int id , int l , int r) {
    int a = lz[id].fi;
    int b = lz[id].se;
    //cerr << id << " " << a << " " << b << '\n';
    int len = (r - l + 1) + 2;
    IT[id] = ((IT[id] + b*f[len - 1]%MOD + a*f[len - 2]%MOD)%MOD - b + MOD)%MOD;
    if (l != r) {
        int mid = (r - l)>>1;
        lz[ls(id)].fi = (lz[ls(id)].fi + a)%MOD;
        lz[ls(id)].se = (lz[ls(id)].se + b)%MOD;
        lz[rs(id)].fi = (lz[rs(id)].fi + b*f[mid + 1]%MOD + a*f[mid]%MOD)%MOD;
        lz[rs(id)].se = (lz[rs(id)].se + b*f[mid + 2]%MOD + a*f[mid + 1]%MOD)%MOD;
    }
    lz[id] = ii(0 , 0);
}

void update(int id , int l , int r , int L , int R) {
    down(id , L , R);
    if (l > R || r < L) return;
    if (l <= L && R <= r) {
        int len = L - l + 1;
        lz[id].fi = (lz[id].fi + f[len])%MOD;
        lz[id].se = (lz[id].se + f[len + 1])%MOD;
        down(id , L , R);
        return; 
    }
    int mid = (L + R)>>1;
    update(ls(id) , l , r , L , mid);
    update(rs(id) , l , r , mid + 1 , R);
    IT[id] = (IT[ls(id)] + IT[rs(id)])%MOD;
    return;
}

int get(int id , int l , int r , int L , int R) {
    down(id , L , R);
    if (l > R || r < L) return 0;
    if (l <= L && R <= r) {
        return IT[id];
    }
    int mid = (L + R)>>1;
    return (get(ls(id) , l , r , L , mid) + get(rs(id) , l , r , mid + 1 , R))%MOD;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    build(1 , 1 , n);
    f[1] = 1;
    f[2] = 1;
    for (int i = 3 ; i < MAX_N ;i ++) {
        f[i] = (f[i - 1] + f[i - 2])%MOD;
    }
    for (int i = 1 ; i <= m ; i++) {
        int k , l , r; cin >> k >> l >> r;
        if (k == 1) {
            update(1 , l , r , 1 , n);
        }
        else {
            cout << get(1 , l , r , 1 , n) << '\n';
        }
    }
    return 0;
}