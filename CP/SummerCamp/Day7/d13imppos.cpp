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
const int MAX_N = 1e6 + 7;
const int MOD = 1e9 + 7;

int n , m , k ; 
ii a[MAX_N];
ii b[MAX_N];
ii c[MAX_N];

bool cmp(ii &a , ii &b) {
    return a.fi < b.fi; 
}
bool cmp1(ii &a , ii &b) {
    return a.se < b.se;
}

int f[MAX_N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 1 ; i <= k ;i ++) {
        cin >> a[i].fi >> a[i].se;
        b[i] = c[i] = a[i];
    }
    sort(a + 1 , a + 1 + k );
    sort(b + 1 , b + 1 + k );
    
    for (int i = 1 ; i <= k ; i++) {
        for (int j = 1 ; j < i ; j++) {
            if (a[i] >= b[j]) {
                f[i] = max(f[i] , f[j] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 1 ; i <= k ; i++) {
        ans = max(ans , f[i]);
    }  
    cout << ans;
    return 0;
}