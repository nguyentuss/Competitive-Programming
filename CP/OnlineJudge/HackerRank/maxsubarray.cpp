#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits.h>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("maxsubarray.inp","r",stdin);
#define fo freopen("maxsubarray.out","w",stdout);

int main() {
	boost;
	fi;fo;
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector <long long> v;
		long long x;bool check = false;
		long long s1 = 0;
		for (int i = 0 ; i < n ; i++) {
			cin >> x;
			v.push_back(x);
			if (x > 0) {
				check = true;
				s1 += x;
			}
		}
		check = false;
		long long s = 0, sminus = 0 , ans = LLONG_MIN , l = 0 , r = 0;
		for (int i = 0 ; i < n ; i++) {
			if (v[i] <= 0) {	
				sminus = v[i];
				if (s + sminus < 0) {
					s = 0;
					sminus = 0;
				}
				else {
					s += sminus;
				}
			}
			else {
				check = true;
				s += v[i];
				ans = max(ans , s);
			}
		}
		if (!check) {
			for (int i = 0 ; i < n ; i++) ans = max(ans,v[i]);
			s1 = ans;
		}
		cout << ans << " " << s1 << endl;
	}
	return 0;
}