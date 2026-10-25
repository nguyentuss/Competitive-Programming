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
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1; 
    //cin >> test;
    while (test--) {
        int n; cin >> n;
        vector<vector<int>> a(n , vector<int>(4 , inf));
        for (int i = 0 ; i < n ; i++) {
            cin >> a[i][0] >> a[i][1] >> a[i][2]; 
        }
        vector<int> f(n + 1);
        f[0] = 0;
        f[1] = min({a[0][0] , a[0][1] , a[0][2]});
        if (n > 1) {
            f[2] = min({min({a[1][0] , a[1][1] , a[1][2]}) + f[1] , a[0][1] , a[0][2]});
        }
        for (int i = 3 ; i <= n ; i++) {
            f[i] = min({f[i - 1] + min({a[i - 1][0] , a[i - 1][1] , a[i - 1][2]}) , f[i - 2] + min(a[i - 2][1] , a[i - 2][2]) , f[i - 3] + a[i - 3][2]});
        }
        cout << f[n];
    }
    return 0;
}