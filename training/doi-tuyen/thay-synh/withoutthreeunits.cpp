//source:: 
#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 47;
const int MOD = 1e9 + 7;

int f[N][3];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1; 
    while (test--) {
        int n; cin >> n;
        f[0][0] = 1;
        for (int i = 1 ; i <= n ; i++) {
            f[i][0] = f[i - 1][0] + f[i - 1][1] + f[i - 1][2]; 
            f[i][1] = f[i - 1][0];
            f[i][2] = f[i - 1][1];
        }
        cout << f[n][0] + f[n][1]+ f[n][2];
    }
    return 0;
}