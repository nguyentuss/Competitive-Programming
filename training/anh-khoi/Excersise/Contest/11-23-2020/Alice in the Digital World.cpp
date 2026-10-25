#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define fi freopen("inp.inp","r",stdin);
#define fo freopen("out.out","w",stdout);

int main() {
	boost;
	fi;fo;
	int t; cin >> t;
	while (t --){
		long long n , m , x , count = 0 , ans = LLONG_MIN , left , s = 0;
		vector<int> v;
		cin >> n >> m;
		for (int i = 0 ; i < n ; i++) {
			cin >> x;
			v.push_back(x);
		}
		for (int i = 0 ; i < n  ; i++) {
			if (v[i] == m) {
				count ++;
				if (count == 1) {
					left = i;
					s += v[i];
					if (i == n - 1) ans = max(s,ans);
				} 
				if (count > 1) {
					i = left;
					ans = max(s,ans);
					s = 0;
					count = 0;
					if (i == n - 1) ans = max(s,ans);
				}
			}
			else {
				if (v[i] < m) {
					left = i;
					if (count == 1)
						ans = max(s,ans);
					s = 0;
					count = 0;
				}
				else if (v[i] >= m) s += v[i];
				if (i == n - 1) ans = max(s,ans);
			}
			if (i == n - 1) ans = max(s,ans);

		}
		cout << ans << endl; 
	}

	return 0;
}