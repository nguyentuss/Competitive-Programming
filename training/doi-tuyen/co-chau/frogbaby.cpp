#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cmath>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("frogbaby.inp","r",stdin);
#define fo freopen("frogbaby.out","w",stdout);

vector <int> v , arr;

int main() {
	boost;
	fi;fo;

	int n , x; cin >> n;
	for (int i = 0 ; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	int count = 0;
	reverse(v.begin() , v.end());
	long long ans = 0 , time = 0;
	for (int i = 0 ; i < n ; i++) {
		if (v[i] == v[i + 1]) count ++;
		else {
			count ++;
			if (v[i] + time > 0) {
				ans += count * (v[i] + time);
				time -= count;
				count = 0;
			}
			else {
				cout << ans;
				return 0;
			}
		} 
	}
	cout << ans;

	return 0;
}