#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 5e3 + 7;
const int MOD = 1e9 + 7;

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    string a , b; cin >> a >> b;
    int n = a.size() , m = b.size();
    a = ' ' + a; b = ' ' + b;
    vector<vector<int>> f(n + 1 , vector<int> (m + 1 , inf));
    f[0][0] = 0;
    for (int i = 1 ; i <= n ; i++) f[i][0] = i;
    for (int i = 1 ; i <= m ; i++) f[0][i] = i;
    for (int i = 1 ; i <= n ;i ++) {
        for (int j = 1 ; j <= m ; j++) {
            if (a[i] == b[j]) f[i][j] = f[i - 1][j - 1];
            else {
                // replace
                int x_1 = f[i - 1][j - 1] + 1;
                // add 
                int x_2 = f[i][j - 1] + 1;
                // remove
                int x_3 = f[i - 1][j] + 1;
                f[i][j] = min({f[i][j] ,x_1 , x_2 , x_3});
            }
        }
    }
    // for (int i = 1 ; i <= n ;i ++) {
    //     for (int j = 1 ; j <= m ; j++) {
    //         cout << f[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    cout << f[n][m];
    return 0;
}