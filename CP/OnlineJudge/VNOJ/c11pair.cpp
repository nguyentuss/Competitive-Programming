#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (5*1e5 + 7)
#define ii pair<int ,int>


int n ,x; 
vector <int> L(MAX_N);
vector <int> R(MAX_N);

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	//freopen("test.inp","r",stdin);
	//freopen("test.out","w",stdout);
	cin >> n;
	vector <int> v;
	v.push_back(-1);
	for (int i = 0 ; i < n ; i++) {
		cin >> x;
		v.push_back(x);
	}
	deque<ii> dq;
	long long ans = 0;
	for (int i = 1 ; i <= n; i++) {
		while (!dq.empty() && v[dq.front().first] < v[i]) {
			ans += dq.front().second;
			dq.pop_front();
		}
		if (!dq.empty()) {
			if (v[i] == v[dq.front().first]) {
				ans += dq.front().second++;
				if (dq.size() > 1) ans ++;	
			}
			else {
				ans ++;
				dq.push_front(ii(i , 1));
			}
		}
		else dq.push_front(ii(i , 1));
	}
	
	cout << ans;


	return 0;
}