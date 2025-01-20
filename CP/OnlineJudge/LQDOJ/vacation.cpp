#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

int a,b,c,l[100007][4];


int main() {
	boost;
	int n; cin >> n;
	l[0][1] = 0; ;l[0][2] = 0; l[0][3] = 0;
	for (int i = 1 ; i <= n ; i++) {
		cin >> a >> b >> c;
		l[i][1] = max(l[i-1][2],l[i-1][3]) + a;
		l[i][2] = max(l[i-1][1],l[i-1][3]) + b;
		l[i][3] = max(l[i-1][1],l[i-1][2]) + c;
	}

	cout << max(l[n][1],max(l[n][2],l[n][3]));

	return 0;
}