#include <bits/stdc++.h>

using namespace std;

struct pos {
	double x , y;
};

bool cmp(pos &a , pos &b) {
	return a.x*a.x + a.y*a.y < b.x*b.x + b.y*b.y;
}

int n;
vector <pos> v;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	freopen("nearest.inp","r",stdin);
	freopen("nearest.out","w",stdout);
	int n; cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		double x , y; cin >> x >> y;
		v.push_back({x , y});
	}
	sort(v.begin() , v.end() , cmp);
	double ans = 1e9;
	for (int i = 0 ; i < v.size() - 1 ; i++) {
		ans = min(ans , sqrt((v[i].x - v[i+1].x)*(v[i].x - v[i + 1].x) + (v[i].y - v[i + 1].y)*(v[i].y - v[i + 1].y)));
	}
	cout << fixed << setprecision(3) << ans;
	return 0;
}