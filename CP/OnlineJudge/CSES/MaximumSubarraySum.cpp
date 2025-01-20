#include <bits/stdc++.h>

using namespace std;

int n; 
vector<int> v;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0 ; i < n ;i++) {
		int x; cin >> x;
		v.push_back(x);
	}
	int sum = 0 , maxi = INT_MIN;
	for (int i = 0 ; i < n ;i++) {
		sum += v[i];
		maxi = max(maxi , sum);
		if (sum < 0) {
			maxi = max(maxi , sum - v[i]);
			sum = 0;
		}
	}
	cout << maxi;
	return 0;
}