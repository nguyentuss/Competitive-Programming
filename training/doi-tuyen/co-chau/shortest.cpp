#include <bits/stdc++.h>

using namespace std;
#define int long long

map<int , bool> cnt;
int POW[40];
int f[40];
int hx , hy , hlca;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("shortest.inp","r",stdin);
	freopen("shortest.out","w",stdout);
	int x , y; cin >> x >> y;
	int tmp1 = x , tmp2 = y;
	while (tmp1 != 0) {
		cnt[tmp1] = true;
		tmp1 /= 2;
	}
	int lca = 1;
	while (tmp2 != 0) {
		if (cnt[tmp2]) {
			lca = tmp2;
			break;
		} 
		tmp2 /= 2;
	}
	POW[0] = 1;
	for (int i = 1 ; i <= 35 ; i++) {
		POW[i] = POW[i - 1]*2;
	}
	int height = 0;
	for (int i = 0 ; i <= 35 ; i++) {
		f[i] = f[i - 1] + POW[i];
		if (POW[i] <= x && x <= f[i]) hx = height;
		if (POW[i] <= y && y <= f[i]) hy = height;
		if (POW[i] <= lca && lca <= f[i]) hlca = height;
		height++;
	}
	cout << hx + hy - 2*hlca;
	return 0;
}