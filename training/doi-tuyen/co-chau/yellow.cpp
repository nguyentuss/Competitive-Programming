#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
using namespace std;
int n, m;
int A[105], ans=0;

int main() {
	freopen("yellow.inp","r",stdin);
	freopen("yellow.out","w",stdout);
	cin >> m >> n;
	int k, t;
	for (int i = 1; i <= m; i++) {
		scanf("%d", &A[i]);
		if (A[i] > 1) {
			k = i;
			if (A[i] == 2) t = 1;
			else t = -1;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (k+t > m) t = -1;
		else if (k+t < 1) t = 1;
		k += t;
		if (A[k] == 0) ans += 1;
	}
	cout << ans;
	return 0;
}