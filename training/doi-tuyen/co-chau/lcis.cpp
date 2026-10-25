#include <bits/stdc++.h>
using namespace std;

#define MAX_N (int) (5e3 + 7) 

int a[MAX_N] , b[MAX_N];
int f[MAX_N] , trace[MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("lcis.inp","r",stdin);
	freopen("lcis.out","w",stdout);
	int n , m; cin >> n;
	for (int i = 1 ; i <= n ; i++) 
		cin >> a[i];
	cin >> m;
	for (int i = 1 ; i <= m ; i++) 
		cin >> b[i];
	for (int i = 1 ; i <= n ; i++) {
		int current = 0;
		int pos = 0;
		for (int j = 1 ; j <= m ; j ++) {
			if (a[i] == b[j]) {
				if (f[j] < current + 1) {
					f[j] = current + 1;
					trace[j] = pos;
				}
			}
			else if (a[i] > b[j]) {
				if (current < f[j]) {
					current = f[j];
					pos = j;
				}
			}
		}
	}
	int ans = 0;
	int pos = 0;
	for (int i = 1 ; i <= m ;i++) {
		if (ans < f[i]) {
			ans = f[i];
			pos = i;
		}
	}
	cout << ans << '\n';
	vector<int> v;
	while (pos != 0) {
		v.push_back(b[pos]);
		pos = trace[pos];
	}
	reverse(v.begin() , v.end());
	for (auto x : v) cout << x << " ";
	return 0;
}