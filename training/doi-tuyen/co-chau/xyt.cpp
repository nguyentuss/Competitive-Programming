#include <bits/stdc++.h>

using namespace std;

int n , m , x;
vector <int> v;
int ans = -1;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("xyt.inp","r",stdin);
	freopen("xyt.out","w",stdout);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin() , v.end());
	for (int i = 0 ; i < n ; i++) {
		if (v[i] > m) break;
		else ans = max(ans , v[i]);
	}
	if (v[0] + v[1] <= m)
	ans = max(ans , v[0] + v[1]);
	for (int i = 1 ; i < n ; i++) {
		int last = m - v[i];
		int j = i - 1;
		while (v[j] > last) j--;
		if (j >= 0 && v[j] <= last) ans = max(ans , v[i] + v[j]);
	}
	if (v[0] + v[1] + v[2] <= m)
		ans = max(ans , v[0] + v[1] + v[2]);
	for (int i = 2 ; i < n ; i++) {	
		int last = m - v[i];
		int j = i - 1 , k = 0;
		while (j > k) {
			while (j > k && v[j] + v[k] > last) j--;
			while (j > k && v[j] + v[k] <= last) {
				ans = max(ans , v[i] + v[j] + v[k]);
				k++;
			}
		}
	}
	cout << ans;
	return 0;
}