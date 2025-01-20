// https://oj.uz/problem/view/IZhO14_blocks
#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

int a[N] , b[N]; 
int f[N][107];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , k; cin >> n >> k;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    for (int i = 1 ; i <= n ;i ++) {
        for (int j = 0 ; j <= k ; j++) {
            f[i][j] = inf;
        }
    }
    a[0] = inf;
    f[0][0] = 0;
    for (int j = 1 ; j <= k ; j++) {
        deque<ii> dq;
    dq.push_back(ii(0 , inf));
        for (int i = j ; i <= n ;i ++) {
            int cxcuti = f[i - 1][j - 1];
            while (!dq.empty() && a[dq.back().fi] <= a[i]) {
                cxcuti = min(cxcuti , dq.back().se);
                dq.pop_back();
            } 
            if (dq.back().fi > 0) f[i][j] = f[dq.back().fi][j];
            f[i][j] = min(f[i][j] ,cxcuti + a[i]);
            dq.push_back(ii(i , min(f[i][j] , cxcuti)));
        }
    }
    // for (int j = 1 ; j <= k ; j++) {
    // for (int i = 1 ; i <= n ; i++) {
    //         cout << f[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    cout << f[n][k];
    return 0;
}