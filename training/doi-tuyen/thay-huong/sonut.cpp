#include <bits/stdc++.h>

using namespace std;

int recursion(int N) {
	if (N < 9) return N;
	else {
		return recursion(N / 10) + (N % 10);
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("sonut.inp","r",stdin);
	freopen("sonut.out","w",stdout);

	int n; cin >> n;

	while (n > 9) {
		n = recursion(n);
	}

	cout << n;

	return 0;
}