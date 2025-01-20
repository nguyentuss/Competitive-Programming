#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e6 + 7)
#define ll long long

string s;
ll f[MAX_N];
vector<int> v;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> s;
	for (int i = s.size() - 1 ; i >= 0 ; i--) {
		f[i] = f[i + 1] + (s[i] == '2' ? 1 : 0);
		if (s[i] == '1') v.push_back(i); 
	}
	ll ans = 0;
	for (auto e : v) {
		ans += 1LL*f[e];
	}
	cout << ans;

	return 0;
}