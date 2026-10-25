#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (4e3 + 7)
#define ii pair<int , int>
#define f first
#define s second

int f[MAX_N][MAX_N];
int n , k;
ii v[MAX_N];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	for (int i = 1 ; i <= n ; i++) {
		cin >> v[i].first >> v[i].second;
	}
	f[1][0] = v[i].f;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 0 ; j <= k ; j++) {
			if (f[i][j] )
		}
	}
	return 0;
}