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
const int MAX_N = 1e5 + 7;
const int MOD = 1e9 + 7;

int n , m;

struct seg {
    int val , lazy;
};

struct query {
    int x , y , k;
};

seg IT[4 * MAX_N];
query q[MAX_N];
int a[MAX_N] , b[MAX_N];

void down(int id) {
    int x = IT[id].lazy;
    IT[2 * id].val = max(IT[2 * id].val , x);
    IT[2 * id + 1].val = max(IT[2 * id + 1].val , x);
    IT[2 * id].lazy = max(IT[2 * id].lazy , x);
    IT[2 * id + 1].lazy = max(IT[2 * id + 1].lazy , x);
    IT[id].lazy = 0;
    return; 
}

void update(int id , int l , int r , int L , int R , int val) {
    if (r < L || l > R) return;
    if (l <= L && R <= r) {
        IT[id].val = val;
        IT[id].lazy = val;
        return;
    }
    down(id);
    int mid = (L + R)/2;
    update(2 * id , l , r , L , mid , val);
    update(2 * id + 1 , l , r , mid + 1 , R , val);
    IT[id].val = max(IT[2 * id].val , IT[2 * id + 1].val);
    return;
}

int get(int id , int i , int L , int R) {
    if (i > R || i < L) return 0;
    if (L == R) return IT[id].val;
    down(id);
    int mid = (L + R)/2;
    return max(get(2 * id , i , L , mid) , get(2 * id + 1 , i , mid + 1 , R));
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) 
        cin >> a[i];
    for (int i = 1 ; i <= n ; i++) 
        cin >> b[i];
    for (int i = 1 ; i <= m ; i++) {
        int t; cin >> t;
        if (t == 1) {
            cin >> q[i].x >> q[i].y >> q[i].k;
            update(1 , q[i].y  , q[i].y + q[i].k - 1 , 1 , n , i);
        }
        else {
            int x; cin >> x;
            int pos = get(1 , x , 1 , n);
            //cout << pos;
            if (pos == 0) {
                cout << b[x] << '\n';
            }
            else {
                int len = x - q[pos].y + 1;
                cout << a[q[pos].x + len - 1] << '\n';
            }
        }
    }
    return 0;
}

// 3 1 0 -1 3