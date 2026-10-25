#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e4 + 7)
#define ii pair<int , int>
#define iii pair <ii , int>
#define s second 
#define f first
iii v[MAX_N];
int f[MAX_N];
int before[MAX_N];
int trace[MAX_N];

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("chonhd.inp","r",stdin);
	freopen("chonhd.out","w",stdout);
	int n , x , y ; cin >> n;
	for (int i = 1 ; i <= n ; i++){
		cin >> v[i].f.f >> v[i].f.s;
		v[i].s = i;
	}
	sort(v + 1 , v + 1 + n);
	for (int i = 1 ; i <= n ;i++) 
		f[i] = 1;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j < i ; j++) {
			if (v[i].f.f >= v[j].f.s && (f[j] + 1 > f[i])) {
				f[i] = f[j] + 1;
				before[i] = j;
				trace[i] = v[j].s;
			}
		}
	}
	int ans = -1 , tmp;
	for (int i = n ;i >= 1 ; i--){ 
		if (f[i] > ans) {
			ans = f[i];
			tmp = i;
		}
	}
	vector <int> tr;
	tr.push_back(v[tmp].s);
	while (tmp > 0) {
		if (trace[tmp] != 0) tr.push_back(trace[tmp]);
		tmp = before[tmp];
	}
	cout << tr.size() << '\n';
	reverse(tr.begin() , tr.end());
	for (auto e : tr) cout << e << " ";

	return 0;
}