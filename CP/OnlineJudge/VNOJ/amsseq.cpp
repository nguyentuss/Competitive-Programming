#include <bits/stdc++.h>

using namespace std;

vector <int> f(10007 , INT_MIN);
int n , k;
vector <int> v(10007);

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);	
	cout.tie(NULL);
	cin >> n >> k;
	for (int i = 1 ; i <= n ; i++) cin >> v[i];
	f[0] = 0;
	for (int i = 0 ; i <= n ; i++) {
		for (int j = i + 1 ; j <= min(i + k, n) ; j++) {
			f[j] = max(f[j] , f[i] + v[j]);
		}
	}
	int ans = INT_MIN;
	for (int i = 1 ; i <= n; i++) 
		ans = max(ans , f[i]);
	cout << ans;

	return 0;
}