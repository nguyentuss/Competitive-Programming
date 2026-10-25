#include <bits/stdc++.h>
using namespace std;

#define MAX_N (int) (5e3 + 7)
#define MAX_K (int) (5e3 + 7)
	
int f[MAX_N][MAX_K	];
bool cnt[MAX_K];
int v[MAX_N];

int main() {
    freopen("cscong.inp","r",stdin);
    freopen("cscong.out","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int n; cin >> n;
	for (int i = 1 ; i <= n; i++) {
		cin >> v[i];
	}
	int ans = 0;
	for (int i = 1 ; i <= n; i++) {
		for (int k = 0 ; k <= v[i] ; k++) {
			if (cnt[v[i] - k]) f[v[i]][k] = f[v[i] - k][k] + 1;
			ans = max(ans , f[v[i]][k]);  
		}
		cnt[v[i]] = true;
	}
	cout << ans + 1;
	return 0;
}