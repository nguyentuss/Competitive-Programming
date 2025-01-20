#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (4007)
#define ll long long

ll v[MAX_N][MAX_N];
ll L[MAX_N] , R[MAX_N];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= n ; j++) {
			cin >> v[i][j];
			L[i + j] += v[i][j];
			R[i - j + n] += v[i][j];
		}
	}
	ll sum_even = -1 , sum_odd = -1;
	ll x1 , x2 , y1 , y2;
	x1 = x2 = y1 = y2 = 0;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1; j <= n ; j++) {
			ll x = L[i + j] + R[i - j + n] - v[i][j];
			if (((i + j)&1) && x > sum_even) {
				sum_even = x;
				x1 = i , y1 = j;
			}
			if (!((i + j)&1) && x > sum_odd){
				sum_odd = x; 
				x2 = i , y2 = j;
			}
		}
	}
	cout << sum_even + sum_odd << '\n';
	cout << x1 << " " << y1 << " " << x2 << " " << y2;
	return 0;
}