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
const int MAX_V = 1e6;
const int MOD = 1e9 + 7;

int lz[4*MAX_V];
int IT[4*MAX_V];
int n , m , a[MAX_N] , b[MAX_N];

int ls(int id) {
    return (id << 1);
}
int rs(int id) {
    return ((id << 1) + 1);
}


void down(int id) {
    int x = lz[id];
    IT[ls(id)] += x;
    IT[rs(id)] += x;
    lz[ls(id)] += x;
    lz[rs(id)] += x;
    lz[id] = 0;
    return ;
}

void update(int id , int l , int r , int L , int R , int val) {
    if (l > R || r < L) return;
    if (l <= L && R <= r) {
        IT[id] += val;
        lz[id] += val;
        return;
    }
    down(id);
    int mid = (L + R)>>1;
    update(ls(id) , l , r , L , mid , val);
    update(rs(id) , l , r , mid + 1 , R , val);
    IT[id] = max(IT[ls(id)] , IT[rs(id)]);
    return;
}

int get(int id , int l , int r) {
    if (IT[id] < 1) return -1;
    if (l == r) return l;
    int mid = (l + r)>>1;
    down(id);
    if (IT[rs(id)] >= 1) {
        return get(rs(id) , mid + 1 , r);
    } 
    if (IT[ls(id)] >= 1) {
        return get(ls(id) , l , mid);
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        update(1 , 1 , a[i] , 1 , MAX_V , 1);
    }
    for (int i = 1 ; i <= m ; i++) {
        cin >> b[i];
        update(1 , 1 , b[i] , 1 , MAX_V , -1); 
    }
    int q; cin >> q;
    for (int i = 1 ; i <= q ;i ++) {
        int k , p , x; cin >> k >> p >> x;
        if (k == 1) {
            update(1 , 1 , a[p] , 1 , MAX_V , -1);
            a[p] = x;
            update(1 , 1 , a[p] , 1 , MAX_V , 1);
        }
        else {
            update(1 , 1 , b[p] , 1 , MAX_V , 1);
            b[p] = x;
            update(1 , 1 , b[p] ,1 , MAX_V , -1);
        }
        cout << get(1 , 1 , MAX_V) << '\n';
    }

    return 0;
}