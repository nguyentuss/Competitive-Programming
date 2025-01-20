#include <bits/stdc++.h>

using namespace std;

#define ii pair<int ,int>
#define f first
#define s second

vector<ii> v[21];
vector<int> ans(1<<20);

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("VDGQ.inp","r",stdin);
	freopen("VDQG.out","w",stdout);
	int n; cin >> n;
	for (int i = 0 ; i < (1 << n)  ; i ++) {
		int x; cin >> x;
		v[0].push_back(ii(x , i));
	}
	int cnt = 0;
	while (cnt <= n) {
		for (int i = 0 ; i < v[cnt].size() ; i+=2) {
			if (v[cnt][i].f >= v[cnt][i + 1].f) 
				v[cnt + 1].push_back(ii(v[cnt][i].f , v[cnt][i].s));
			else 
				v[cnt + 1].push_back(ii(v[cnt][i + 1].f , v[cnt][i + 1].s));
		}
		cnt++;
	}
	cnt = n - 1;
	while (n >= 0) {
		int j = 0;
		for (int i = 0 ; i < v[cnt].size() ; i+= 2) {
			auto a = v[cnt][i] , b = v[cnt][i + 1];
			if (a.f == b.f) {
				if (!ans[a.s]) ans[a.s] = (n - cnt - 1);
				if (!ans[b.s]) ans[b.s] = (n - cnt - 1); 
			}
			else if (a.f > b.f) {
				if (!ans[a.f]) ans[a.s] = (n - cnt - 1);
				if (!ans[b.s]) ans[b.s] = (n - cnt);
			}
			else {
				if (!ans[b.f]) ans[b.s] = (n - cnt - 1);
				if (!ans[a.f]) ans[a.s] = (n - cnt);
			}
		}
		cnt--;
	}
	for (int i = 0 ; i < (1 << n) ; i++) cout << ans[i] << " ";
	return 0;
}