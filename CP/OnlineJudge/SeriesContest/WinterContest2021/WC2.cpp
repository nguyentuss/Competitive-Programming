#include <bits/stdc++.h>

using namespace std;

string a;

void solve(){
	int len = a.size();
	if (a[len - 1] == '0') {
		for (int i = len - 1 ; i >= 0 ; i --) {
			if (a[i] > '0') {
				a[i] -= 1;
				break;
			}
			else a[i] = '9';
		}
	}
	else a[len - 1] -= 1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("WC2.inp","r",stdin);
	freopen("WC2.out","w",stdout);

	int t; cin >> t;
	while (t--) {
		cin >> a;
		while (a[0] == '0') a.erase(0 , 1);
		if (a.size() == 1 && a[0] == '1') {
			cout << 0 << '\n';
		}
		else {
			solve();
			if (a[0] == '0') a.erase(0 , 1);
			cout << a << '\n';
		}
	}
	return 0;
}