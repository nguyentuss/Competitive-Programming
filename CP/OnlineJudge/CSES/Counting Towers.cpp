//source:: 
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long
typedef unsigned __int128 ull;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 1e6 + 7;
const int MOD = 1e9 + 7;
 
int dp[N][3];; 

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    dp[1][1] = dp[1][2] = 1;
    for (int i = 2; i < N; i++) {
        dp[i][1] = (dp[i-1][1]*4%MOD + dp[i-1][2])%MOD;
        dp[i][2] = (dp[i-1][1] + dp[i-1][2]*2%MOD)%MOD;
    }   
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << (dp[n][1] + dp[n][2])%MOD << '\n';
    }
    return 0;
}