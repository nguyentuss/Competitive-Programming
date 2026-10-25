#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e7 + 7)
//#define int long long
#pragma GCC optimize("Ofast")

int f[MAX_N];
vector<int> v;
int n , A , B;

void eratosthenes() {
	for (int i = 2 ; i <= B ; i++) {
		f[i] = 1;
	}
	for (int i = 2 ; i + i <= B ; i++) {
		int j = i + i;
		while (j <= B) {
			f[j] += i;
			j += i;
		}
	}
}


signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("sohhao.inp","r",stdin);
	freopen("sohhao.out","w",stdout);
	cin >> A >> B;
	eratosthenes();
	long long ans = 0;
	for (int i = A ; i <= B ; i++) {
		ans += abs(i - f[i]); 
	}
	cout << ans;
	return 0;
}