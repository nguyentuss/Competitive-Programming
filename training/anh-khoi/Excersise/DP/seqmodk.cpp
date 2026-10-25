#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (500007)

int n, k;
vector <int> v(MAX_N);
vector <int> f(MAX_N);

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);

	cin >> n >> k;
	f[0] = 0;
	for (int i = 1 ; i <= n ; i++) {
		cin >> v[i];
		f[i] = f[i - 1] + v[i];
	}
	for (int i = 1 ; i <= n ; i++) {
		int l = 1 , r = i;
		while (l <= r) {
			int mid = (l + r)/2;
			if (f[i])
		}
	}

	return 0;
}