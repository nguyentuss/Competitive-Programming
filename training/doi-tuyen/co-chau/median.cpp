#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)

int n , x; 
int v[MAX_N];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	cout.tie(NULL);
	freopen("median.inp","r",stdin);
	freopen("median.out","w",stdout);
	cin >> n >> x;
	for (int i = 1 ; i <= n ; i++) {
		cin >> v[i];
	}
	sort(v + 1 , v + 1 + n);
	int ans = 0;
	while (v[(n + 1) / 2] != x) {
		v[++n] = x;
		ans ++;
		sort(v + 1 , v + 1 + n);
	}
	cout << ans;
	return 0;
}