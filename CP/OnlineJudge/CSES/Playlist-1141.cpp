#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;

int main() {	
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL); 
	int n ;cin >> n;
	vector<int> a(n); 
	for (int i = 0 ; i < n ; i++) {
		cin >> a[i];
	}
	int l = 0;
	map<int , int> cnt;
	int ans = 0;
	for (int i = 0 ; i < n ; i++) {
		cnt[a[i]]++;
		while (l <= i && cnt[a[i]] >= 2) {
			cnt[a[l]]--; 
			l++;
		}
		ans = max(ans , i - l + 1);
	}
	cout << ans;
	return 0;
}