#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<ll> v(107);

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int n; cin >> n;
	for (int i = 1 ; i <= n ; i++) cin >> v[i];
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= n ; j ++) {
			cout <<(ll) (v[i]^v[j]) << " ";
		}
		cout << '\n';
	}
	return 0;
}