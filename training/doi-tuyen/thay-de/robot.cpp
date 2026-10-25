#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#define MAX_M (int) (3e5 + 7)
#define int long long

int x[MAX_N] , y[MAX_N];
int f1[MAX_N] , f2[MAX_N];
int n , m;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("robot.inp","r",stdin);
	freopen("robot.out","w",stdout);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) 
		cin >> x[i] >> y[i];
	sort(x + 1 , x + 1 + n);
	sort(y + 1 , y + 1 + n);
	for (int i = 1 ; i <= n ; i++) {
		f1[i] = f1[i - 1] + x[i];
		f2[i] = f2[i - 1] + y[i];
	}
	int nwx = 0 , nwy = 0;
	for (int i = 1 ; i <= m ; i++) {
		char ch; cin >> ch;
		if (ch == 'I') nwx++;
		if (ch == 'S') nwy++;
		if (ch == 'J') nwy--;
		if (ch == 'Z') nwx--;
		//cout << nwx << " " << nwy << '\n';
		int l , r;
		int pos = 0 , total = 0;
		l = 1 , r = n;
		while (l <= r) {
			int mid = (l + r)/2;
			if (nwx >= x[mid]) {
				l = mid + 1;
				pos = mid;
			}
			else r = mid - 1;
		}
		//cout << pos << '\n';
		total = pos*nwx - f1[pos] + f1[n] - f1[pos] - (n - pos)*nwx;
		l = 1 , r = n , pos = 0;
		while (l <= r) {
			int mid = (l + r)/2;
			if (nwy >= y[mid]) {
				l = mid + 1;
				pos = mid;
			}
			else r = mid - 1;
		}
		total += pos*nwy - f2[pos] + f2[n] - f2[pos] - (n - pos)*nwy;
		cout << total << '\n';
	}
	return 0;
}