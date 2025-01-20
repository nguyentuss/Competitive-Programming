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
//#define int long long
const int inf = 1e9 + 7;
const int MAX_N = 5e2 + 7;
const int MOD = 1e9 + 7;

char a[MAX_N][MAX_N];
char s[5007];
bitset<507> dp[2][MAX_N];
bitset<507> d[MAX_N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , m , l; cin >> n >> m >> l;
    //subtask 3
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                cin >> a[i][j];
                if (a[i][j] == '#') {
                    d[i][j] = 0;
                    dp[1][i][j] = 0;
                }
				else {
					d[i][j] = 1;
					dp[1][i][j] = 1;
				}
            }
        }
        for (int i = 0 ; i < l ; i++) {
            cin >> s[i];
        }
        for (int i = 0 ; i < l ; i++) {
            int now = i & 1;
            int prev = now ^ 1;
            for (int j = 0 ; j < n ; j++) {
                if (s[i] == 'W') {
                    dp[now][j] = dp[prev][j] >> 1;
                }
                else if (s[i] == 'E') {
                    dp[now][j] = dp[prev][j] << 1;
                }
                else if (s[i] == 'S') {
                    dp[now][j] = dp[prev][j - 1];
                }
                else if (s[i] == 'N') {
                    dp[now][j] = dp[prev][j + 1];
                }
                else if (s[i] == '?') {
                    dp[now][j] = (dp[prev][j] >> 1);
                    dp[now][j] |= (dp[prev][j] << 1);
					if ((j - 1) >= 0)
                    dp[now][j] |= dp[prev][j - 1];
					if ((j + 1) < n)
                    dp[now][j] |= dp[prev][j + 1];
                }
            }
            for (int j = 0 ; j < n ; j++) {
                dp[now][j] = dp[now][j] & d[j];
                dp[prev][j] = dp[now][j];
            }
			// for (int j = 0 ; j < n ; j++) {
			// 	dp[now][j].reset
			// }
        }
        int ans = 0;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (dp[(l - 1) & 1][i][j]) {
                    ans++;
                }
				//cout << dp[(l - 1) & 1][i][j] << " ";
            }
			//cout << '\n';
        }
        cout << ans;
    //}
    return 0;
}

// 1 1 0 0 0 0 1 1 0 
// 1 1 0 0 0 0 1 1 0 
// 1 1 0 1 1 1 1 0 0 
// 1 0 0 1 1 1 0 1 0 
// 1 0 1 1 0 1 1 1 1