#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (5e3 + 7) 
#define VAL (int) (1e8 + 7)
#define lim (int) (2e8)

int v[MAX_N];
int cnt[MAX_N];
map<int ,int> previ;
int ans[MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.inp","r",stdin);
	int n; cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		cin >> v[i];
		for (int j = 2 ; j * j <= abs(v[i]) ; j++) {
			while (v[i] % (j * j) == 0) v[i] /= (j *j);
		}
	}
	for (int i = 1 ; i <= n ;i++) {
		cnt[i] = previ[v[i]];
		previ[v[i]] = i; 
	}
	for (int i = 1 ; i <= n ; i ++) {
		int res = 0;
		for (int j = i ; j <= n ; j++) {
			if (v[j] && cnt[j] < i) res++;
			ans[max(1 , res)] ++;
		}
	}
	for (int i = 1 ; i <= n ; i++) cout << ans[i] << " ";
	return 0;
}