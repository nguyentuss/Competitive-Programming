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
const int N = 4e3 + 7;
const int MOD = 1e9 + 7;

// dnc + dp 
// f[k][i] : use i peoples assencding order 
// former f[k][i] = f[k - 1][j] + cost[i][j] (j <= i) 
// use dnc -> solving find minimum j that optimize f[k][i]
// (n * k * log(n))
vector<vector<int>> a(N + 1 , vector<int> (N + 1 , 0));
vector<vector<int>> P(N + 1 , vector<int> (N + 1 , inf));
vector<vector<int>> f(N + 1 , vector<int> (N + 1 , inf));

int cost(int l , int r) {
    if (l > r) return 0ll;
    int len = r -  l;
    return (a[r][r] - a[r][r - len - 1] - a[r - len - 1][r] + a[r - len - 1][r - len - 1]);
}

void DC(int g , int L , int R , int optL , int optR) {
    if (L > R) return;
    int mid = (L + R)/2;
    f[g][mid] = inf;
    for (int i = optL ; i <= optR ; i++) {
        int new_cost = f[g - 1][i] + cost(i + 1 , mid);
        if (f[g][mid] > new_cost) {
            f[g][mid] = new_cost;
            P[g][mid] = i;
        }
    }
    DC(g , L , mid - 1, optL , P[g][mid]);
    DC(g , mid + 1 , R , P[g][mid] , optR);
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1; 
    //cin >> test;
    while (test--) {
        int n , k; cin >> n >> k;
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= n ; j++) {
                int x; cin >> x;
                a[i][j] = x + a[i - 1][j] + a[i][j -1] - a[i - 1][j - 1];
            }
        }
        for (int i = 0 ; i <= n ; i++) 
            f[1][i] = a[i][i];
        for (int i = 2 ; i <= k ; i++) {
            DC(i , 1 , n , 1 , n);
        }
        cout << f[k][n]/2;
    }
    return 0;
}