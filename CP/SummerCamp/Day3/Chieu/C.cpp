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
const int MAX_N = 2e6 + 7;
const int MOD = 1e9 + 7;


int POW(int a , int n) {
    if (n == 1) return a;
    int child = POW(a , n / 2)%MOD; 
    if (n % 2) {
        return ((child*child)%MOD*a)%MOD;
    }
    else return (child*child)%MOD;
}

int frac[MAX_N];
int inv[MAX_N];
int f[MAX_N];
int f1[MAX_N] , fn[MAX_N];
int save[MAX_N];

int CnK(int n , int k) {
    return (frac[n]%MOD*save[k]%MOD*save[n - k]%MOD)%MOD;
}
 
ii b[MAX_N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , m , k; cin >> n >> m >> k;
    frac[0] = 1;
    for (int i = 1 ; i < MAX_N ; i++) {
        frac[i] = (frac[i - 1]*i)%MOD;
    }
    for (int i = 1 ; i <= k ; i++) {
        int x , y; cin >> x >> y;
        b[i].fi = x , b[i].se = y;
    }
    sort(b + 1 , b + 1 + k);
    for (int i = 0 ; i <= (n + m) ; i++) {
        save[i] = pow(frac[i] , MOD - 2)%MOD;
    }
    b[k + 1] = ii(n , m);
    int sum = 0;
    for (int i = 1 ; i <= k + 1 ; i++) {
        int x = b[i].fi , y = b[i].se;
        f[i] = CnK(x + y - 2 , x - 1)%MOD;
        for (int j = 1 ; j < i ; j++) {
            int nx = b[j].fi , ny = b[j].se;
            if (nx <= x && ny <= y) {
                int l_x = x - nx + 1;
                int l_y = y - ny + 1;
                f[i] = (f[i] - (f[j]*CnK(l_x + l_y - 2 , l_x - 1))%MOD + MOD)%MOD;
            }  
        }
    }
    cout << f[k + 1];
    return 0;
}                                    