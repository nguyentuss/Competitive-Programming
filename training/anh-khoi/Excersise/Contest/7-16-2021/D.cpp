#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);

	int n ; cin >> n;
	vector <int> v(1000);
	for (int i = 1 ; i <= n ; i++) {
		cin >> v[i];
	}
	int sum = v[1];
	for (int i = 2 ; i <= n; i ++){
		sum = v[i] - sum;
		cout << sum << " ";
	}
	cout << '\n';
	cout << sum;
	return 0;
}