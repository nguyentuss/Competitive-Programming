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
const int inf = 1e18 + 7;
const int MAX_N = 2e5 + 7;
const int MOD = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> sieve(n + 1 , false);
        cout << 2 << '\n';
        for (int i = 1 ; i <= n ; i++) {
            for (int j = i ; j <= n ; j *= 2) {
                if (!sieve[j]) {
                    cout << j << " ";
                    sieve[j] = true;
                }
            }
        }
    }
    return 0;
}