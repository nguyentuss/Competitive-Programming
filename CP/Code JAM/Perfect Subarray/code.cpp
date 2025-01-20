#include <bits/stdc++.h>

using namespace std;

int t , n , x;	
vector <int> v;
vector <int> sum((int) (1e5 + 7));
int counted[(int) (2*1e7 + 8)];
int mini , maxi;

void init() {
	v.clear();
	cin >> n;
	mini = INT_MAX;
	maxi = INT_MIN;
	for (int i = 0 ; i < n ; i++) {
		cin >> x;
		v.push_back(x);
	}
	sum[0] = 0;
	for (int i = 1 ; i <= n ; i++) {
		sum[i] = sum[i - 1] + v[i - 1];
		mini = min(mini , sum[i]);
		maxi = max(maxi , sum[i]);
	}
	return;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);

	cin >> t;
	for (int test = 1 ; test <= t ; test++) {
		init();
		long long ans = 0;
		memset(counted , 0 , sizeof(counted));
		counted[(int) 1e7] ++;
		maxi = max(maxi , 0);
		mini = min(mini , 0);

		for (int i = 1 ; i <= n ; i++) {
			//counted[(int) 1e7] ++;
			for (int x = 0 ; x <= (int) sqrt(maxi - mini) ; x ++) {
				if (sum[i] - x * x < (int) (-1e7)) break;
				ans += counted[sum[i] - x * x + (int) 1e7];
			}
			counted[sum[i] + (int) 1e7] ++;
		}
		cout << "Case #" << test << ": " << ans << '\n';
	}

	return 0;
}