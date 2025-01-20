#include <bits/stdc++.h>

using namespace std;

// Do phuc tap : O(nlogn) 

int n , k , x; 
vector <int> v;
vector <int> dis;
void init() {
	v.clear();
	dis.clear();
}

bool check(int x) {
	int count = 0;
	for (int i = 0 ; i < (int) dis.size() ; i++) {
		if (dis[i] >= x) {
			count += dis[i] / x; /* cong don phan de chia*/
		}
		else break;
	}
	if (count > k) return false; /*khong thoa*/
	else return true; /*thoa*/
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);

	int t ;cin >> t;
	for (int test = 1 ; test <= t ; test ++) {
		init();
		cin >> n >> k;
		for (int i = 0 ; i < n ;i++) {
			cin >> x;
			v.push_back(x);
		}

		for (int i = 0 ; i < n - 1 ; i ++) 
			dis.push_back(v[i + 1] - v[i] - 1);
		// dis[i] = v[i + 1] - v[i] - 1
		sort(dis.begin() , dis.end());
		int l = 1 , r = dis[(int) dis.size() - 1];
		int ans = INT_MAX;
		reverse(dis.begin() , dis.end());
		// cnp [1 .. maximum(dis[i])] -> ans

		while (l <= r) {
			int mid = (l + r)/2;
			if (check(mid)) {
				r = mid - 1;
				ans = min(ans , mid);
			}
			else{
				l = mid + 1;
			}
		}
		// khong tim duoc kq //
		if (ans == INT_MAX) ans = 1;
		cout << "Case #" << test << ": " << ans << endl; 
	}
	return 0;
}