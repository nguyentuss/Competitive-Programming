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

int f[MAX_N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    f[0] = 1;
    int sum = 1;
    for (int i = 1 ; i <= n ;i ++) {
        for (int j = 0 ; j <= min(6ll , i) ; j++) {
            (f[i] += f[i - j])%=MOD;
        }
    }
    cout << f[n];
    return 0;
}