#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (3*1e5 + 7)
#define ll long long

int a[MAX_N];
ll fl[MAX_N] , fr[MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("seq3n.inp","r",stdin);
	//freopen("seq3n.out","w",stdout);
	int n; cin >> n;
	for (int i = 1 ; i <= 3*n ; i++) cin >> a[i];
	priority_queue<int , vector<int> , greater<int>> pq;
	ll sum = 0;
	for (int i = 1 ; i <= 3*n ; i++) {
		sum += a[i];
		pq.push(a[i]);
		if (pq.size() > n) {
			sum -= 1LL*pq.top();
			pq.pop();
		}
		fl[i] = sum;
	}	
	priority_queue<int> pr;
	sum = 0;
	for (int i = 3 *n ; i >= 1 ; i--) {
		sum += a[i];
		pr.push(a[i]);
		if (pr.size() > n) {
			sum -= 1LL*pr.top();
			pr.pop();
		}
		fr[i] = sum;
	}
	ll ans = LLONG_MIN;
	for (int i = n ; i <= 2 *n ; i++) {
		ans = max(ans , fl[i] - fr[i + 1]);
	}
	cout << ans;
	return 0;
}