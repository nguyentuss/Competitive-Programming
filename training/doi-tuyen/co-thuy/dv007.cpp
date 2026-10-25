#include <bits/stdc++.h>

using namespace std;

vector <int> v;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("dv007.inp","r",stdin);
	freopen("dv007.out","w",stdout);

	int n, r , x; cin >> n >> r;

	for (int i = 0 ; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin() , v.end() , greater<int>());

	long long ans = 0;
	int counted = 0;

	for (int i = 0 ; i < n ; i++) {
		counted = 0;
		for (int j = i + 1 ; j < n; j++){
			if (counted == n - 1) {
				cout << ans;
				return 0;
			}  
			if (v[i] - v[j] > r) {
				ans += n - j;
				break;
			}
			else counted ++;
		}
	}
	cout << ans;


	return 0;
}