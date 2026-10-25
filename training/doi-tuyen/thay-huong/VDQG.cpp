#include <bits/stdc++.h>

using namespace std;

#define ii pair<int ,int>
#define f first
#define s second

vector<ii> v[22];
vector<int> ans((1<<20) + 7, -1);

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("VDQG.inp","r",stdin);
	//freopen("VDQG.out","w",stdout);
	int n; scanf("%d",&n);
	for (int i = 0 ; i < (1 << n) ; i ++) {
		int x; scanf("%d",&x);
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
	/*for (int i = 0 ; i <= n ; i++) {
		for (auto e : v[i]) cout << e.f << " ";
		cout << '\n';
	}*/
	cnt = n - 1;
	ans[v[n][0].s] = 0;
	while (cnt >= 0) {
		int j = 0;
		for (int i = 0 ; i < v[cnt].size() ; i+= 2) {
			auto a = v[cnt][i] , b = v[cnt][i + 1];
			if (a.f == b.f) {
				if (ans[a.s] == -1 && ans[b.s] != -1) ans[a.s] = ans[b.s];
				if (ans[b.s] == -1 && ans[a.s] != -1) ans[b.s] = ans[a.s]; 
			}
			else if (a.f > b.f) {
				if (ans[a.s] == -1) ans[a.s] = (n - cnt - 1);
				if (ans[b.s] == -1) ans[b.s] = (n - cnt);
			}
			else {
				if (ans[b.s] == -1) ans[b.s] = (n - cnt - 1);
				if (ans[a.s] == -1) ans[a.s] = (n - cnt);
			}
			j++;
		}
		cnt--;
	}
	for (int i = 0 ; i < (1 << n) ; i++) printf("%d ",ans[i]);
	return 0;
}