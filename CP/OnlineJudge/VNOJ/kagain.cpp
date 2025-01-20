#include <bits/stdc++.h>

using namespace std;

deque <int> dq;
vector <int> v;
int n , x;
int L[30007] , R[30007];

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);

	int t; cin >> t;
	for (int test = 0 ; test < t ; test ++) {
		v.clear();
		for (int i = 1 ; i <= n ; i++) {
			L[i] = 0;
			R[i] = 0;
		}
		while ((int) dq.size()) dq.pop_front();
		v.push_back(-1);
		cin >> n;
		for (int i = 1 ; i <= n; i++) {
			cin >> x;
			v.push_back(x);
		}
		v.push_back(-1);
		dq.push_back(0);
		for (int i = 1 ; i <= n; i++) {
			while (dq.size() && v[dq.back()] >= v[i]) dq.pop_back();
			L[i] = dq.back() + 1;
			dq.push_back(i);
		}
		while ((int) dq.size()) dq.pop_back();
		dq.push_back(n + 1);
		for (int i = n ; i >= 1 ; i --) {
			while (dq.size() && v[dq.back()] >= v[i]) dq.pop_back();
			R[i] = dq.back() - 1;
			dq.push_back(i);
		}
		//cout << L[3] << " " << R[3] << '\n';
		int ans = -1 , l , r;
		for (int i = 1 ; i <= n; i++) {
			if (ans < v[i]*(R[i] - L[i] + 1)){ 
				ans = v[i]*(R[i] - L[i] + 1);
				l = L[i];
				r = R[i];
			}
		}
		cout << ans << " " << l << " " << r << '\n';
	}

	return 0;
}