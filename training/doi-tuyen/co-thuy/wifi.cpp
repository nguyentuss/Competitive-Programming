#include <bits/stdc++.h>

using namespace std;

#define esp (double) (1e-7)
#define inf (double) (1e6 + 7)

vector<int> v;
int n , m , x;

bool check(double x) {
	int cnt = 0;
	int rou = -inf;
	for (int i = 0 ; i < v.size() ;i++) {
		if (v[i] - rou > x) {
			rou = v[i] + x;
			cnt++;
			if (cnt > n) return false;
		}
	}
	return (cnt <= n);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("test.inp","r",stdin);
	freopen("test.out","w",stdout);
	cin >> n >> m;
	for (int i = 1 ; i <= m ; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	double ans = 0;
	double l = 0 , r = 1e6;
	while (r - l > esp) {
		double mid = (l + r)/2.0;	
		//cout << mid << '\n';
		if (check(mid)) {
			r = mid;
			ans = mid;
		}
		else l = mid;
	}
	cout << fixed << setprecision(1) << ans;
	return 0;
}