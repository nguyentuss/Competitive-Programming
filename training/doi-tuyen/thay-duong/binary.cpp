#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (207)
#define int long long

int f[MAX_N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("binary.inp","r",stdin);
	freopen("binary.out","w",stdout);
	f[0] = 1 , f[1] = 2;
	for (int i = 2 ; i <= 100 ; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}
	int n; cin >> n;
	while (n--) {
		int k; cin >> k;
		int pos = upper_bound(f + 1 , f + 101 , k) - f - 1;
		int val = k;
		bitset<50> str;
		while (val) {
			str[pos] = 1;
			val -= f[pos];
			pos = upper_bound(f + 1 , f + pos , val) - f - 1;
		}
		string s = str.to_string();
		while (s[0] == '0') s.erase(0 , 1);
		cout << s << '\n';
	}

	return 0;
}