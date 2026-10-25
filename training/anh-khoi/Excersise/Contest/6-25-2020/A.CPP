#include <bits/stdc++.h>

using namespace std;

struct ele {
	int m , id;
};

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int t , x; cin >> t;
	while (t--) {
		int n;
		cin >> n;
		ele max , minn;
		max.m = -1 , minn.m = 101;
		for (int i = 1 ; i <= n ; i++) {
			cin >> x;
			if (max.m < x) {
				max.m = x;
				max.id = i;
			}
			if (minn.m > x) {
				minn.m = x;
				minn.id = i;
			}
		}
		int ans = 1000;
		//cout << minn.id << " " << max.id << '\n';
		if (minn.id < max.id) {
			int x = minn.id , y = max.id;
			cout << min(x + n - y + 1 , min(n - x + 1, y)) << '\n';
		}
		else {
			int x = minn.id , y = max.id;
			cout << min(y + n - x + 1, min(n - y + 1 , x)) << '\n'; 
		}

	}
	return 0;
}