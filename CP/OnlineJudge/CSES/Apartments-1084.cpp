#include <bits/stdc++.h>

using namespace std;

int n , m , k;
multiset<int> mini;
multiset<int , greater<int>> maxi;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0 ; i < n ; i ++) {
		int x; cin >> x;
		v.push_back(x);
	}
	for (int i = 0 ; i < m ; i++) {
		int x; cin >> x;
		mini.insert(x);
		maxi.insert(x);
	}
	sort(v.begin() , v.end());
	int ans = 0;
	for (int i = 0 ; i < n ; i++) {
		auto tmp1 = mini.lower_bound(v[i] - k);
		auto tmp2 = maxi.lower_bound(v[i] + k);
		//if (*tmp1 > *tmp2) continue;	
		if (tmp1 != mini.end() && *tmp1 <= (v[i] + k)) {
			ans ++;
			mini.erase(tmp1);
			maxi.erase(maxi.find(*tmp1));
		}
		else if (tmp2 != maxi.end() && *tmp2 >= (v[i] - k)) {
			ans ++;
			mini.erase(mini.find(*tmp2));
			maxi.erase(tmp2);
		}
	}
	cout << ans;
	return 0;
}