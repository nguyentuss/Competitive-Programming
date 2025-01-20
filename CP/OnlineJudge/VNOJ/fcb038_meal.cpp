#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)

int a[MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
//	freopen("test.inp","r",stdin);
//	freopen("test.out","w",stdout);	
	int t; cin >> t;
	while (t--) {
		int n , k; cin >> n >> k;
		vector<int> pos[MAX_N];
		vector<int> v;
		for (int i = 1 ; i <= n ; i++) {
			cin >> a[i];
			if (pos[a[i]].size() == 0) {
				pos[a[i]].push_back(0);
				v.push_back(a[i]);
			}
			pos[a[i]].push_back(i);
		}
		int res = 0;
		for (auto num : v) {
			if (pos[num].size() == 1) continue;
			//cout << num << " " << pos[num].size() << '\n';
			int ans = 1;
			int l = 1 , len = 1 , tmp = 0;	
			for (int i = 2 ; i < pos[num].size() ; i++) {
				if (tmp + pos[num][i] - pos[num][i - 1] - 1 > k) { 
					res = max(res , len + k - tmp);		
				}
				tmp += pos[num][i] - pos[num][i - 1] - 1;
				len += pos[num][i] - pos[num][i - 1];
				while (l < i && tmp > k) {
					tmp = tmp - (pos[num][l + 1] - pos[num][l] - 1);
					len = len - (pos[num][l + 1] - pos[num][l]);
					l++;
				}
				if ((pos[num][l] - 1 - pos[num][l - 1]) > (k - tmp)) 
					ans = max(ans , len + k - tmp);
				else if ((pos[num][l] - 1 - pos[num][l - 1]) <= (k - tmp))
					ans = max(ans , len + pos[num][l] - 1 - pos[num][l - 1]);
			}
			if ((pos[num][l] - 1 - pos[num][l - 1]) > (k - tmp))
					tmp += k - tmp;
			else tmp += pos[num][l] - 1 - pos[num][l - 1];
			if (tmp <= k) {
				if ((k - tmp) <= (n - pos[num][pos[num].size() - 1])) 
					ans = ans + k - tmp;
				else ans = ans + n - pos[num][pos[num].size() - 1];
			}
			res = max(res , ans);
			//cout << num << " " << ans << '\n';
		}
		cout << res << '\n';
	}

	return 0;
}