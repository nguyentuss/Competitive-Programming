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
const int MAX_N = 507;
const int MOD = 1e9 + 7;
const int MAX_VAL = 1e6 + 7;

bool sieve[MAX_VAL];
set<int> s;

void eratosthenes() {
    for (int i = 2 ; i * i < MAX_VAL ; i++) {
        if (!sieve[i])
            for (int j = i * i ; j < MAX_VAL ; j+= i) {
                sieve[j] = true;
            }
    }
    for (int i = 2 ; i < MAX_VAL ; i++) {
        if (!sieve[i]) {
            s.insert(i);
        }
    }

}

int a[507][507] , b[507][507];
int f1[507][507] , f2[507][507];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    eratosthenes();
    int n , m; cin >> n >> m;
    for (int i = 1 ; i <= n ; i ++) {
        for (int j = 1 ; j <= m ; j++) {
            cin >> a[i][j];
            b[i][j] = *s.lower_bound(a[i][j]) - a[i][j];
            //cout << b[i][j] << " ";
        }
        //cout << '\n';
    }
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            f1[i][j] = f1[i][j - 1] + b[i][j];
        }
    }
    for (int j = 1 ; j <= m ; j++) {
        for (int i = 1 ; i <= n ; i++) {
            f2[i][j] = f2[i - 1][j] + b[i][j];
        }
    }
    int ans = inf;  
    for (int i = 1 ; i <= m ; i++) {
        ans = min(ans , f2[n][i]);
    }
    for (int i = 1 ; i <= n ; i++) {
        ans = min(ans , f1[i][m]);
    }
    cout << ans;

    return 0;
}