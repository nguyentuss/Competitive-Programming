#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("dethuongpair.inp","r",stdin);
#define fo freopen("dethuongpair.out","w",stdout);

int main() {
	boost;
	fi;fo;
	int n ; cin >> n;
	vector <int> a; int x;
	for (int i = 0 ; i < n; i++) {
		cin >> x;
		a.push_back(x);
	}
	int minimum = INT_MAX , ans = INT_MIN;
	int l , left , right , r;
	for (int i = 1 ; i < n ; i++) {
		if (a[i-1] < minimum) {
			minimum = a[i-1];
			l = i - 1;
		} 
		if (a[i] - minimum >= ans) {
			ans = a[i] - minimum;
			//cout << ans << endl;
			left = l; right = i;
		}
	}
	cout << left + 1 << " " << right + 1 << endl;
	cout << ans;

	return 0;
}