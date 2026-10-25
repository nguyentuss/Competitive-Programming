#include <bits/stdc++.h>
using namespace std;
const long lm = 1e5+9;
long A[lm], n, m, k, test;
int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("cards.inp", "r", stdin);
	freopen("cards.out", "w", stdout);
	cin >> test;
	while (test--){
		cin >> m >> n >> k;
		priority_queue<long> pq;
		map<long, long> cnt;
		long cur = 1, cap = 0, ans = 0, resv = k-1;
		for (int i=1; i<=m; i++){
			cin >> A[i];
			if (cnt[A[i]] > 0) continue;
			cnt[A[i]] += 1;
			bool played = false;
			while (cnt[cur] > 0){
				played = true;
				cnt[cur] -= 1;
				ans += 1;
				cur += 1;
			}
			if (!played){
				while (cap >= k-1 && !pq.empty()){
					cap -= 1;
					cnt[pq.top()] -= 1;
					pq.pop();
				}
				cap+= 1;
				pq.push(A[i]);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}