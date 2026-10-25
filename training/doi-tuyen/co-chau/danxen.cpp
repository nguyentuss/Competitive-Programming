#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e6 + 7)

vector <int> a(MAX_N);
vector <int> color(MAX_N);
vector <int> v(MAX_N);
vector <int> c(MAX_N);
int f[MAX_N][2];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("danxen.inp","r",stdin);
	freopen("danxen.out","w",stdout);
	int n; cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 0 ; j <= 1; j++) {
			f[i][j] = INT_MIN;
		}
	}
	for (int i = 1 ; i <= n ; i++) cin >> a[i];
	for (int i = 1 ; i <= n ; i++) cin >> color[i];
	int maxi = INT_MIN , len = 0;
	for (int i = 1 ; i <= n ; i ++) {
		if (color[i] != color[i + 1]) {
			maxi = max(maxi , a[i]);
			v[++len] = maxi;
			maxi = INT_MIN;
		}
		else {
			maxi = max(maxi , a[i]);
		}
	}
	int change;
	if (color[1] == 2) change = 2;
	else change = 1;
	for (int i = 1 ; i <= len ; i++) {
		c[i] = change;
		change = change==1?2:1;
	}
	//for (int i = 1 ; i <= len ; i++) cout << v[i] << " ";
	//cout << '\n';
	//for (int i = 1 ; i <= len ; i++) cout << c[i] << " ";
	//cout <<'\n';
	f[1][c[1]==2?1:0] = v[1];
	int max1 , max2;
	max1 = max2 = INT_MIN;
	for (int i = 2 ; i <= len; i ++) {
		max1 = max(max1 , f[i - 1][0]);
		max2 = max(max2 , f[i - 1][1]);
		if (c[i] == 2) f[i][1] = max(f[i][1] , max(max1 + v[i] , v[i]));
		else f[i][0] = max(f[i][0] , max(max2 + v[i] , v[i]));
	}
	int ans = INT_MIN	;
	for (int i = 1 ; i <= len ; i++) {
	//	cout << f[i][0] << " " << f[i][1] << '\n';
		ans = max(ans , max(f[i][0] , f[i][1]));
	}
	cout << ans;

	return 0;
}