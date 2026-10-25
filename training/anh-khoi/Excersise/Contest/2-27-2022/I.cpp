#include <bits/stdc++.h>
 
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
 
#define ii pair<int , int>
#define f first
#define s second
#define int long long
const int inf = 1e9 + 7;
const int MAX_N = 2e5 + 7;
const int MOD = 1e9 + 7;

set<int> s;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    while (n--) {
        int x; cin >> x;
        int ans = inf , res = 0;
        for (int i = 100 ; i <= 999 ; i++) {
            int tmp = i , j = i;
            while (j > 0) {
                tmp = tmp*10 + j % 10;
                j /= 10;
            }
            int dis = abs(x - tmp);
            if (ans > dis) {
                ans = dis; 
                res = tmp;
            }
        }
        cout << res << '\n';
    }
    return 0;
}

// 1, 2, 3, 5, 6, 9, 10, 15, 18, 30, 45, 90