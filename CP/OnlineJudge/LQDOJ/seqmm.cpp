#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits.h>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

int ansmax = INT_MIN;
int ansmin = INT_MAX;
int ans = INT_MAX;
vector <int> v , posmax , posmin;

int main() {
	boost;
	int n , x; cin >> n;

	for (int i = 0 ; i < n; i++) {
		cin >> x;
		ansmax = max(ansmax , x);
		ansmin = min(ansmin , x);
		v.push_back(x);
	}

	for (int i = 0 ; i < n ; i++) {
		if (v[i] == ansmax) posmax.push_back(i);
		else if (v[i] == ansmin) posmin.push_back(i);
	}

	for (int i = 0 ; i < (int) posmax.size() ; i++) 
		for (int j = 0 ; j < (int) posmin.size() ; j++) {
			//cout << posmax[i] << " " << posmin[j] << endl;
			ans = min(ans, abs(posmin[j] - posmax[i]) + 1);
		}

	cout << ans;
	return 0;
}