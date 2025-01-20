#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , set<int>>
#define f first
#define s second
map<set<int> , bool> checked;
int n , m;
queue <set<int>> q;
set<int> myset[107];
set<int> s , v;

void init() {
	for (int i = 1 ; i <= n ;i++) {
		myset[i].clear();
	}
	checked.clear();
	return;
}

vector<set<int>> adj;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int t ;cin >> t;
	while (t--) {
		cin >> n >> m;
		init();
		for (int i = 1 ; i <= n ; i++) {
			int x; cin >> x;
			for (int j = 1 ; j <= x ; j++) {
				int tmp; cin >> tmp;
				myset[i].insert(tmp);
			}
			q.push(myset[i]);
		}
		int cnt = 0;
		while (!q.empty()) {
			s = q.front();
			q.pop();
			for (int i = 1 ; i <= n ; i ++) {
				v = s;
				for (auto e : myset[i]) {
					v.insert(e);
				}
				if (!checked[v]) {
					q.push(v);
					checked[v] = true;
					cnt ++;
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}