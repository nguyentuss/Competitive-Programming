#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)

int f1[MAX_N] , f2[MAX_N] , f3[MAX_N];
int a[MAX_N] , b[MAX_N] , c[MAX_N];
int n;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1 ; i <= n ;i++){
		cin >> a[i] >> b[i] >> c[i];
	}
	for (int i = 1 ; i <= n ;i++) {
		f1[i] = max(f1[i] , max(f2[i - 1] , f3[i - 1]) + a[i]);
		f2[i] = max(f2[i] , max(f1[i - 1] , f3[i - 1]) + b[i]);
		f3[i] = max(f3[i] , max(f1[i - 1] , f2[i - 1]) + c[i]);
	}

	cout << max(f1[n] , max(f2[n] , f3[n]));
	return 0;
}