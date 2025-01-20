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
const int MAX_N = 5 * 1e5 + 7;
const int MOD = 1e9 + 7;

int a[MAX_N];
int sum[MAX_N];
int t[MAX_N];
int c[3][3];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n;cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        a[i] %= 3;
    }
    for (int i = 1 ; i <= n ;i++) {
        (t[i] = t[i - 1] + a[i])%=3;
        (sum[i] = sum[i - 1] + a[i]*t[i])%=3;
    }
    int ans = 0;
    c[0][0] = 1;
    for (int i = 1 ; i <= n ;i ++) {
        for (int j = 0 ; j <= 2 ; j ++) {
            for (int k = 0 ; k <= 2 ; k++) {
                if ((t[i]*(t[i - 1] - j) - (sum[i - 1] - k)) % 3 == 0) {
                    ans += c[j][k];
                }
            }
        }
        c[t[i]][sum[i]]++;
    }
    cout << ans;    
    return 0;
}