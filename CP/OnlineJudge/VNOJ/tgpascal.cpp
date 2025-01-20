#include <bits/stdc++.h>

using namespace std;

int n ; 

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	int num = __builtin_popcount(n);
	cout << (long long) (pow(2LL , num));
	return 0;
}