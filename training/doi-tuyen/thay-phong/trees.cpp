#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)
#define int long long

int a[MAX_N];
int ans = 0;

int lis(vector<int> &a) {
    int res = 0;
    int n = a.size();
    vector<int> last(n, 1e9);
    vector<int> f(n);
    for (int i = 0; i < n; i++) {
        f[i] = lower_bound(last.begin(), last.begin() + res + 1, a[i]) - last.begin();
        res = max(res, f[i] + 1);
        last[f[i]] = min(last[f[i]] , a[i]);
    }
    return res;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int n , k; cin >> n >> k;
	for (int i = 1 ; i <= n ;i++) {
		cin >> a[i];
	}
	vector<int> tmp1;
	for (int i = 1 ; i <= (k - 1) ; i++) {
		if (a[i] < a[k]) {
			tmp1.push_back(a[i]);
		}
	}
	tmp1.push_back(a[k]);
	vector<int> tmp2;
	tmp2.push_back(a[k]);
	for (int i = k + 1 ; i <= n ; i++) {
		if (a[i] > a[k]) {
			tmp2.push_back(a[i]);
		}
	}
	cout << lis(tmp2) + lis(tmp1) - 1;

	return 0;
}