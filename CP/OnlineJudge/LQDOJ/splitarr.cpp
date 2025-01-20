#include <bits/stdc++.h>
using namespace std ;

#define ll long long
#define ull unsigned long long
#define fastio ios_base::sync_with_stdio(0)

ll a[1000005], d[1000005], n, l = 1e8, r = 1e8 ;

int main() {
	cin >> n ;
	for(ll i = 1; i <= n; i ++) cin >> a[i], d[i] = d[i - 1] + a[i] ;
	if(d[n] % 3 != 0) cout << -1 ;
	else {
		for(ll i = 1; i <= n; i ++) {
			if(d[i] == d[n] / 3) l = min(l, i - 1) ;
			if(d[i] == d[n] / 3 * 2) r = min(r, i - 1) ;
			cout << l << " " << r << endl;
		}
		if(l == 1e8 || r == 1e8) cout << -1 ;
		else cout << l << " " << r ;
	}
}