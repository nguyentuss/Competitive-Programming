//source:: 
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define repn(i ,a, b) for(int i = a; i <= (b); ++i)
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define vi vector<int>
#define fi first
#define se second
#define int long long
#define sz(a) (int) a.size()
typedef unsigned __int128 ull;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;

int f[107][107];

void solve() {
    string s; cin >> s;
    int n = s.size();
    s = " " + s; 
    for (int j = 1 ; j <= n ; j++) {
        f[j][j] = 1;
        for (int i = j - 1 ; i >= 1 ; i--) {
            f[i][j] = max(f[i + 1][j] , f[i][j - 1]);
            if (s[i] == s[j]) {
                f[i][j] = max(f[i][j]  , f[i + 1][j - 1] + 2);
            }
        }
    }
    cout << f[1][n];
}

main() {
	int test = 1;
	//cin >> test;
	while(test--) {
		solve();
	}
	return 0;
}