#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#define int long long
#define inf (int) (1e9 + 7)

int s = 0;
int v[MAX_N];
char res[MAX_N];
signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("sum.inp","r",stdin);
	freopen("sum.out","w",stdout);
	//freopen("test.inp","r",stdin);
	int n; cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		cin >> v[i];
	}
	res[n] = '-';
	s -= v[n];
	for (int i = n - 1 ; i >= 1 ; i--) {
		if (s >= v[1]) {
			s -= v[i]; res[i] = '-'; 
		}
		else if (s <= -v[1]) {
			s += v[i]; res[i] = '+';
		}
		else {
			if (s > 0) {
				s -= v[i]; res[i] = '-';
			}
			else {
				s += v[i]; res[i] = '+';
			}
		}
	}
	for (int i = 1 ; i <= n ; i++) {
			if (s >= 0) 
				cout << res[i];
			else {
				cout << (res[i] == '+' ? '-' : '+');
			}
	}
	return 0;
}