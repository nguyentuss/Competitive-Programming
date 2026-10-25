#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e6 + 7)

int f[MAX_N];
int a[MAX_N];
int pos[MAX_N];
set<int> s;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	cout.tie(NULL);
	//freopen("dongho.inp","r",stdin);
	//freopen("dongho.out","w",stdout);
	freopen("test.inp","r",stdin);
	int n , m , k; cin >> n >> m >> k;
	for (int i = 1 ; i <= n ; i++) {
		cin >> a[i];
		s.insert(a[i]);
	}
	sort(a + 1 , a + 1 + n);
	for (int i = 1 ; i <= n ; i++) 
		pos[a[i]] = i;
	int ans = 0;
	for (int i = 1 ; i <= n ; i++) {
		auto it = s.lower_bound(a[i] - m + 1);
		int j = pos[*it];
		int remain = i - j + 1;
		cout << i << " " << remain << " " << *it << '\n';
		it = s.find(a[i]);
		while (remain >= k) {
			if (it == s.end()) break;
			else {
				s.erase(it);
				remain--;
				it--;
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}