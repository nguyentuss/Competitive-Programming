#include <bits/stdc++.h>

using namespace std;

int cnt[257];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("silent.inp","r",stdin);
	freopen("silent.out","w",stdout);
	int n; cin >> n;
	for (int i = 1 ; i <= n ; i ++) {
		string s; cin >> s;
		cnt[s[0]]++;
	}
	int ans = 0;
	for (int i = 'a' ; i <= 'z' ; i++) {
		int x = cnt[i]/2 , y = cnt[i]/2 + cnt[i]%2;
		ans += x*(x - 1)/2 + y*(y - 1)/2;
	}
	cout << ans;
	return 0;
}