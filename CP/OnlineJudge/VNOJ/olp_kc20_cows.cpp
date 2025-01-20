#include <bits/stdc++.h>

using namespace std;

long long n , s;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> s;
	cout << (n*(n + 1))/2 - s;
	return 0;
}