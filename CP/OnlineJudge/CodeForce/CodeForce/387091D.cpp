//source:: https://codeforces.com/group/bDOIjJTvcH/contest/387091/problem/D
#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

// update 1 l r a b , add a[i] 1 luong ((i - l)*2 + 1)*a + b
// cout 2 l r sum a[l] + a[l + 1]...+a[r]


struct node{
    int lzA , lzB;
    int val;
} IT[4*N];

int a[N];

int sum(int l, int r) {
    int len = r - l + 1;
    int ret = (r + 1) * r / 2 - (l - 1) * l / 2;
    ret %= MOD;
    if (ret < 0) ret += MOD;
    return ret;
}

void lazy(int id , int l , int r) {
    int v1 = IT[id].lzA%MOD;
    int v2 = IT[id].lzB%MOD;
    int mid = (l + r)/2;
    int L = mid - l + 1;
    int R = r - mid;
    (IT[id << 1].lzA += v1)%=MOD;
    (IT[id << 1].lzB += v2)%=MOD;
    (IT[id << 1 | 1].lzA += v1)%=MOD;
    (IT[id << 1 | 1].lzB += v2)%=MOD;
    IT[id << 1].val = (IT[id << 1].val%MOD + v1*sum(l, mid))%MOD;
    IT[id << 1].val = (IT[id << 1].val%MOD + v2*L%MOD)%MOD;
    IT[id << 1 | 1].val = (IT[id << 1 | 1].val%MOD + v1*sum(mid+1, r))%MOD;
    IT[id << 1 | 1].val = (IT[id << 1 | 1].val%MOD + v2%MOD*R%MOD)%MOD;
    IT[id].lzA = 0;
    IT[id].lzB = 0;
    return;
}

void build(int id , int l , int r) {
    if (l == r) {
        IT[id].val = a[l];
        return;
    }
    int mid = (l + r)/2; 
    build(id << 1 , l , mid); 
    build(id << 1 | 1 , mid + 1 , r);
    IT[id].val = (IT[id << 1].val%MOD + IT[id << 1 | 1].val%MOD)%MOD; 
    return;
}

void update(int id , int l , int r , int L , int R , int val1 , int val2) {
    if (r < L || l > R) return;
    if (L <= l && r <= R) {
        int len = r - l + 1;
        IT[id].val = (IT[id].val%MOD + (val1*sum(l, r))%MOD + (val2*len)%MOD)%MOD;
        IT[id].lzA = (IT[id].lzA + val1)%MOD;
        IT[id].lzB = (IT[id].lzB + val2)%MOD;
        return;
    }
    int mid = (l + r) >> 1;
    lazy(id , l , r);
    update(id << 1 , l , mid , L , R , val1 , val2);
    update(id << 1 | 1 , mid + 1 , r , L , R , val1 , val2); 
    IT[id].val = (IT[id << 1].val%MOD + IT[id << 1 | 1].val%MOD)%MOD;
}

int get(int id , int l , int r , int L , int R) {
    if (r < L || l > R) return 0;
    if (L <= l && r <= R) return IT[id].val%MOD;
    int mid = (l + r) >> 1;
    lazy(id , l , r);
    return (get(id << 1 , l , mid , L , R) + get(id << 1 | 1 , mid + 1 , r , L , R))%MOD;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1;
    while (test--) {
        int n, q; cin >> n >> q;
        for (int i = 1 ; i <= n ; i++) {
            cin >> a[i];
        }
        build(1 , 1 , n);
        while (q--) {
            int status; cin >> status; 
            if (status == 1) {
                int l , r , a , b; cin >> l >> r >> a >> b;
                update(1 , 1 , n , l , r , (2*a)%MOD , ((-2*a*l)%MOD + a%MOD + b%MOD)%MOD);
            }
            else {
                int l , r; cin >> l >> r;
                cout << (get(1 , 1 , n , l , r)%MOD+MOD)%MOD << '\n';
            }
        }
    }   
    return 0;
}