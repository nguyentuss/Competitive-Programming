#include <bits/stdc++.h>

using namespace std;

vector <int> v;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	int n , k; cin >> n >> k;
	for (int i = 0 ; i < n ; i ++) {
		int x; cin >> x;
		v.push_back(x);
	}
	int l = 1 , r = n , ans;
	while (l <= r) {
		int mid = (l + r)/2;
		vector <int> tmp(n);
		int sum = 0;
		for (int i = 0 ; i < n ; i++) {
			if (v[i] >= mid) sum ++;
			else sum --;	
			tmp[i] = sum;
		}
		int mini = 0;
		bool check = false;
		for (int i = k - 1 ; i < n ; i ++) {
			if (tmp[i] - mini > 0) {
				check = true;
				break;
			}
			mini = min(mini , tmp[i - k + 1]);
		}
		if (check) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << ans; 

	return 0;
}