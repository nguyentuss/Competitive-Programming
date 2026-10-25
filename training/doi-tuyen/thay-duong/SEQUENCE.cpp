#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAX_N (int) (1e5 + 7)
#define ii pair<int , int>

vector<int> le , ri;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	freopen("sequence.inp","r",stdin);
	freopen("sequence.out","w",stdout);
	int x = 1 , ans = 0;
	le.push_back(0);
	ri.push_back(0);
	while (ans <= 1e13) {
		int tm = ans + 1;
		ans += x*floor(sqrt(x) + ceil(x/2);
		le.push_back(tm);
		ri.push_back(ans);
		x++;
	}
	sort(le.begin() , le.end());
	sort(ri.begin() , ri.end());
	int q; cin >> q;
	while (q--) {
		int askl , askr; cin >> askl >> askr;
		int numr = 0 , numl = 0;
		int l = 1 , r = x;	
		while (l <= r) {
			int mid = (l + r)/2;
			if (askr >= le[mid]) {
				l = mid + 1;
			}
			else {
				numl = mid;
				r = mid - 1;
			}
		}
		l = 1 , r = x;
		while (l <= r) {
			int mid = (l + r)/2;
			if (askl <= ri[mid]) {
				r = mid - 1;
			}
			else {
				numr = mid;
				l = mid + 1;
			}
		}
		numr++ , numl--;
		//cout << numr << " " << numl << '\n';
		cout << numl - numr + 1 << '\n';
	}

	return 0;
}