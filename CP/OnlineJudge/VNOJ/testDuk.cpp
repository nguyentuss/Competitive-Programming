#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
 
using namespace std;
 
const int MOD = 1E9+7;
 
int fpow(int a, int n) {
    int tmp = 1;
    while (n) {
        if (n & 1) {
            tmp = (tmp * a) % MOD;
        }
        a = (a * a) % MOD;
        n >>= 1;
    }
    return tmp;
}
 
string s;
int res, gt[2000050], n, m;
map<char, int> cnt;
 
int choose(int k, int n) {
    int tmp = gt[n];
    tmp *= fpow(gt[k], MOD-2);
    tmp %= MOD;
    tmp *= fpow(gt[n-k], MOD-2);
    tmp %= MOD;
    return tmp;
}
 
signed main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("t.inp", "r", stdin);
    cin >> n >> m;
    gt[0] = 1;
    for (int i = 1 ; i <= n+m+1 ; i++) {
        gt[i] = (i * gt[i-1]) % MOD;
    }
    cout << choose(n-1, n+m-1);
    return 0;
}