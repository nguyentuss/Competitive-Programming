#include <bits/stdc++.h>

using namespace std;

#define ii pair<int ,int> 
#define x first
#define y second

bool cmp(ii &a , ii &b) {
	return a.y < b.y;
}
vector <ii> v;
map<int , int> cnt;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		int r , c; cin >> r >> c;
		v.push_back(ii(r , c));
	}
	sort(v.begin() , v.end() , cmp);
	int ans = 1;
	for (int i = 0 ; i < n ; i++) {
		int x = v[i].x , y = v[i].y;
		int l = x - y , r = x + y , c = 1;
		while (cnt.find(r) != cnt.end() && (l = cnt[r]) >= x - y) {
			r = l;
		}
		if (r == x - y) c++; 
		ans += c;
		cnt[x + y] = x - y;
	}
	cout << ans;
	return 0;
}