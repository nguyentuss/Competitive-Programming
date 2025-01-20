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
const int MAX_N = 1e3 + 7;
const int MOD = 1e9 + 7;

int a[MAX_N][MAX_N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            cin >> a[i][j];
        }
    }
    int max_1 = 0 , max_2 = 0;
    for (int i = 1 ; i <= n ; i++) {
        vector<int> sum(2);
        for (int j = 1 ; j <= n ; j++) {
            sum[j % 2] += a[i][j];
        }
        max_1 += max(sum[0] , sum[1]);
    }
    for (int i = 1 ; i <= n ; i ++) {
        vector<int> sum(2);
        for (int j = 1 ; j <=n ; j++) {
            sum[j % 2] += a[j][i];
        }
        max_2 += max(sum[0] , sum[1]);
    }
    cout << max(max_1 , max_2);
    return 0;
}