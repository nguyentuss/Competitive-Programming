#include <bits/stdc++.h>

using namespace std;

#define ii pair<int ,int>
#define x first
#define y second
#define int long long

int X[37];
int n;
ii v[37];
map<ii , int> cnt1 , cnt2; 

void calc(int l , int r) {
	int x = 0 , y = 0;
	for (int i = l ; i <= r ; i++) {
		x += v[i].x*X[i];
		y += v[i].y*X[i];
	}
	if (r == n/2) cnt1[ii(x , y)] ++;
	else cnt2[ii(x , y)]++;
}

void backtr(int l , int r) {
	for (int j = 0 ; j <= 1 ; j++) {
		X[l] = j;
		if (l == r) {
			if (l == (n/2)) calc(1 , n/2);
			else calc(n/2 + 1 , n);
		}
		else backtr(l + 1 , r);
	} 
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("vector.inp","r",stdin);
	freopen("vector.out","w",stdout);
	cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		cin >> v[i].x >> v[i].y;
	}
	int U , V; cin >> U >> V;
	if (n == 0) {
	 	cout << 0;
	 	return 0;
	}
	if (n == 1) {
		if (U == 0 && V == 0) {
			cout << 1;
		}
		else if (v[1].x == U && v[1].y == V) 
			cout << 1;
		else {
			cout << 0;
		}
		return 0;
	}
	backtr(1 , n/2);
	backtr(n/2 + 1 , n);
	int ans = 0;
	for (auto it : cnt1) {
		ans += it.second*cnt2[ii(U - it.first.first , V - it.first.second)];
	}
	cout << ans;
	return 0;
}