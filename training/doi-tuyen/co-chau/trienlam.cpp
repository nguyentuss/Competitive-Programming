#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e4 + 7)
#define ii pair<int , int>
ii v[MAX_N];
int f[MAX_N];

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("trienlam.inp","r",stdin);
	freopen("trienlam.out","w",stdout);
	int n , x , y ; cin >> n;
	for (int i = 1 ; i <= n ; i++){
		cin >> v[i].first >> v[i].second;
	}
	sort(v + 1 , v + 1 + n);
	for (int i = 1 ; i <= n ;i++) {
		f[i] = v[i].second - v[i].first;
	}
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j < i ; j++) {
			if (v[i].first >= v[j].second) f[i] = max(f[i] , f[j] + v[i].second - v[i].first);
		}
	}
	int ans = -1;
	for (int i = 1 ;i <= n ; i++) 
		ans = max(ans , f[i]);
	cout << ans;

	return 0;
}