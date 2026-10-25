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
const int MAX_N = 100;
const int MOD = 1e9 + 7;

int a[30000];
int f[300];
int b[30000];
int maxi = 0;
int ans = 0;

struct seg{
    int val , lz;
};

seg IT[4 * 30000];

int ls(int id) {
    return (id << 1);
}

int rs(int id) {
    return ls(id) + 1;
}

void down(int id) {
    int x = IT[id].lz;
    IT[ls(id)].val += x;
    IT[rs(id)].val += x;
    IT[ls(id)].lz += x;
    IT[rs(id)].lz += x;
    IT[id].lz = 0;
    return;
}

void build(int id , int l , int r) {
    if (l == r) {
        IT[id].val = b[l];
        return;
    }
    int mid = (l + r)/2;
    build(ls(id) , l , mid);
    build(rs(id) , mid + 1 , r);
    IT[id].val = max(IT[ls(id)].val , IT[rs(id)].val);
}

void calc(int id , int l , int r) {
    int x = IT[id].val;
    int val = max(0ll , maxi - x);
    if (l == r) {
        IT[id].val += val;
        ans += val;
        //cout << l << " " << r << " " << ans << '\n';
        return; 
    }
    IT[id].val += val;
    IT[id].lz += val;
    ans += val;
    down(id);
    //cout << l << " " << r << " " << ans << '\n';
    int mid = (l + r)/2;
    calc(ls(id) , l , mid);
    calc(rs(id) , mid + 1 , r);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    f[0] = 1;
    for (int i = 1 ; i <= 11 ; i++) {
        f[i] = f[i - 1] * 2;
    }
    int n; cin >> n;
    for (int i = 1 ; i < (f[n + 1] - 1) ; i++) {
        cin >> a[i];
        //cout << a[i] << " ";
    }
    int cnt = 0;
    for (int i = f[n] ; i <= (f[n + 1] - 1) ; i++) {
        int x = i;
        int total = 0;
        while (x > 0) {
            total += a[x - 1];
            x/=2;
        }
        b[++cnt] = total;
        maxi = max(maxi , total);
    }
    build(1 , 1 , f[n]);
    calc(1 , 1 , f[n]);
    cout << ans;
    return 0;
}