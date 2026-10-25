#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("certif.inp","r",stdin);
#define fo freopen("certif.out","w",stdout);

vector<int> v;

int main() {
	boost;
	fi;fo;
	int n; cin >> n;

	int x;
	for (int i = 0 ; i < n; i++) {
		cin >> x;
		if (x != 0)
			v.push_back(x);
	}

	sort(v.begin() , v.end());
	long long ans = 0;
	//for (int i = 0 ; i < (int) v.size() ; i++) cout << v[i] << " ";
	for (int i = 0 ; i < (int) v.size() - 1; i++) {
		if (v[i] != 0) {
			ans += v[i] + 1;
		}
	}
	cout << ans;

	return 0;
}