#include <bits/stdc++.h>

using namespace std;

#define ii pair<int ,int>
#define f first
#define s second
#define inf (int) (1e9 + 7)

int n;
ii v[20];
int X[20];
int ans = inf;

void process() {
	int cnt =0;
	int dang = 0 , chua = 1;
	for (int i = 1 ; i <= n ; i++) {
		dang += v[i].s*X[i];
		if (X[i] != 0)
			chua *= v[i].f*X[i];
		cnt += X[i];
	}
	if (cnt != 0) 
	ans = min(ans , abs(dang - chua));
}

void backtr(int i) {
	for (int j = 0 ; j <= 1 ; j++) {
		X[i] = j;
		if (i == n) process();
		else backtr(i + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("phohn.inp","r",stdin);
	freopen("phohn.out","w",stdout);
	cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		cin >> v[i].f >> v[i].s;
	}
	backtr(1);
	cout << ans;

	return 0;
}