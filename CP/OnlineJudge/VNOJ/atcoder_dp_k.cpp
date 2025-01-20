#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)

bool f[MAX_N];
int n , k , v[MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	for (int i = 1 ; i <= n ; i++) {
		cin >> v[i];
	}
	f[0] = false;
	for (int i = v[1] ; i <= k; i++) {
		for (int j = 1 ; j <= n ; j ++) {
			if (i - v[j] >= 0 && !f[i - v[j]]) 
				f[i] = true;
		}
	}
	if (f[k]) cout << "First";
	else cout << "Second";

	return 0;
}