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
const int N = 1e2 + 7;
const int M = 1e6 + 7;
const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    int s; cin >> s;
    vector<vector<int>> P(n + 1 , vector<int>(s + 1 , -1));
    vector<vector<int>> f(n + 1 , vector<int>(s + 1 , inf));
    f[0][0] = 0;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 0 ; j <= s ; j++) {
            f[i][j] = f[i - 1][j];
            if (j - c[i] >= 0 && f[i - 1][j - c[i]] != inf) {
                f[i][j] = min(f[i][j] , f[i - 1][j - c[i]] + 1);
                P[i][j] = c[i];
            }
        }
    }
    if (f[n][s] == inf) {
        cout << "No solution";
    }
    else {
        vector<int> trace;
        int x = n , y = s;
        while (x > 0 && y > 0) {
            if (P[x][y] != -1) {
                trace.push_back(P[x][y]); 
                y = y - P[x][y];
                x --;
            }
            else {
                x --;
            }
        }
        reverse(trace.begin() , trace.end()); 
        for (int x : trace) cout << x << " ";
    }
    
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1; 
    //cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}