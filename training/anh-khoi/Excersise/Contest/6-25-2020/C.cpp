#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2*1e5 + 7)

int n, lef , righ;
vector <int> v;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int t , x; cin >> t;
	while (t--) {
		v.clear();
		cin >> n >> lef >> righ;
		for (int i = 1 ; i <= n ; i ++) {
			cin >> x;
			v.push_back(x);
		}
		sort(v.begin() , v.end());
		long long ans = 0;
		for (int i = 1 ; i < n ; i++) {
			if (v[i] < righ) {
				int l , r , rightpos = -1 , leftpos = -1;
				l = 0 , r = i;
				while (l <= r) {
					int mid = (l + r)/2;
					if (v[mid] <= (righ - v[i]) && mid != i) {
						rightpos = mid;
						l = mid + 1;
					}
					else {
						r = mid - 1;
					}
				}
				if (rightpos == -1) continue;
				l = 0 , r = rightpos;
				while (l <= r) {
					int mid = (l + r)/2;
					if ((v[i] + v[mid]) >= lef && i != mid && (v[i] + v[mid]) <= righ) {
						leftpos = mid;
						r = mid - 1;
					}
					else 
						l = mid + 1;
				}
				//cout << leftpos << " " << rightpos << '\n';
				if (leftpos != -1)
					ans += rightpos - leftpos + 1;
			//	cout << ans << '\n';
			}
			else break;
		}
		cout << ans << '\n';
	}

	return 0;
}