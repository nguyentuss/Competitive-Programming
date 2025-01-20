#include <bits/stdc++.h>

using namespace std;

int color[407][407];
int cnt[5][5];

void init() {
	for (int i = 0 ; i <= 400 ; i++) {
		for (int j = 0 ; j <= 400 ; j++) {
			color[i][j] = 0;
		}
	}
	for (int i = 1 ; i <= 4 ; i++) {
		for (int j = 1 ; j <= 4 ; j++) {
			cnt[i][j] =	 0;
		}
	}
}

int calc() {
	long long res = 0;
	for (int a = 1 ; a <= 4 ; a++) {
		for (int b = 1 ; b <= 4 ; b++) {
			for (int c = 1 ; c <= 4 ; c++) {
				for (int d = 1 ; d <= 4 ; d++) {
					if (a != b && a != c && a != d && b != c && b != d && c != d) {
						res += cnt[a][b]*cnt[c][d];
					}
				}
			}
		}
	}
	return res;
}

void clearcnt() {
	for (int i = 1 ; i <= 4 ; i++) {
		for (int j = 1 ; j <= 4 ; j++) {
			cnt[i][j] = 0;
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		init();
		int n; cin >> n;
		long long ans = 0;
		for (int i = 1 ; i <= n ; i++) {
			int u , v , c; cin >> u >> v >> c;
			color[u + 200][v + 200] = c;
		}
		for (int i = 0 ; i <= 400 ; i++) {
			for (int j = i + 1 ; j <= 400 ; j++) {
				clearcnt();
				for (int k = 0 ; k <= 400 ; k++) {
					if (color[i][k] && color[j][k]) cnt[color[i][k]][color[j][k]] ++;
				}
				ans += calc();
			}
		}
		cout << ans/2 << '\n';
	}
	return 0;
}