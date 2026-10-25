#include <bits/stdc++.h>

using namespace std;

#define inf (ll) (1e18)
#define ll long long

int n , len = 0;
int a[10];
int x[10];
bool C[10];
ll ans = inf;

void write() {
	ll tmp = 0;
	for (int i = 1 ; i <= len ; i++) {
		tmp *= 10;
		tmp += a[x[i]];
	}
	if (n < tmp) {
		ans = min(ans , tmp);
	}
}

void quaylui(int i) {
	for (int j = 1 ; j <= len ; j++) {
		if (C[j] == false) {
			x[i] = j;
			C[j] = true;
			if (i == len) write();
			else quaylui(i + 1);
			C[j] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("more.inp","r",stdin);
	freopen("more.out","w",stdout);
	cin >> n;
	int tmp = n;
	while (tmp > 0) {
		len++;
		a[len] = tmp % 10;
		tmp /= 10;
	}
	quaylui(1);
	if (ans == inf) cout << -1;
	else cout << ans;

	return 0;
}