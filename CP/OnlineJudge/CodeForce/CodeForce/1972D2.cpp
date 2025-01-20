//source:: 
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e18 + 7;

bool check(int a , int b) {
    //return ((a + b) % (b * __gcd(a , b)) == 0);
    return ((b * __gcd(a , b)) % (a + b) == 0);
}

int f(int a, int d) {
    return a / d;
}

int count(int l, int r, int d) {
    return f(r, d) - f(l-1, d);
}

int lcm(int a, int b) {
    return a / __gcd(a, b) * b;
}

void solve() {
    int n , m; cin >> n >> m;
    // for (int i = 1 ; i <= n ; i++) {
    //     for (int j = 1 ; j <= m ; j++) {
    //         if (check(i , j)) {
    //             cout << i << " " << j << '\n';
    //         }
    //     }
    // }
    
    int res = 0;

    for (int q = 1 ; q * q <= n ; q++) {
        for (int p = 1 ; p * p <= m ; p++) {
            if (__gcd(p, q) == 1) {
                int s = p + q;
                int d = lcm(s, p) / p;
                int k = min(n / q, m / p);
                res += f(k, d);
                // cout << q << " " << p << " " << f(k, d) << "\n";
            }
        }
    }

    cout << res << "\n";
    
}

main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); 
	cout.tie(NULL);
	int test = 1;
	cin >> test;
	while(test--) {
		solve();
	}
	return 0;
}

// (2,2),(3,6),(4,4),(6,3),(6,6),(8,8)
// (1,1),(1,2),(1,1),(2,1),(1,1),(1,1)