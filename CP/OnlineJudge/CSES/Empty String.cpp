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
const int N = 5e2 + 7;
const int MOD = 1e9 + 7;

int f[N][N];
int C[N][N];

// f[l][r] += (f[l + 1][k - 1]*f[k + 1][r])*C(len/2)(k - 1 - l - 1+ 1);

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    string s; cin >> s;
    int n = s.size();
    for (int i = 0 ; i < N ; i++) C[i][0] = C[i][i] = 1;
    for (int i = 1 ; i < N ; i++) {
        for (int j = 1 ; j < i ; j++) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1])%MOD;
        }
    }
    for (int i = 0 ; i <= n ; i++) {
        f[i + 1][i] = 1;
    }
    s = " " + s;
    for (int r = 1; r <= n ; r++) {
        for (int l = r - 1 ; l >= 1 ; l -= 2) {
            for (int k = r - 1 ; k >= l ; k -= 2) {
                if (s[r] == s[k]) {
                    int len = (r - l + 1)/2;
                    f[l][r] = (f[l][r] + (f[l][k - 1]%MOD*f[k + 1][r - 1])%MOD*C[len][(k - l)/2]%MOD)%MOD;
                }
                // if (s[l] == s[k]) {
                //     int len = (r - l + 1)/2;
                //     f[l][r] = (f[l][r] + f[l + 1][k - 1]%MOD*f[k + 1][r]%MOD*C[len][(r - k)/2])%MOD;
                // }
            }
        }
    }
    
    cout << f[1][n]; 
    return 0;
}