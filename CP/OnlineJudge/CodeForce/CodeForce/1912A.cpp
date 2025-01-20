#include<bits/stdc++.h>
#define int long long


using namespace std;

signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	int x, k;

	cin >> x >> k;

	int res = x;

	vector<vector<int>> b(k);
	int cnt = 0;

	set<pair<int , int>> s;
	for (int i = 0 ; i < k ; i++) {
		int n;
		cin >> n;
		vector<int> a(n);

		for (int &u: a) {
			cin >> u;
		}
        int mn = 0;
        int sum = 0;
        vector<pair<int , int>> b;
		for (int i = 0 ; i < n ; i++) {
            sum += a[i];
            mn = min(mn , sum);
            if (sum >= 0) {
                s.insert({-mn , sum});
            }
        }
	}

	vector<int> ptr(k);


	for (int i = 0 ; i < k ; i++) {
		s.insert({-b[i][0], {i, 0}});
	}

	while (cnt--) {
		auto [u, id] = *s.begin();
		u = -u;
		s.erase(s.begin());
		x += b[id.first][id.second];
		if (x < 0) break;
		res = max(res, x);
		if (id.second + 1 < b[id.first].size()) {
			s.insert({-b[id.first][id.second+1], {id.first, id.second+1}});
		}
	}

	cout << res;
	return 0;
}