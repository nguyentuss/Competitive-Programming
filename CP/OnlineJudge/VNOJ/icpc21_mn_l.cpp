#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#define int long long

set<int> s1 , s2;
int n , m , a[MAX_N];
int sum = 0;

void add(int x , int i) {
	if (x % 2 == 0) s1.insert(i);	
	else s2.insert(i);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1 ; i <= n ; i ++) {
		cin >> a[i];	
		sum += a[i];
		add(a[i] , i);
	}
	string s; cin >> s;
	for (int i = 0 ; i < s.size() ; i++) {
		int tmp = 0;
		queue<set <int> :: iterator> q , q1;
		if (s[i] == '0') {
			auto it = s1.lower_bound(1);

			while (*it <= n) {
					if (it == s1.end() || *it > n) break;
					else {
						a[*it] /= 2;
						tmp += a[*it];
						if (a[*it] == 0) q1.push(it);
						else if (a[*it] % 2 != 0) q.push(it);
						it ++;
					}
			}
			while (!q.empty()) {
				auto x = q.front();
				s1.erase(x);
				s2.insert(*x);
				q.pop();
			}
		}
		else {
			auto it = s2.lower_bound(1);
			while (*it <= n) {
					if (it == s2.end() || *it > n) break;
					else {
						a[*it] --;
						tmp++;
						if (a[*it] == 0) q1.push(it);
						else if (a[*it] % 2 == 0) q.push(it);
						it ++;
					}
			}
			while (!q.empty()) {
				auto x = q.front();
				s2.erase(x);
				s1.insert(*x);
				q.pop();
			}
			while (!q1.empty()) {
				auto x = q1.front();
				s2.erase(x);
				q1.pop();
			}
		}
			
		sum -= tmp;
		cout << sum << '\n';
	}

	return 0;
}