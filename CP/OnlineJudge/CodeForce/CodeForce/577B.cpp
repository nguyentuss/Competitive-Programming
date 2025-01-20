#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e6 + 7)

bool f[MAX_N] , tmp[MAX_N];
int v[MAX_N] , n , m;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1 ; i <= n ;i++) {
		cin >> v[i];
	}
	for (int i = 1 ; i <= n ;i++) {
		if (f[0]) return (cout << "YES" , 0);
		memset(tmp , false , sizeof tmp);
		for (int j = 0 ; j <= m; j ++) {
			if (f[j]) {
				if (!f[(j + v[i])%m])
					tmp[(j + v[i])%m] = true;
			}
		}
		for (int j = 0 ; j <= m; j++) {
			if (tmp[j]) f[j] = true; 
		}
		f[v[i]%m] = true;
	}
	if (f[0]) return (cout << "YES" , 0);
	cout << "NO";
	return 0;
}