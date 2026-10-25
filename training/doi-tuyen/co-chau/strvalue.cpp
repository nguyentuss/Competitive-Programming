#include <bits/stdc++.h>

using namespace std;

string s;
int k;
int cnt[257];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("strvalue.inp","r",stdin);
	//freopen("strvalue.out","w",stdout);
	cin >> s >> k;
	for (int i = 0 ; i < s.size() ; i++) {
		cnt[(int) s[i]] ++;
	}
	priority_queue<int> pq;
	for (int i = 'a' ; i <= 'z' ; i++) {
		if (cnt[i] > 0) pq.push(cnt[i]);
	}
	for (int i = 1 ; i <= k ; i++) {
		int x = pq.top(); pq.pop();
		x = x - 1;
		pq.push(x);
	}
	long long ans = 0;
	while (pq.empty() == false) {
		long long x = pq.top();
		if (x > 0) {
			ans = ans + x*x;
		}
		pq.pop();
	}
	cout << ans;
	return 0;
}