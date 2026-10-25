#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (3e5 + 7)
#define ll long long
#define ngarcute ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

struct toado {
	int x , y;
};

vector<toado> cv1 , cv2;
toado v[MAX_N] , u[MAX_N];

ll ccw(toado &O , toado &A , toado &B) {
	ll tmp = ((A.x - O.x)*(B.x - O.x) - (B.x - O.x)*(B.y - O.y));
	if (tmp < 0) return -1;
	return (tmp > 0);
}

bool cmp(toado &a , toado &b) {
	ll tmp = ccw(v[1] , a , b);
	return (tmp == -1 || (!tmp && (a.y < b.y || (a.y == b.y && a.x < b.x))));

}


void build() {
	sort(v + 2 , v + n + 1 , cmp);
	sort(u + 2 , u + m + 1 , cmp);
	for (int i = 1 ; i <= n ; i++) {
		if (v[i] == v[i - 1]) continue;
		if (cv1.size() < 2) cv1.push_back(v[i]);
		else {
			while (cv1.size() >= 2 && ccw(cv1[cv1.size() - 2] , cv1[cv1.size() - 1] , v[i]) != -1) {
				cv1.pop_back();
			}
			cv1.push_back(v[i]);
		}
	}
}

int main() {
	ngarcute;
	int n; cin >> n;
	v[0] = {-1e9 , -1e9};
	u[0] = {-1e9 , -1e9};
	for (int i = 1 ; i <= n ;i++) {
		cin >> v[i].x >> v[i].y;
		if (v[i].y < v[1].y || (v[i].y == v[1].s && v[i].x < v[1].x)) swap(v[i] , v[1]);
	}
	int m; cin >> m;
	for (int i = 1 ; i <= m ; i++) {
		cin >> u[i].x >> u[i].y;
		if (u[i].y < u[1].y || (u[i].y == u[1].y && u[i].x < u[1].x)) swap(u[i] , u[1]);
	}
	build();
	return 0;
}