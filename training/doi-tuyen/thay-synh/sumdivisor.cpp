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
const int TWO_MOD_INV = 500000004;

int pw(int base , int x) {
    if (x == 0) return 1; 
    int child = pw(2 , x / 2)%MOD; 
    if (x % 2 == 0) return (child*child)%MOD; 
    else return ((child*child)%MOD*base)%MOD;
}

void solve() {
    int n; cin >> n;
    int total = 0; 
    for (int i = 1,j ; i <= n ; i = j) {
        int q = n / i; 
        j = n/q+ 1; 
        int jump = (((j%MOD)*((j - 1)%MOD))%MOD*pw(2 , MOD - 2)%MOD)%MOD;
		int prevjump = (((i%MOD)*((i - 1)%MOD))%MOD*pw(2 , MOD - 2)%MOD)%MOD;
		int calc = (jump - prevjump + MOD)%MOD;
		total = (total + (q%MOD)*calc)%MOD;
    }
    cout << total;
}

signed main() {
	int test = 1;
	//cin >> test;
	while(test--) {
		solve();
	}
	return 0;
}