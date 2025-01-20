#include <bits/stdc++.h>

using namespace std;

#define ii pair<int ,int>
#define f first
#define s second

vector <ii> v;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	for (int i = 0 ; i < n ;i++) {
		int x , y; cin >> x >> y;
		v.push_back(ii(y , x));
	}
	sort(v.begin() , v.end());
	int ans = 1 , r = v[0].f;
	for (int i = 1 ; i < n ; i++) {
		if (v[i].s >= r) {
			ans++;
			r = v[i].f;
		}
	}
	cout << ans;
	
	return 0;
}