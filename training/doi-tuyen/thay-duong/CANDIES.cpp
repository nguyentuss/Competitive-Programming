#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)

string s;
int cnt[30];
vector<int> v;
int cntodd;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("candies.inp","r",stdin);
	freopen("candies.out","w",stdout);
	cin >> s;
	int n = s.size();
	s = '0' + s;
	for (int i = 1; i <= n ;i++) 
		cnt[s[i] - 'a'] ++;
	for (int i = 'a' ; i <= 'z' ; i++) {
		if (cnt[i - 'a'] % 2 == 0) 
			v.push_back(cnt[i - 'a']);
		else {
			cntodd++;
			v.push_back(cnt[i - 'a'] - 1);
		}
	}
	sort(v.begin() , v.end() , greater<int>());
	int t; cin >> t;
	while (t--) {
		int k; cin >> k;
		if (k > (s.size() - 1)) {
			cout << -1 << '\n';
			continue;
		}
		int total = 0;
		int found = false;
		for (auto x : v) {
			total += x;
			if (total >= k) {
				found = true;
				cout << k << '\n';
				break;
			}
		}
		if (!found) {
			if ((k - total) == 1 && cntodd >= 1) cout << k << '\n';
			else cout << -1;	
		}
	}
	return 0;
}