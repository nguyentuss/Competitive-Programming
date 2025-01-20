#include <bits/stdc++.h>

using namespace std;

int n , m , x;
vector <int> v;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >>m;
	for (int i = 1 ; i <= n ; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin() , v.end());
	int ans = v[0] + v[1] + v[2];
	for (int i = 2 ; i < n ; i++) {
		int last = m - v[i];
		int j = i - 1 , k = 0;
		while (j > k) {
			while (j > k && v[j] + v[k] > last) j--;
			while (j > k && v[j] + v[k] <= last) {
				ans = max(ans , v[i] + v[j] + v[k]);
				k++;
			}
		}
	}
	cout << ans;
	return 0;
}