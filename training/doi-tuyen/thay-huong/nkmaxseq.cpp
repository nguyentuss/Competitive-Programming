#include <bits/stdc++.h>

using namespace std;

#define ii pair<int ,int>

int n , p;
vector <int> v(50005);
ii sum[50005];
int f[50005];

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> p;

	sum[0].first = 0;
	for (int i = 1 ; i <= n; i++) {
		cin >> v[i];
		sum[i].first = sum[i - 1].first + v[i];
		sum[i].second = i;
	}
	sort(sum + 1 , sum + 1 + n) ;
	f[1] = sum[1].second;
	int ans = -1;
	for (int i = 2 ; i <= n ; i++) {
		int l = 1 , r = i , pos = 0;
		while (l <= r) {
			int mid = (l + r)/2;
			if (sum[i].first - sum[mid].first >= p) {
				pos = mid;
				l = mid + 1;
			} 
			else r = mid - 1;
		}
		f[i] = min(f[i - 1] , sum[i - 1].second);
		if (f[pos + 1] <= sum[i].second && pos != 0)
			ans = max(ans , sum[i].second - f[pos + 1]);
	}
	cout << ans;


	return 0;
}