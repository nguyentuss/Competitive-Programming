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

struct seg {
    int l , r , val , id;
};

struct ss{
    int val , id; 
};

bool cmp1 (ss &a , ss &b) {
    return a.val < b.val;
}

bool cmp(seg &a , seg &b) {
    return a.val < b.val;
}

int ls(int x) {
    return (x << 1);
}
int rs(int x) {
    return (ls(x) + 1); 
}

ss a[MAX_N];
seg b[2*MAX_N];
int ans[2*MAX_N];
int IT[4*MAX_N];
void build(int id , int l , int r) {
    if (l == r) {
        IT[id] = 1;
        return;
    }
    int mid = (l + r)>>1; 
    build(ls(id) , l , mid);
    build(rs(id) , mid + 1 , r);
    IT[id] = IT[ls(id)] + IT[rs(id)];
    return;  
}

void update(int id , int i , int l , int r) {
    if (l > i || r < i) return;
    if (l == r) {
        IT[id] = 0;
        return;
    }
    int mid = (l + r)>>1;
    update(ls(id) , i , l , mid);
    update(rs(id) , i , mid + 1 , r);
    IT[id] = IT[ls(id)] + IT[rs(id)];
    return;
}

int get(int id , int l , int r , int L , int R){
    if (l > R || r < L) return 0;
    if (l <= L && R <= r) return IT[id];
    int mid = (L + R)>>1;
    return (get(ls(id) , l , r , L , mid) + get(rs(id) , l , r , mid + 1 , R));
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , q; cin >> n >> q;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i].val;
        a[i].id = i;
    }
    build(1 , 1 , n);
    sort(a + 1 , a + 1 + n , cmp1);
    for (int i = 1 ; i <= q ; i++) {
        cin >> b[i].l >> b[i].r >> b[i].val; 
        b[i].id = i;
    }
    sort(b + 1 , b + 1 + q , cmp);
    int l = 1;
    set<int> s;
    for (int i = 1 ; i <= q ; i++) {
        while (l <= n && a[l].val <= b[i].val) {
            update(1 , a[l].id , 1 , n);
            l++;
        }
        ans[b[i].id] = get(1 , b[i].l , b[i].r , 1 , n);
    }
    for (int i = 1 ; i <= q ;i ++) {
        cout << ans[i] << '\n';
    }
    return 0;
}