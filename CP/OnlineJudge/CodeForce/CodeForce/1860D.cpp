#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 107;
const int MOD = 1e9 + 7;

int a[N];
int dp[N][2*N];
int f_0[N] , f_1[N];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 1 ; i <= n ; i++) {
            int x; cin >> x;
            a[i] = (int) (x - '0');
            f_0[i] = f_0[i - 1] + (a[i] == 0 ? 1 : 0); 
            f_1[i] = f_1[i - 1] + (a[i] == 1 ? 1 : 0);
        }
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= i ; j++) {
                for (int k = 0 ; i <= 100 + n ; i++) {
                    
                }
            }
        }
    }
    return 0;
}