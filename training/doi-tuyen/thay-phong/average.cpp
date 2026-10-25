#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#define ll long long

double v[MAX_N] , a;
ll sum;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >>n;
	for (int i = 1; i <= n ; i++) {
		cin >> v[i];
		sum += v[i];
	}
	sort(v + 1 , v + 1 + n);
	for (int i = 2 ; i <= n ; i++) {
		a = (v[i - 1] + v[i])/2.0;
		v[i] = a;
	}
	cout << fixed << setprecision(5) << a * n - sum;
	return 0;
}